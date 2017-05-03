This assignment has three sections. 

Part I. (20 points)

After compiling, run cpStrBug.c. Unfortunately, there is a problem with the code which result in segmentation fault.  Modify the code, so that the string copy method which we have developed will work without segmentation fault. You should not modify the string copy method. Also, you are not allowed to use arrays to fix the problem. 


Part II. (20 points)

There are four functions in  struct.c that you have to complete.  Make sure the program produces the correct and meaningful output after your modifications.

 
Part III. (30 points)

Write a program as follows. 


Define a pointer to character, named cp. Next, use malloc() to allocate enough memory to hold 26 characters (For this, you should assign the return value of malloc() to cp). Assign english alphabets ‘a’ to ‘z’ (lowercase) as characters to the allocated space. Next, print the content of those memory location to show those alphabets. Next, use free() to free the allocated memory. 


In the same program, use the same operations, i.e., applying malloc() and free() on cp, but this time by allocating 10 bytes to hold characters ‘0’ to ‘9’.


Note: do not forget to include <stdlib.h> 
