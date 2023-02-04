/*
Coin Determiner

Have the function CoinDeterminer(num) take the input, which will be an integer ranging
from 1 to 250, and return an integer output that will specify the least number of
coins, that when added, equal the input integer. Coins are based on a system as follows:
there are coins representing the integers 1, 5, 7, 9, and 11. So for example: if
num is 16, then the output should be 2 because you can achieve the number 16 with
the coins 9 and 7. If num is 25, then the output should be 3 because you can achieve
25 with either 11, 9, and 5 coins or with 9, 9, and 7 coins. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <array>

int CoinDeterminer(int num) {
  // this brilliant solution is not mine, it is taken from 
  // https://math.stackexchange.com/questions/4181564/coindeterminer-by-modulo
  // also there is a good explanation, on which that here is based

  // num is smaller than 5, no other way than to give 1's
  if (num < 5) return num;
  // given num = 11 * n + rest
  int rest = num % 11;

  if (rest == 0) {
    // num = 11 * n; where n >= 0
    return num/11;
  } else if ( rest % 2 != 0) {
    // rest is an odd number that is it belongs to set {1,3,5,7,9}
    // each of these can be easily satisfied with one plus coin
    // (when rest == 3, than we can have (n-1) 11's, one 9 and one 5,
    // it can be done when n>= 1, however would n==0, this case is
    // adressed in the first if statement (num < 5))
    return num/11 + 1;
  } else {
    // rest is an even number, taken from set {2, 4, 6, 8, 10}
    // each of these can be achieved by 2 additional coins
    // 2 -> 1,1; 4 -> 3,1; 6 -> 5,1; 8 - > 7,1; 10 -> 9,1
    return num/11 + 2;
  }
}

int main(void) { 
  // keep this function call here
  std::cout << CoinDeterminer(coderbyteInternalStdinFunction(stdin));
  return 0;
}