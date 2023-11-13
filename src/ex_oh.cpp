/*
Ex Oh
#search #string manipulation 

Have the function ExOh(str) take the str parameter being passed and return the string
true if there is an equal number of x's and o's, otherwise return the string false.
Only these two letters will be entered in the string, no punctuation or numbers.
For example: if str is "xooxxxxooxo" then the output should return false because
there are 6 x's and 5 o's. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>
std::string ExOh(std::string str) {
  // code goes here 
  size_t x_cnt{};
  size_t o_cnt{};
  std::for_each(str.begin(),str.end(),
    [&](const char &c){if(c=='x'){x_cnt++;} else {o_cnt++;}});
  if (x_cnt == o_cnt) {return "true";}
  return "false";
}

int main(void) { 
  // keep this function call here
  std::cout << ExOh(coderbyteInternalStdinFunction(stdin));
  return 0;
}