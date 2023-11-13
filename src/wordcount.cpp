/*
Word Count
#string manipulation 

Have the function WordCount(str) take the str string parameter being passed and return
the number of words the string contains (e.g. "Never eat shredded wheat or cake"
would return 6). Words will be separated by single spaces. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

int WordCount(std::string str) {
  // code goes here  
  
  size_t counter{};
  size_t startInd{};
  size_t endInd{str.length() - 1};

  // 'remove'trailing and leading spaces
  while (str.at(startInd) == ' ') { startInd++; }
  while (str.at(endInd) == ' ') { endInd--; } 

  // start at startInd
  size_t pos{startInd};
  // until you reach the and of the string
  do {
    if (str.at(pos) == ' ') {counter++;}
    pos = str.find(" ",pos+1);
  } while (pos < endInd);

  return ++counter;
}

int main(void) { 
  // keep this function call here
  std::cout << WordCount(coderbyteInternalStdinFunction(stdin));
  return 0;
}