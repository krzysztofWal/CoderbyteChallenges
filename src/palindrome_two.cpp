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

/* omits non alphanumerics */
std::string PalindromeTwo(std::string str) {
  //code goes here
  // two indexes running from left to right and right to left
  size_t i{ 0 };
  size_t j{ str.length() - 1 };

  bool foundNextAlphanum{true};

  // while both indexes are in bounds
  while ( (j >= 0 && i <= str.length() - 1) && (i >= 0 && j <= str.length() - 1) ) {
   
    // until both indexes are  alphanumeric
    while ( !isalpha_m(str.at(i)) && i < str.length() - 1) {
      i++;
      if( i == str.length() - 1 ) { foundNextAlphanum = false; }
    }
    while ( !isalpha_m(str.at(j)) && j > 0 ) {
      j--;
      if( j == 0 ) { foundNextAlphanum = false; }
    }

    // check corresponding alphanumerical characters
    // if foundNextAlphanum is false, that means that one of the indexes
    // when increasing or decreasing (in case of i or j accordingly) did not
    // found the next alphanumerical value to compare with and reached the end 
    // of the string
    if (foundNextAlphanum && tolower(str.at(i)) != tolower(str.at(j))) { 
      return "false";
    }
    i++; 
    j--;
  }
  return "true";
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG 
int main(void) { 
  // keep this function call here
  // std::cout << PalindromeTwo(coderbyteInternalStdinFunction(stdin));
  std::cout << PalindromeTwo("!Al!lets!Della!call!Ed!\"Stella\".");
  return 0;
}
#endif