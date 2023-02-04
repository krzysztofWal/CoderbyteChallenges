/*
Triple double

Have the function TripleDouble(num1,num2) take both parameters being passed, and
return 1 if there is a straight triple of a number at any place in num1 and also
a straight double of the same number in num2. For example: if num1 equals 451999277
and num2 equals 41177722899, then return 1 because in the first parameter you have
the straight triple 999 and you have a straight double, 99, of the same number in
the second parameter. If this isn't the case, return 0. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <unordered_set>

int TripleDouble(int num1, int num2) {
  
  // code goes here  
  std::string sNum1 = std::to_string(num1);
  std::string sNum2 = std::to_string(num2);
  std::unordered_set<char> numSet;

  if (sNum1.length() < 3 || sNum2.length() < 2) { return 0; }
  for (size_t i{0}; i<=sNum1.length()-3; i++) {
    if (sNum1.at(i) == sNum1.at(i+1) && sNum1.at(i) == sNum1.at(i+2) && numSet.find(sNum1.at(i)) == numSet.end()) {
      numSet.insert(sNum1.at(i));
    }
  }
  for (size_t i{0}; i<=sNum2.length()-2; i++) {
    if (sNum2.at(i) == sNum2.at(i+1) && numSet.find(sNum2.at(i)) != numSet.end()) {
      return 1;
    }
  }
  return 0;

}

int main(void) { 
   
  // keep this function call here
  std::cout << TripleDouble(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}