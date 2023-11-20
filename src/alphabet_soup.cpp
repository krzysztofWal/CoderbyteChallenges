/*
Alphabet Soup
#sort #string manipulation 

Have the function AlphabetSoup(str) take the str string parameter being passed and
return the string with the letters in alphabetical order (ie. hello becomes ehllo).
Assume numbers and punctuation symbols will not be included in the string. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string AlphabetSoup(std::string str) {
  // code goes here 
  
  std::sort(str.begin(), str.end(), [](char a, char b){

    // HeLloHellOhello - >OooLlllllHHheee
    char lower_a = std::tolower(a);
    char lower_b = std::tolower(b);

    if (lower_a == lower_b) {
      // if lower are the same return the smaller number (capital letter that is)
      return a < b;
    } else {
      // if the letters are different
      return lower_a > lower_b;
    }
  });
  
  return str;
}

int main(void) { 
  // keep this function call here
  std::cout << AlphabetSoup(coderbyteInternalStdinFunction(stdin));
  return 0;
}