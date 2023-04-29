/*
Palindrome Two
#search #string manipulation 

Have the function PalindromeTwo(str) take the str parameter being passed and return
the string true if the parameter is a palindrome, (the string is the same forward
as it is backward) otherwise return the string false. The parameter entered may have
punctuation and symbols but they should not affect whether the string is in fact
a palindrome. For example: "Anne, I vote more cars race Rome-to-Vienna" should return
true. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cctype>

bool isalpha_m(char c) {
    return static_cast<bool>(std::isalpha(static_cast<unsigned char>(c)));
}

std::string PalindromeTwo(std::string str) {
  //code goes here
  unsigned long long i{ 0 };
  unsigned long long j{ str.length() - 1 };
  bool con_end{}; 
  bool con_beg{};
  while (j >= 0 && i <= str.length() - 1 && i >= 0 && j <= str.length() - 1) {
    while (!isalpha_m(str.at(i)) || !isalpha_m(str.at(j))) {
        if (!isalpha_m(str.at(i))) {if (++i == str.length()) {i--; con_end = true;}}
        if (!isalpha_m(str.at(j))) {if (--j == -1) {j++; con_beg = true;}}
        if (con_beg && con_end) {break;}
    }
    if (!con_beg && !con_end &&tolower(str.at(i)) != tolower(str.at(j))) { return "false";}
    i++; j--;
  }
  return "true";
}

int main(void) { 
  // keep this function call here
  std::cout << PalindromeTwo(coderbyteInternalStdinFunction(stdin));
  return 0;
}