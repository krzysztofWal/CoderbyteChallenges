/*
Vowel Count
#regex #search #string manipulation 

Have the function VowelCount(str) take the str string parameter being passed and
return the number of vowels the string contains (ie. "All cows eat grass and moo"
would return 8). Do not count y as a vowel for this challenge. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>

#define SAY_YES_TO_REGEX

#ifndef SAY_YES_TO_REGEX
#include <set>


int VowelCount(const std::string &str) {  
  // code goes here 
  int cnt{};
  std::set<char> vowSet = {'a','e','i','o','u'};
  std::for_each(str.begin(),str.end(),
    [&](char c){if(vowSet.find(c)!=vowSet.end()) {cnt++;} });
  return cnt;
}
#else
#include <regex>

int VowelCount(const std::string &str) {
  std::regex reg("[aeiou]", std::regex_constants::icase | std::regex_constants::nosubs);
  // auto sBegin = std::sregex_iterator(str.begin(), str.end(), reg);
  // auto sEnd = std::sregex_iterator();
  // return static_cast<int>(std::distance(sBegin, sEnd));
  size_t i = 0;
  for(std::sregex_iterator it = std::sregex_iterator(str.begin(), str.end(), reg);
      it != std::sregex_iterator();
      ++it )
    {
      i++;
    }
  
    return i;
  }

#endif

int main(void) { 
  // keep this function call here
  std::cout << VowelCount(coderbyteInternalStdinFunction(stdin));
  return 0;
}