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
int FirstFactorial(int num) {
  // code goes here  
  int sum=1;
  for (int i=1;i<=num;i++) {sum = sum*i;}
  return sum;
}

int main(void) { 
  // keep this function call here
  std::cout << FirstFactorial(coderbyteInternalStdinFunction(stdin));
  return 0;
}