/*
Min Windows Substring

Have the function MinWindowSubstring(strArr) take the array of strings stored in
strArr, which will contain only two strings, the first parameter being the string
N and the second parameter being a string K of some characters, and your goal is
to determine the smallest substring of N that contains all the characters in K. For
example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that
contains the characters a, e, and d is "dae" located at the end of the string. So
for this example your program should return the string dae.

Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring
of N that contains all of the characters in K is "aabd" which is located at the beginning
of the string. Both parameters will be strings ranging in length from 1 to 50 characters
and all of K's characters will exist somewhere in the string N. Both strings will
only contains lowercase alphabetic characters. 

Optimal: o(n), achieved: o(n^2)
*/

#include <iostream>
#include <string>
#include <string_view>
#include <map>
#define FALSE 127
using std::cout;
using std::string;

std::map<char,int> getMapOfChars(const std::string_view &str){
  std::map<char, int> hashMap;
  std::map<char,int>::iterator it;
  for (const auto &ch : str) {
    it = hashMap.find(ch);
    if (it != hashMap.end()) {
      it->second += 1;
    } else {
      hashMap[ch] = 1;
    }
  }
  return hashMap;
}

bool isInside(std::map<char,int> &&m1, const std::map<char,int> &m2) {
  bool temp{true};
  std::map<char,int>::iterator itIn;
  if (m1.size() >= m2.size()) { 
    for (auto itWhat{m2.begin()}; itWhat != m2.end() ;itWhat++){ // iterate over charactersin m2
      itIn = m1.find(itWhat->first);
      // if there is no entry with that key in m1 
      // or the number of occurences is smaller in m1 than m2
      if (!(itIn != m1.end() && itIn->second >= itWhat->second)) {
        temp = false; 
        break;
      }
    }
  } else { // smaller number of unique characters in m1
    temp = false;
  }
  return temp;
}

string MinWindowSubstring(string strArr[], int arrLength) {
  // substrings
  std::string inFind = strArr[0]; std::string whatFind = strArr[1];
  std::string_view inFindV = inFind; std::string_view whatFindV = whatFind;
  std::string_view temp;
  // map of chars inside whatFind
  auto whatFindMap = getMapOfChars(whatFindV);
  // 'iterators' starts at zero
  std::size_t inFindBegin{}; std::size_t inFindEnd{};
  // minimal window info
  struct {
    std::size_t ind{};
    std::size_t len{}; // not including the first element
  }  minWindow;
  minWindow.len = inFindV.length();

  while (inFindEnd < inFindV.length() && minWindow.len+1 > whatFind.length()){
    // until reach the end of the inFind string or find valid string
    for (;inFindEnd < inFind.length(); inFindEnd++) {
      temp = inFindV.substr(inFindBegin,inFindEnd-inFindBegin+1);
      if (isInside(getMapOfChars(temp), whatFindMap)) {
        break;
        }
    }
    // minimalize the window up to the point when its not valid
    inFindBegin++;
    for (; inFindBegin <= inFindEnd - whatFind.length() + 1; inFindBegin++) {
      temp =inFindV.substr(inFindBegin,inFindEnd-inFindBegin+1);
      if (!isInside(getMapOfChars(temp), whatFindMap)) {
        break;
      }
    }
    inFindBegin--; // return to end index that gives valid window
    // if length of found window is smaller than the priovously found one
    if (inFindEnd-inFindBegin < minWindow.len) {
      minWindow.len = inFindEnd-inFindBegin; 
      minWindow.ind = inFindBegin;
    }
    inFindBegin++; inFindEnd++;
  }
  return inFind.substr(minWindow.ind, minWindow.len+1);

}

int main(void) { 
   
  // keep this function call here
  // string A[] = {"bacffa","aff"};
  // string A[] = {"ahffaksfajeeubsne", "jefaa"};
  // string A[] = {"aaffhkksemckelloe", "fhea"};
  // string A[] = {"aaffhkksemckellfhoeae", "fhea"};
  //  string A[] = {"aaaaaab", "b"};
  //  string A[] = {"baaaaab", "b"};
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;
    
}

// std::cout << "increasing inFindBegin, now its = " << inFindBegin <<  " str[inFindBegin] =" << inFind.at(inFindBegin) <<
//    " " << inFindV.substr(inFindBegin,inFindEnd-inFindBegin+1) <<  "\n";
//  std::cout << "increasing inFindEnd, now its = " << inFindEnd << " str[inFindEnd] =" << inFind.at(inFindEnd)<< 
//      " " << inFindV.substr(inFindBegin,inFindEnd-inFindBegin+1) << "\n";
