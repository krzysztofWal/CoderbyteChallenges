/*
First Reverse

Have the function FirstReverse(str) take the str parameter being passed and return
the string in reversed order. For example: if the input string is "Hello World and
Coders" then your program should return the string sredoC dna dlroW olleH. 

Optimal: o(n), achieved: o(n)
*/

#include <stdio.h> 
#include <string.h>

void FirstReverse(char * str) {
  // code goes here  
  for (unsigned long i = strlen(str)-1; i>0 ;i--) {
    printf("%c",*(str+i));
  }
  printf("%c",*str);
}

int main(void) { 
  // keep this function call here
  char * str = "Test string";
  FirstReverse(str);
  return 0;
}