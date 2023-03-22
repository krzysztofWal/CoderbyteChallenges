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
#include <set>
#include <algorithm>

int VowelCount(const std::string &str) {  
  // code goes here 
  int cnt{};
  std::set<char> vowSet = {'a','e','i','o','u'};
  std::for_each(str.begin(),str.end(),
    [&](char c){if(vowSet.find(c)!=vowSet.end()) {cnt++;} });
  return cnt;
}

int main(void) { 
  // keep this function call here
  std::cout << VowelCount(coderbyteInternalStdinFunction(stdin));
  return 0;
}