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
#include <deque>

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

int main(void) { 
  // keep this function call here
  std::cout << ABCheck(coderbyteInternalStdinFunction(stdin));
  return 0;
}