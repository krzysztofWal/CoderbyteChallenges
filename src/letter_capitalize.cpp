/*
Letter Capitalize
#string manipulation 

Have the function LetterCapitalize(str) take the str parameter being passed and capitalize
the first letter of each word. Words will be separated by only one space. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
std::string LetterCapitalize(std::string str) {
  size_t pos{str.find(" ")};
  str.at(0) = toupper(str.at(0));
  while (pos != std::string::npos && pos+1<str.length()) {
      str.at(pos+1) = toupper(str.at(pos+1));
      pos = str.find(" ", pos+1);
  }
  return str;
}

int main(void) { 
  // keep this function call here
  std::cout << LetterCapitalize(coderbyteInternalStdinFunction(stdin));
  return 0;
}
