/*
Bracket Matcher
#stack #recursion #tree 

Have the function BracketMatcher(str) take the str parameter being passed and return
1 if the brackets are correctly matched and each one is accounted for. Otherwise
return 0. For example: if str is "(hello (world))", then the output should be 1,
but if str is "((hello (world))" the the output should be 0 because the brackets
do not correctly match up. Only "(" and ")" will be used as brackets. If str contains
no brackets return 1. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using namespace std;

int BracketMatcher(string str) {
  // code goes here
  // idea seen in deuzen user's code (Javascript)
  int cnt{};
  for (const auto &el : str) {
    if (el == '(') { cnt++; }
    else if (el == ')') {cnt--;}
    if (cnt < 0) {return 0;}
  }
  if (cnt == 0) {return 1;}
  return 0;
}

int main(void) { 
  // keep this function call here
  cout << BracketMatcher(coderbyteInternalStdinFunction(stdin));
  return 0;
}