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


/* jiggery-pokery for testing (and because templates being templates) */
#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG 
    #define TEST_SHENANIGANS
#endif
#ifdef TEST_SHENANIGANS

/*  CONSTEXPR FIZZBUZ - create an array at compile time
    This solution is shamelessly stolen from https://arne-mertz.de/2019/12/constexpr-fizzbuzz/ by Arne Mertz and modified a bit.
    But look there for an explanation and the original concept.

    I will not lie, the idea of using std::integer_sequence in the recursion-free version was given to me by an AI.
    In my defense I was today years old when I learned about std::integer_sequence.
    And of course implemantation provided by the AI did not work, so good old documentation and trial and error are still (happily) the way forward.
*/

// because std::copy is not constexpr
constexpr void constCopy(char const* a, char const* b, char* to) {
    while (a < b) {
        *to++ = *a++;
    }
}

// this is rather self-explanatory
template <std::size_t N, std::size_t M>
constexpr std::array<char, N+M> operator+(std::array<char, N> const &s1, std::array<char, M> const &s2) {
    std::array<char, N+M> RET_ARR {};
    constCopy(s1.begin(), s1.end(), RET_ARR.begin());
    constCopy(s2.begin(), s2.end(), RET_ARR.begin() + N);
    return RET_ARR;
}

// convert an integer to a character array representation
template <std::size_t N>
constexpr auto toConstCharArr() {
    constexpr char LAST_DIGIT = '0' + N % 10;
    if constexpr (N >= 10) {
        return toConstCharArr<N/10>() + std::array<char, 1>{LAST_DIGIT};
    } else {
        return std::array<char, 1>{LAST_DIGIT};
    }
}

// get a fizz, a buzz or a number depending on ptemplate parameter N
template <std::size_t N>
constexpr auto fizzingOrBuzzing()
{
    constexpr std::array<char, 4> BUZZ{'B','u','z','z'};
    constexpr std::array<char, 4> FIZZ{'F','i','z','z'};

    if constexpr ( N%3 == 0) {
        return FIZZ;
    } else if constexpr (N%5 == 0){
        return BUZZ;
    } else {
        return toConstCharArr<N>();
    }
}

/* the 'final' function that does the main task */
template <std::size_t N>
constexpr auto compileTimeRecursiveFizzBuzz() {
    static_assert( N > 0 );
    constexpr std::array<char, 2> SEPARATOR{',', ' '};
    constexpr auto FIZZ_BUZZ = fizzingOrBuzzing<N>();
    if constexpr (N != 1) {
        return compileTimeRecursiveFizzBuzz<N - 1>() + (SEPARATOR + FIZZ_BUZZ);
    }  else {
        return FIZZ_BUZZ;
    }
}

/* how to 'unwind' recursion with constexpr?
 maybe like this: */
template <std::size_t... Ints>
constexpr auto fizzBuzzGenerator(std::integer_sequence<std::size_t, Ints...>) {
    constexpr std::array<char, 2> SEPARATOR{',', ' '};
    return ((fizzingOrBuzzing<Ints +1>() + SEPARATOR) + ...);
}

/* at compile time we get the array, and at runtime we return a string created with it */
template<std::size_t N>
std::string getFizzBuzz() {
    constexpr auto res = fizzBuzzGenerator(std::make_integer_sequence<std::size_t, N>());
    return std::string(res.data(), res.size() - 2); // trim the trailing SEPARATOR
}

std::string FizzBuzz(int n) {
  std::string num{};
  // idea taken from https://dev.to/itr13/what-is-the-fastest-fizzbuzz-21cp
  // does it makes sense not in C and with Cpp string manipulation? 
  // good question and probably not, because also string allocation
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

/* more adaptable */
std::string FizzBuzzClassic(int n) {
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

#endif

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG 
int main(void) { 
    // keep this function call here
    // std::cout << FizzBuzz(coderbyteInternalStdinFunction(stdin));
    // std::cout << FizzBuzz(std::stoi(coderbyteInternalStdinFunction(stdin)));
    constexpr auto fizzBuzz = compileTimeRecursiveFizzBuzz<100>(); // <= you can see in the .s file when compiled with flag
                                                                   //  -save-temps (in case of GCC) that its just data
    std::cout << std::string_view(fizzBuzz.data(), fizzBuzz.size()) << std::endl;
    
    std::cout << getFizzBuzz<100>();
    // st
    return 0;
}
#endif