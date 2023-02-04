/*
Hamming Distance

Have the function HammingDistance(strArr) take the array of strings stored in strArr,
which will only contain two strings of equal length and return the Hamming distance
between them. The Hamming distance is the number of positions where the corresponding
characters are different. For example: if strArr is ["coder", "codec"] then your
program should return 1. The string will always be of equal length and will only
contain lowercase characters from the alphabet and numbers. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using namespace std;

size_t HammingDistance(string strArr[], int arrLength) {
  // code goes here
  std::string s1 = strArr[0];
  std::string s2 = strArr[1];
  size_t n{};

  for (size_t i{}; i < s1.length(); i++) {
    if (s1.at(i) != s2.at(i)) {n++;}
  }

  return n;
}

int main(void) { 
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << HammingDistance(A, arrLength);
  return 0;
}
