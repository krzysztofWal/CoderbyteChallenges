/*
First Reverse
#tree #string manipulation 

Have the function FirstReverse(str) take the str parameter being passed and return
the string in reversed order. For example: if the input string is "Hello World and
Coders" then your program should return the string sredoC dna dlroW olleH. 

Optimal: o(n), achieved: o(n)
*/

#include <stdio.h> 
#include <string.h>

void FirstReverse(char * str) {
  // printf("%lu\n",sizeof(str));
  // printf("%lu\n",sizeof(char*)); // They both return the same because how could they not?

  // code goes here
  for (unsigned long i = strlen(str)-1; i>0 ;i--) {
    printf("%c",*(str+i));
  }
  printf("%c",*str);

  #ifdef CMAKE_CODERBYTE_SOLUTIONS_BUILD
    free(str);
  #endif // CMAKE_CODERBYTE_SOLUTIONS_BUILD

}

int main(void) { 
  // keep this function call here
  char * str = coderbyteInternalStdinFunction(stdin);
  FirstReverse(str);
  return 0;
}