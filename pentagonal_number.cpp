/*
Pentagonal Number

Have the function PentagonalNumber(num) read num which will be a positive integer
and determine how many dots exist in a pentagonal shape around a center dot on the
Nth iteration. For example, in the image below you can see that on the first iteration
there is only a single dot, on the second iteration there are 6 dots, on the third
there are 16 dots, and on the fourth there are 31 dots. 

Your program should return the number of dots that exist in the whole pentagon on the 
Nth iteration. 

Optimal: o(-), achieved: o(n)
*/

#include <iostream>
#include <string>

int PentagonalNumber(int num) {
  // code goes here
  size_t sum{1};
  while (--num > 0) {
    sum += num * 5;
  }
  return sum;
}

int main(void) { 
  // keep this function call here
  std::cout << PentagonalNumber(coderbyteInternalStdinFunction(stdin));
  return 0;
}