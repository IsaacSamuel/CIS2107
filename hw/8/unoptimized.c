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

void sort(struct LinkedList ** sorted, int size) {
	struct LinkedList * temp;
	struct LinkedList * current_node;
	struct LinkedList * next_node;
	int changed = 1;
	int k = 0;

	//bubble sort
	while (changed == 1) {
		changed = 0;
		for (int i = 0; i < size-1-k; i++) {
			current_node = sorted[i];
			next_node = sorted[i+1];
			if ((*current_node).count < (*next_node).count ) {
				changed = 1;
				temp = sorted[i];
				sorted[i] = sorted[i+1];
				sorted[i+1] = temp;
			}
		}
		k++;
	}
}

void put_into_array(struct LinkedList ** storage, struct LinkedList ** to_sort) {
	//Takes all elements from the hash table and puts them into an array
	struct LinkedList * current_node;
	int j = 0;

	for (int i = 0; i < 511; i++) {
		current_node = storage[i];
		while (1) {
			if ((*current_node).count > 1) {
				//Put into array
				to_sort[j] = current_node;
				j++;
			}
			if ((*current_node).next != 0) {
				current_node = (*current_node).next;
			}
			else {
				break;
			}
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

	struct LinkedList * storage[511];
	struct LinkedList ** for_sorting;
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
	for (int i = 0; i < 511; i++) {
		storage[i] = malloc(sizeof( struct LinkedList));
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
		current_node = storage[(word1.size + word2.size + word3.size) % 511];
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

	//count the size
	size = 0;
	for (int i = 0; i < 511; i++) {
		current_node = storage[i];
		while (1) {
			if ((*current_node).count > 1) {
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

	printf("%d\n", size);
	
	for_sorting = (struct LinkedList *) malloc(sizeof(struct LinkedList *) * size);

	put_into_array(storage, for_sorting);
	sort(for_sorting, size);

	for (int i = 0; i < size; i++) {
		printf("%s %d   ", (*for_sorting[i]).gram, (*for_sorting[i]).count);
	}
}