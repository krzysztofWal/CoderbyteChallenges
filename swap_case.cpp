/*
Swap Case
#string manipulation 

Have the function SwapCase(str) take the str parameter and swap the case of each
character. For example: if str is "Hello World" the output should be hELLO wORLD.
Let numbers and symbols stay the way they are. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using std::string;
using std::cout;

string SwapCase(string str) {
  for (auto i{0};i<str.length(); i++){
    if (str.at(i)<=90 && str.at(i)>=65) {str.at(i)+=32;} 
      else if (str.at(i)<=122 && str.at(i)>=97) {str.at(i)-=32;}
  }
  return str;
}

int main(void) { 
  // keep this function call here
  cout << SwapCase(coderbyteInternalStdinFunction(stdin));
  return 0;
}