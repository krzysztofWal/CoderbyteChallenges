/*
Fibonnacci Checker

Have the function FibonacciChecker(num) return the string yes if the number given
is part of the Fibonacci sequence. This sequence is defined by: Fn = Fn-1 + Fn-2,
which means to find Fn you add the previous two numbers up. The first two numbers
are 0 and 1, then comes 1, 2, 3, 5 etc. If num is not in the Fibonacci sequence,
return the string no. 

Optimal: o(-), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// b - base
double MyLog(double a, double b) {
  return std::log2(a)/std::log2(b);
}

std::string FibonacciChecker(int num) {
  
  // code goes here
  // https://r-knott.surrey.ac.uk/Fibonacci/fibFormula.html#section1.1
  const double fi = (1+std::sqrt(5.))/2;
  int ind;
  if (num == 1 || num == 2) {return "yes";}
  // index of nth fibonnaci number that is not less than num
  ind = std::round(MyLog((num*std::sqrt(5.)-1/2),fi));
 // check if nt-h fibbonacci number is equal to num
  if ((int)std::round(std::pow(fi,ind)/std::sqrt(5)) != num) {
    return "no";
  } else {
    return "yes";
  }
}

int main(void) { 
   
  // keep this function call here
  // int arr[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352};
  // size_t sum{};
  // for (size_t i{}; i < sizeof(arr)/sizeof(*arr); i++) {
  //   if (FibonacciChecker(arr[i])=="yes") {sum++;}
  //   else {std::cout << arr[i] << "\n";}
  //   if (i > 2 && FibonacciChecker(arr[i]+1)=="yes") {std::cout << arr[i]+1 << std::endl;}  
  //   if (i > 4 && FibonacciChecker(arr[i]-1)=="yes") {std::cout << arr[i]-1 << std::endl;}  
  // }
  // std::cout << sum << " " << sizeof(arr)/sizeof(*arr) << std::endl;
  cout << FibonacciChecker(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
