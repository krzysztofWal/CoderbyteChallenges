/*
Simple Symbols

Have the function SimpleSymbols(str) take the str parameter being passed and determine
if it is an acceptable sequence by either returning the string true or false. The
str parameter will be composed of + and = symbols with several characters between
them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded
by a + symbol. So the string to the left would be false. The string will not be empty
and will have at least one letter. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string SimpleSymbols(std::string str) {
  
  // code goes here
  if (isalpha(str.at(0)) || isalpha(str.at(str.length()-1))) { return "false";}

  for (size_t i{1}; i<str.length()-1; i++) {
    if(isalpha(str.at(i)) && (str.at(i+1)!='+' || str.at(i-1)!='+')) {
      return "false";
    }
  }
  return "true";
}

int main(void) { 
  // keep this function call here
  std::cout << SimpleSymbols(coderbyteInternalStdinFunction(stdin));
  return 0;
}