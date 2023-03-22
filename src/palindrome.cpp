/*
Palindrome
#recursion #string manipulation 

Have the function Palindrome(str) take the str parameter being passed and return
the string true if the parameter is a palindrome, (the string is the same forward
as it is backward) otherwise return the string false. For example: "racecar" is also
"racecar" backwards. Punctuation and numbers will not be part of the string. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string Palindrome(std::string str) {
  // code goes here
  size_t j{str.length()-1};
  size_t i{0};
  bool spaceEnd{};

  // if no spaces before the word
  for (;i<str.length();i++){
    while (str.at(i) == ' ') {
      if(++i==str.length()) {
        i--;
        spaceEnd = true;
        break;
      }
    }
    while (str.at(j) == ' ') {j--;}
    //std::cout << str.at(i) << " " << str.at(j) << "\n";
    if (str.at(i) != str.at(j) && !spaceEnd) {
      return "false";
    }
    if(j>=1) {j--;};
  }
  return "true";
}

int main(void) { 
  // keep this function call here
  std::cout << Palindrome(coderbyteInternalStdinFunction(stdin));
  return 0;
}