/*
Prime Checker
#prime 

Have the function PrimeChecker(num) take num and return 1 if any arrangement of num
comes out to be a prime number, otherwise return 0. For example: if num is 910, the
output should be 1 because 910 can be arranged into 109 or 019, both of which are
primes. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

bool IsPrime(int num) {
  if (num <= 1 || num % 2 == 0) {return 0;}
  for (int i{3}; i <= sqrt(num); i+=2) {
    if (num % i == 0) {return 0;}
  }
  return 1;
}

int PrimeChecker(int num) {
  // code goes here  
  std::string s = std::to_string(num);
  std::sort(s.begin(),s.end());
  do {
     if (IsPrime(std::stoi(s))) {return 1;}
  } while(std::next_permutation(s.begin(), s.end()));

  return 0;
}

int main(void) { 
   
  // keep this function call here
  std::cout << PrimeChecker(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}