/*
AB Check
#regex #string manipulation 

Have the function ABCheck(str) take the str parameter being passed and return the
string true if the characters a and b are separated by exactly 3 places anywhere
in the string at least once (ie. "lane borrowed" would result in true because there
is exactly three characters between a and b). Otherwise return the string false.

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

#define SAY_YES_TO_REGEX 


#ifndef SAY_YES_TO_REGEX
#include <deque>
// who heard of regexes? not me
std::string ABCheck(std::string str) {
   // code goes here  
  size_t a{str.find("a")},b{str.find("b")},s{str.find(" ")};
  int sPos{-1}, sCnt;
  std::deque<int> pos{};
  while (pos.empty() || pos.back() < std::string::npos) {
    if (s<b && s<a) {
      sCnt=1;
      while (str.find(" ",s+1) == s+1) {s++;sCnt++;}
      sPos = s;
      s = str.find(" ",s+1);
    } else if (a<s && a<b) {
      pos.push_back(a);
      a = str.find("a",a+1);
      if (pos.size()>2) {pos.pop_front();}
    } else {
      pos.push_back(b);
      b = str.find("b",b+1);
      if (pos.size()>2) {pos.pop_front();}
    } 
     if (pos.size() > 1 &&
        (sPos <= pos.front() || sPos >= pos.back()) &&
        pos.back() - pos.front() == 4 ) {
      return "true";
    } else if (pos.size() > 1 &&
              sPos > pos.front() && sPos < pos.back() &&
              pos.back() - pos.front() == 3 + sCnt) {
      return "true";
    } 
  }
  return "false";
}

#else
#include <regex>
// oh, but you know, they actually can be handy
// and look since c++ 11 you can do them without third-party libraries!
// how quaint
std::string ABCheck(std::string str) {
    // matches the whole expression so we need optional 'padding'
    // std::regex regexExpr("((.)|(\n))*a((.)|(\n)){3,3}b((.)|(\n))*", std::regex_constants::nosubs|std::regex_constants::icase);

    // if (std::regex_match(str, regexExpr)) {
    //   return "true";
    // } else {
    //   return "false";
    // };

    std::regex regexExpr("a((.)|(\n)){3,3}b", std::regex_constants::nosubs | std::regex_constants::icase);
    if (std::regex_search(str.cbegin(), str.cend(),  regexExpr, std::regex_constants::match_any)) {
      return "true";
    } else {
      return "false";
    }

}

#endif


int main(void) { 
  // keep this function call here
  std::cout << ABCheck(coderbyteInternalStdinFunction(stdin));
  return 0;
}