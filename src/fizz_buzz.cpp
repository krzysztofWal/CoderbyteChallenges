/*
FizzBuzz
#string manipulation 

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
#include <array>

/*
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
*/

/* more adaptable */
std::string FizzBuzz(int n) {
    const int arr_size = 2;
    std::array<int, arr_size> numbers { 3, 5};
    std::array<const char *, arr_size> fizzesAndBuzzes {"Fizz", "Buzz"};

    std::string tmp{};
    std::string res{};

    for (int i{ 1 }; i <= n; i++) {
        tmp = "";
        // is number Fizz or Buzz
        for (int j{ 0 }; j < arr_size; j++) {
            if (i % numbers.at(j) == 0) { tmp += fizzesAndBuzzes.at(j) ; }
        }
        // it is not a fizzbuzz number
        if (tmp.length() == 0) { tmp += std::to_string(i); }
        res += tmp + " \n";
    }

    return res;
}

int main(void) { 
  // keep this function call here
//   std::cout << FizzBuzz(coderbyteInternalStdinFunction(stdin));
    std::cout << FizzBuzz(std::stoi(coderbyteInternalStdinFunction(stdin)));
    return 0;
}