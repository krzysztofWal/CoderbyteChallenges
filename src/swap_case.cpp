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

const size_t bigA = 65;
const size_t smalla = 97;
const size_t smallz = 122;
const size_t bigZ = 90;
const size_t shift = 32;

// affects only letters
std::string SwapCase(std::string str) {
  for (auto i{0};i<str.length(); i++){
    if ( str.at(i) <= bigZ && str.at(i) >= bigA) { str.at(i)+=shift; } 
      else if (str.at(i) <= smallz && str.at(i) >= smalla) { str.at(i)-=shift; }
  }
  return str;
}

int main(void) { 
  // keep this function call here
  std::cout << SwapCase(coderbyteInternalStdinFunction(stdin));
  return 0;
}