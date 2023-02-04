/*
Word Count

Have the function WordCount(str) take the str string parameter being passed and return
the number of words the string contains (e.g. "Never eat shredded wheat or cake"
would return 6). Words will be separated by single spaces. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using namespace std;

int WordCount(string str) {
  
  // code goes here  
  size_t pos{str.find(" ")};
  size_t cnt{};
  while (pos != std::string::npos) {
    if (str.at(pos) == ' ') {cnt++;}
    pos = str.find(" ",pos+1);
  }  
  return ++cnt;

}

int main(void) { 
   
  // keep this function call here
  cout << WordCount(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}