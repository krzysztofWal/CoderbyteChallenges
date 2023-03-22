/*
Division
#algebra 

Have the function Division(num1,num2) take both parameters being passed and return
the Greatest Common Factor. That is, return the greatest number that evenly goes
into both numbers with no remainder. For example: 12 and 16 both are divisible by
1, 2, and 4 so the output should be 4. The range for both parameters will be from
1 to 10^3. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>

int Division(int n1, int n2) {
  // code goes here
  int rest{};
  while (true) {
    rest = n1 % n2;
    if (rest != 0) {n1 = n2; n2 = rest;}
      else {break;}
  }
  return n2;
}

int main(void) { 
  // keep this function call here
  std::cout << Division(coderbyteInternalStdinFunction(stdin));
  return 0;
}