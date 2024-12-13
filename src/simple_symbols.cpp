/*
Simple Symbols
#regex #string manipulation 

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
#define SAY_YES_TO_REGEX 
// #define PRINT_SIMPLE_SYMBOLS

#ifndef SAY_YES_TO_REGEX
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
#else
#include <regex>

/* This one not tested very thoughrougly, and given what I've read about implementation of regexes in standard libray
it is probably slower than the solution above xD */
std::string SimpleSymbols(std::string str) {

  std::regex reg, reg2;
  std::string tmp;
  const char toReplace[] = "*";

  try {
    /* because standard library regex are a funny thing you cannot use lookaheads and lookbacks */
    reg = std::regex(R"((?:(\+[a-z]){1,}\+))", std::regex_constants::icase);
    reg2 = std::regex("[a-z]", std::regex_constants::icase);
  } catch (std::regex_error &e) {
    std::cerr << "\tError: " << e.what() << ", code: " << e.code() << std::endl; 
    throw std::runtime_error("Oopsie daisy!");
  }
  /* remove single letters surrounded by '+' */
  std::regex_replace(std::back_inserter(tmp), str.cbegin(), str.cend(),reg , toReplace);

  #ifdef PRINT_SIMPLE_SYMBOLS
    std::cout << "SimpleSymbols(): " << tmp << std::endl;
  #endif

  /* if there are any left now, return false */
  if (std::regex_search(tmp, reg2)) {
    return "false";
  } else {
    return "true";
  }
  
}
#endif

int main(void) { 
  // keep this function call here
  std::cout << SimpleSymbols(coderbyteInternalStdinFunction(stdin));
  return 0;
}