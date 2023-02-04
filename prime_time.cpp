/*
Prime Time

Have the function PrimeTime(num) take the num parameter being passed and return the
string true if the parameter is a prime number, otherwise return the string false.
The range will be between 1 and 2^16. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

std::string PrimeTime(int num) {
  
  // code goes here  
  
  if (num <= 1 || (num % 2 == 0 && num != 2)) {return "false";}
  for (int i{3};i<=sqrt(num);i+=2) {
    if (num%i==0) {return "false";}
  }
  return "true";

}

int main(void) { 
   
  // keep this function call here
  cout << PrimeTime(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}