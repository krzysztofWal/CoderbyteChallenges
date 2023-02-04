/*
Letter changes

Have the function LetterChanges(str) take the str parameter being passed and modify
it using the following algorithm. Replace every letter in the string with the letter
following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every
vowel in this new string (a, e, i, o, u) and finally return this modified string.


Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

string LetterChanges(string str) {
  
  // code goes here  
  std::set<char> vowSet = {'a', 'e', 'i', 'o', 'u'};
  // assuming there are no uppercases in the beginning
  for (int i{0}; i<str.length(); i++) {
    if (isalpha(str.at(i))) {
      str.at(i)=static_cast<char>(str.at(i)+1);
      if (str.at(i) == '{') {str.at(i)='a';}
    }
    if (vowSet.find(str.at(i)) != vowSet.end()) {
      str.at(i) = toupper(str.at(i));
    }
  }
  return str;
  

}

int main(void) { 
   
  // keep this function call here
  cout << LetterChanges(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}