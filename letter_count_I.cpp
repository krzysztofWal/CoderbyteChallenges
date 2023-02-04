/*
LetterCountI

Have the function LetterCountI(str) take the str parameter being passed and return
the first word with the greatest number of repeated letters. For example: 
"Today, is the greatest day ever!" should return greatest because it has 2 e's (and 2 t's)
and it comes before ever which also has 2 e's. If there are no words with repeating
letters return -1. Words will be separated by spaces. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <map>

int LetterCount(std::string_view const &str, std::map<char,int> &mapTemp) {
  std::map<char,int>::iterator it;
  int ret{};
  mapTemp.clear();
  for (const auto &el : str) {
    it = mapTemp.find(el);
    if (it==mapTemp.end()) {mapTemp[el] = 1;} else {it->second++;}
  }
  for (it = mapTemp.begin(); it != mapTemp.end();it++) {
    if (it->second > ret) {ret = it->second;}
  }
  return ret;
}

std::string_view LetterCountI(const std::string &str) {
  // code goes here  
  std::string_view strV = str;
  std::vector<std::pair<int,int>> posVec{};
  std::map<char,int> mapTemp;
  size_t pos{};
  int temp{-1};
  posVec.emplace_back(std::pair<int,int>(pos-1,0));
  
  while (pos < str.length() ) {
    pos = str.find(" ",pos+1);
    if (pos == std::string::npos) {pos = str.length();}
    posVec.emplace_back(
      std::pair<int,int>(pos, LetterCount(strV.substr(posVec.back().first+1, pos - posVec.back().first - 1), mapTemp)));
  }
  for (pos = 1; pos<posVec.size(); pos++){
    if (posVec.at(pos).second > temp+2) {temp = pos;} 
  }
  return ((temp!=-1) ? strV.substr( posVec.at(temp-1).first+1, posVec.at(temp).first - posVec.at(temp-1).first-1) : std::string_view("-1") );

}

int main(void) { 
   
  // keep this function call here
  std::cout << LetterCountI(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}