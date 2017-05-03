#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

struct LinkedList {
	char gram[100];
	int count;
	struct LinkedList * next;
};


struct Word {
	char chars[100];
	int size;
};

void put_into_sorted(struct LinkedList * current_node, struct LinkedList ** sorted, int size) {
	int i = 0;
	struct LinkedList * temp;
	sorted[size] = current_node;

	if (size != 0) {
		while (i != size && (*sorted[size-i]).count < (*sorted[size-i-1]).count) {
			temp = sorted[size-i];
			sorted[size-i] = sorted[size-i-1];
			sorted[size-i-1] = temp;
			i++;
		}
	}

}

char * coallese(char * word1, char * word2, char * word3) {
	int sum = 0;
	int i = 0;
	char * sumword = (char *) malloc(300);

	while (word1[i] != '\0') {
		sumword[sum] = word1[i];
		i++;
		sum++;
	}
	sumword[sum] = ' ';
	sum++;
	i=0;

	while (word2[i] != '\0') {
		sumword[sum] = word2[i];
		i++;
		sum++;
	}
	sumword[sum] = ' ';
	sum++;
	i=0;

	while (word3[i] != '\0') {
		sumword[sum] = word3[i];
		i++;
		sum++;
	}
	sumword[sum] = '\0';


	return sumword;
}


struct Word * find_word(FILE * bookpointer) {
	int word_found = 0;
	struct Word  * word = malloc(sizeof(struct Word));
	struct Word a = {.size = -1};
	(*word) = a;
	char c;
	int i = 0;

	while ( !(word_found) && (c = getc(bookpointer)) != EOF) {
		if  ((c >= 65 && c <= 90)  || (c >= 97 && c <= 122)) {
			word_found = 1;
			//if uppercase, make lowercase
			if (c >= 65 && c <= 90) {
				c += 32;
			}

			if (c >= 97 && c <= 122) {
				(*word).chars[i] = c;
				i++;
				(*word).size += c;
				c= getc(bookpointer);

				while ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)  || (c == 39) && c != EOF ) {
					if (c >= 65 && c <= 90) {
						c += 32;
					}

					(*word).chars[i] = c;
					i++;
					(*word).size += c;
					c = getc(bookpointer);
				}

				(*word).chars[i] = '\0';
			}
		}
	}

	return word;
}



void main() {

	struct LinkedList * storage[100000];
	struct LinkedList * sorted[750000];
	struct LinkedList * current_node;
	struct LinkedList * next_node;
	struct LinkedList a = { .count = 0, .next = 0};

	int size;
	struct Word word1;
	struct Word word2;
	struct Word word3;
	char * sumword;

	char * book;
	char c;
	int i = 0;
	FILE * bookpointer;
	int sum;


	// stat.h is something I found online that helps find a file's size
	struct stat st;
	i = stat("book.txt", &st);
	size = st.st_size;


	//populate linked list storage with init values
	for (int i = 0; i < 99999; i++) {
		storage[i] = malloc(sizeof(struct LinkedList));
		(*storage[i]) = a;
	}
	i = 0;


	bookpointer = fopen("book.txt", "r");

	//find initial words
	word1 = *find_word(bookpointer);
	word2 = *find_word(bookpointer);
	word3 = *find_word(bookpointer);

	while (word3.size > 0) {
		sumword = coallese(word1.chars, word2.chars, word3.chars);
		current_node = storage[(word1.size + word2.size + word3.size) % 499999];
			//add to hash!
		while (1) {
			if (strcmp((*current_node).gram, sumword) == 0) {
				(*current_node).count += 1;
				break;
			}
			else {
				if ((*current_node).count == 0) {
					//initial node
					strcpy((*current_node).gram, sumword);
				}
				else if ((*current_node).next == 0) {
					next_node = malloc(sizeof(struct LinkedList));
					*next_node = a;
					(*current_node).next = next_node; 
					current_node = next_node;
				} else {
					current_node = (*current_node).next;
				}
			}
		}

		word1 = word2;
		word2 = word3;
		word3 = *find_word(bookpointer);
	}

	//sort
	size = 0;
	for (int i = 0; i < 99999; i++) {
		current_node = storage[i];
		while (1) {
			if ((*current_node).count > 1) {
				put_into_sorted(current_node, sorted, size);
				size++;
			}
			if ((*current_node).next != 0) {
				current_node = (*current_node).next;
			}
			else {
				break;
			}
		}
	}

	for (i = 0; i < size; i++) {
		printf("%s %d   ", (*sorted[i]).gram, (*sorted[i]).count);
	}

}