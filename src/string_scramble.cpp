/*
String Scramble
#search #string manipulation 

Have the function StringScramble(str1,str2) take both parameters being passed and
return the string true if a portion of str1 characters can be rearranged to match
str2, otherwise return the string false. For example: if str1 is "rkqodlw" and str2
is "world" the output should return true. Punctuation and symbols will not be entered
with the parameters. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <map>
#include <string_view>

std::map<char,int> GetCharsMap(const std::string_view &str) {
  std::map<char,int> ret{};
  std::map<char,int>::iterator it;
  for (const auto &el : str) {
    it = ret.find(el);
    if (it != ret.end()) {
      it->second += 1;
    } else {
      ret[el] = 1;
    }
  }
  return ret;
}

std::string StringScramble(std::string str1, std::string str2) {
  // code goes here
  std::string_view strV1 = str1; 
  std::string_view strV2 = str2; 
  std::map<char,int> map1 = GetCharsMap(strV1);
  std::map<char,int> map2 = GetCharsMap(strV2);
  std::map<char,int>::iterator it1;

  for (auto it2{map2.begin()}; it2!=map2.end(); it2++) {
    it1 = map1.find(it2->first);
    if (it1 == map1.end() || it1->second < it2->second) {return "false";} 
  }
  return "true";

  return str1;
}

int main(void) { 
  // keep this function call here
  std::cout << StringScramble(coderbyteInternalStdinFunction(stdin));
  return 0;
}