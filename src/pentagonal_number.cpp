/*
Pentagonal Number
#combinatorics #sequences 

Have the function PentagonalNumber(num) read num which will be a positive integer
and determine how many dots exist in a pentagonal shape around a center dot on the
Nth iteration. For example, in the image below you can see that on the first iteration
there is only a single dot, on the second iteration there are 6 dots, on the third
there are 16 dots, and on the fourth there are 31 dots. 

image: https://en.wikipedia.org/wiki/File:Nombre_pentagon_cent.svg

Your program should return the number of dots that exist in the whole pentagon on the 
Nth iteration. 

Optimal: o(-), achieved: o(n)
*/

#include <iostream>
#include <string>

/* using loop - O(n) */
// int PentagonalNumber(int num) {
//   // code goes here
//   size_t sum{1};
//   num--;
//   while (num > 0) {
//     sum += num * 5;
//     num--;
//   }
//   return sum;
// }

/*  as can be seen in the loop above
    for n = 1 -> 1 + 5 * (0)
    for n = 2 -> 1 + 5 * (0 + 1)
    for n = 3 -> 1 + 5 * (0 + 1 + 2)
    for n = 4 -> 1 + 5 * (0 + 1 + 2 + 3)
    ... and so on until n
    for n -> 1 + 5 (0 + 1 + 2 + ... + n-1)
    the expression in parenthesis is the sum of first n elements of 
    an arithmetic series : 0, 1, 2, .., n-1
    for n -> 1 + 5 * Sn
    because Sn = ((0 + n - 1) / 2 ) n:
    pentagonalNumber(n) = 1 + 5 * (n^2 - n) / 2
 */
int PentagonalNumber(int num) {
  return 1 + 5 * (num * num - num) / 2;
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests
int main(void) { 
  // keep this function call here
  // std::cout << PentagonalNumber(coderbyteInternalStdinFunction(stdin));
  std::cout << PentagonalNumber(std::stoi(coderbyteInternalStdinFunction(stdin)));
  return 0;
}
#endif