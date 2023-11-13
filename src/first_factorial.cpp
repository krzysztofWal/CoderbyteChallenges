/*
First Factorial
#recursion #tree 

Have the function FirstFactorial(num) take the num parameter being passed and return
the factorial of it. For example: if num = 4, then your program should return (4
* 3 * 2 * 1) = 24. For the test cases, the range will be between 1 and 18 and the
input will always be an integer. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
long long FirstFactorial(int num) {
  // code goes here  
  long long sum=1;
  for (int i=1;i<=num;i++) {sum = sum*static_cast<long long>(i);}
  return sum;
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests
int main(void) { 
  // keep this function call here
  // std::cout << FirstFactorial(coderbyteInternalStdinFunction(stdin));
  std::cout << FirstFactorial(std::stoi(coderbyteInternalStdinFunction(stdin)));
  return 0;
}
#endif