/*
FizzBuzz

Have the function FizzBuzz(num) take the num parameter being passed and return all
the numbers from 1 to num separated by spaces, but replace every number that is divisible
by 3 with the word "Fizz", replace every number that is divisible by 5 with the word
"Buzz", and every number that is divisible by both 3 and 5 with the word "FizzBuzz".
For example: if num is 16, then your program should return the string "1 2 Fizz 4
Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16". The input will be within the
range 1 - 50. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string FizzBuzz(int n) {
  std::string num{};
  // idea taken from https://dev.to/itr13/what-is-the-fastest-fizzbuzz-21cp
  // does it makes sense not in C and with Cpp string manipulation? 
  // good question
  int arr[] = {3, 0, 0, 2, 0, 1, 2, 0, 0, 2, 1, 0, 2, 0, 0};
  for (int i{ 1 }; i <= n; i++) {
      switch (*(arr + i % 15)) {
      case 0:
          num += (std::to_string(i))+" ";
          break;
      case 2:
          num += "Fizz ";
          break;
      case 1:
          num += "Buzz ";
          break;
      default:
          num += "FizzBuzz ";
          break;
      }
  }
  num.pop_back();
  return num;

}

int main(void) { 
   
  // keep this function call here
  std::cout << FizzBuzz(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}