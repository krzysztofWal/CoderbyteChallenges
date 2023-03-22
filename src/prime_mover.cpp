/*
Prime Mover
#prime 

Have the function PrimeMover(num) return the numth prime number. The range will be
from 1 to 10^4. For example: if num is 16 the output should be 53 as 53 is the 16th
prime number. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>

bool PrimeTime(int num) {
  for (int i{2};i<=sqrt(num);i++) {
    if (num%i==0) { return false;}
  }
  if (num <= 1) {return false;}
  return true;
}

int PrimeMover(int num) {
  int cnt{1};
  int i{3};

  if (num == 1) {return 2;}
  while (cnt<num) {
    if (PrimeTime(i)) {cnt++;}
    i+=2;
  }
  // code goes here  
  return i-2;
}

int main(void) { 
  // keep this function call here
  std::cout << PrimeMover(coderbyteInternalStdinFunction(stdin));
  return 0;
}