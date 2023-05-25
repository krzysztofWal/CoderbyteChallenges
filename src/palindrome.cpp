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


/*I am commenting this a bit after i wrote this
 and I must admit, I had rather interesting attitude here.
 More reasonable solution below this piece of code.
  */
// std::string Palindrome(std::string str) {
//   // code goes here
//   size_t j{str.length()-1};
//   size_t i{0};
//   bool spaceEnd{};
//
//   // if no spaces before the word
//   for (;i<str.length();i++){
//     while (str.at(i) == ' ') {
//       if(++i==str.length()) {
//         i--;
//         spaceEnd = true;
//         break;
//       }
//     }
//     while (str.at(j) == ' ') {j--;}
//     //std::cout << str.at(i) << " " << str.at(j) << "\n";
//     if (str.at(i) != str.at(j) && !spaceEnd) {
//       return "false";
//     }
//     if(j>=1) {j--;};
//   }
//   return "true";
// }

/* Or perhaps like this: */
std::string Palindrome(std::string str) {
  
  // 'remove' trailing and leading spaces
  // set start and end index
  size_t start_ind{ 0 };
  size_t end_ind{ str.length() - 1 };
  
  while (str.at(start_ind) == ' ') {
    start_ind++;
  }

  while (str.at(end_ind) == ' ') {
    end_ind--;
  }

  size_t word_length{end_ind - start_ind + 1};
  
  // if word's length is even -> 2*n than you should check
  // from start_ind to start_ind + word_length/2 (excluding)
  // if it is odd -> 2*n + 1 than divide it will be n + 0.5 which 
  // cast into int makes n, so the same number as in even case,
  // there is no need to check te next character as it will not have 
  // a pair - it will be the middle one
  for (size_t j{ 0 }; j < static_cast<int>(word_length/2); j++) {
    // std::cout <<  j + start_ind << " " << str.at(j + start_ind) << " " << str.at(end_ind - j) << std::endl;
    if (str.at(j + start_ind) != str.at(end_ind - j)) {
      return "false";
    }
  }

  return "true";
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests

int main(void) { 
  // keep this function call here
  std::cout << Palindrome(coderbyteInternalStdinFunction(stdin));
  // std::cout << Palindrome("   kajak  ");
  return 0;
}

#endif