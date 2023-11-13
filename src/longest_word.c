/*
Longest Word
#tree #search #string manipulation 

Have the function LongestWord(sen) take the sen parameter being passed and return
the longest word in the string. If there are two or more words that are the same
length, return the first word from the string with that length. Ignore punctuation
and assume sen will not be empty. Words may also contain numbers, for example 
"Hello world123 567" 

Optimal: o(n), achieved: o(n)
*/

#include <stdio.h> 
#include <string.h>

void LongestWord(char * sen) {
  // code goes here  
  unsigned long iter = 0;
  unsigned long counter = 0;

  int s = 0;
  int s_p = 0;
  unsigned long dumb_characters = 0;
  unsigned long length = strlen(sen);

  unsigned long longest = 0;
  unsigned long position_start_buff= 0;
  unsigned long position_end_buff = 0;
  unsigned long position_start = 0;
  unsigned long position_end = 0;

  // get array copy without characters taken into account
  char copy_arr[length];

  for (iter = 0; iter < length; iter++) {
    s = (int)(*(sen+iter));
    if ( (s<48 || (s>57 && s<65) || (s>90 && s<97) || s>122) && s!=32 ) {
      // not a space or an alphanumeric value
      dumb_characters++;
      *(copy_arr+strlen(sen)-dumb_characters) = (char)(' ');
    } else {
      *(copy_arr+counter) = (char)s;
      counter++;
    }
  }

  // reset the counter, now it counts the length of a word;
  counter = 0;
  iter = 0;
  position_end = length-dumb_characters-1;

  while (iter <= length - dumb_characters) {
    s = (int)*(copy_arr+iter);
    if (iter>0) {
        s_p = (int)*(copy_arr+iter-1);
        if ((s==32 && s_p!=32) || (s!=32 && iter==length-dumb_characters)) {
            // word ends
            position_end_buff = iter-1;
            if (counter>longest){
                longest = counter;
                position_start = position_start_buff;
                position_end = position_end_buff;
            }
        } else if (s!=32 && s_p==32) {
            // new word starts
            position_start_buff = iter;
            counter = 1;
        } else if (s!=32 && s_p!=32) {
            // still not space (word still lasts)
            counter++;
        } 
    } else if (iter==0 && s!=32) {
        counter++;
    }

    iter++;
  }

  for (iter=position_start;iter<=position_end;iter++){
    putchar((int)*(copy_arr+iter));
  }

  #ifdef CMAKE_CODERBYTE_SOLUTIONS_BUILD
      free(sen);
  #endif // CMAKE_CODERBYTE_SOLUTIONS_BUILD

}

int main(void) { 
  // keep this function call here
  LongestWord(coderbyteInternalStdinFunction(stdin));
  return 0;
}
