#include <stdio.h> 
#include <stdlib.h>




void copyStr (char *s, char*t) 
{


  while ((*s++ = *t++)!= '\0') 
     ;  
   

}   



void main(){
    
  char *t = "12345";
  char *s;

  s = (char*) malloc(sizeof(char)*6);
   
  copyStr(s,t); 

  printf("string is %s\n",s); 
   
 
}
