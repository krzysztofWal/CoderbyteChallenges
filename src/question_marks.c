/*
Question marks
#hashmap #tree #search #string manipulation 

Have the function QuestionsMarks(str) take the str string parameter, which will contain
single digit numbers, letters, and question marks, and check if there are exactly
3 question marks between every pair of two numbers that add up to 10. If so, then
your program should return the string true, otherwise it should return the string
false. If there aren't any two numbers that add up to 10 in the string, then your
program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true
because there are exactly 3 question marks between 6 and 4, and 3 question marks
between 5 and 5 at the end of the string. 

Optimal: o(n), achieved: o(n)
*/

#include <stdio.h> 
#include <string.h>

#define IF_DEBUG 0

void QuestionsMarks(char * str) {
  // code goes here 
  int positions[strlen(str)];
  int cnt = 0; int q_cnt = 0; int t_cnt = 0;
  
  for (int i=0; i<strlen(str);i++) {
    if ((int)(str[i])>47 && (int)(str[i])<58){
      positions[cnt++]=i;
      if (cnt>1 && (int)(str[positions[cnt-2]]) + (int)(str[positions[cnt-1]]) == 106) {
        // sum of the neighbouring numerals is equal to 10
        // check if between them are exactly three question marks
        for (int j=positions[cnt-2]+1;j<positions[cnt-1];j++) {if (str[j] == 63) {q_cnt++;}}
          if (IF_DEBUG) {
            printf("position %i and %i are  equal 10\n",positions[cnt-2],positions[cnt-1]);
            printf("Between %i and %i are %i question marks\n",positions[cnt-2],positions[cnt-1],q_cnt);
          }
        if (q_cnt!=3) {printf("false"); return;}
        q_cnt = 0;
        t_cnt++;
      }
    }
  }
  if (t_cnt==0) {printf("false");} else {printf("true");}

  if (IF_DEBUG) {
    printf("\nt_cnt = %i\n",t_cnt);
    for (int i=0;i<cnt;i++){printf("\\%i ", positions[i]);}
    for (int i=0;i<cnt;i++){printf("%c ", str[positions[i]]);}
  }

  #ifdef CMAKE_CODERBYTE_SOLUTIONS_BUILD
      free(str);
  #endif // CMAKE_CODERBYTE_SOLUTIONS_BUILD

}

int main(void) { 
  // keep this function call here
  QuestionsMarks(coderbyteInternalStdinFunction(stdin));
  return 0;
}