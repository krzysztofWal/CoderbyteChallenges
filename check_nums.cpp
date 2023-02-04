/*
Check Nums

Have the function CheckNums(num1,num2) take both parameters being passed and return
the string true if num2 is greater than num1, otherwise return the string false.
If the parameter values are equal to each other then return the string -1. 

Optimal: o(-), achieved: o(-) - not being calculated
*/

#include <iostream>
#include <string>
using namespace std;

std::string CheckNums(int num1, int num2) {
  
  if (num2 > num1) {
    return "true";
  } else if (num2 < num1) {
    return "false";
  } else {
    return "-1";
  }

}

int main(void) { 
   
  // keep this function call here
  cout << CheckNums(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}