/*
Bitwise One
#bitwise operations #array #search 

Have the function BitwiseOne(strArr) take the array of strings stored in strArr,
which will only contain two strings of equal length that represent binary numbers,
and return a final binary string that performed the bitwise OR operation on both
strings. A bitwise OR operation places a 0 in the new string where there are zeroes
in both binary strings, otherwise it places a 1 in that spot. For example: if strArr
is ["1001", "0100"] then your program should return the string "1101" 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

std::string BitwiseOne(std::string strArr[], int arrLength) {  
  // code goes here
  std::bitset<32> bit{ std::stoul(strArr[0],nullptr,2) | std::stoul(strArr[1],nullptr,2)};
  std::stringstream ss;
  ss << bit;
  ss >> strArr[0];
  return strArr[0].substr(strArr[0].length() - strArr[1].length() , strArr[1].length());
}

int main(void) { 
  // keep this function call here
  std::string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << BitwiseOne(A, arrLength);
  return 0;
}