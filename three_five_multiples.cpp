/*
ThreeFive Multiples

Have the function ThreeFiveMultiples(num) return the sum of all the multiples of
3 and 5 that are below num. For example: if num is 10, the multiples of 3 and 5 that
are below 10 are 3, 5, 6, and 9, and adding them up you get 23, so your program should
return 23. The integer being passed will be between 1 and 100.

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int ThreeFiveMultiples(int num) {
  
  // code goes here  
  int cnt{}, fives{5}, threes{3};
  int sum{};
  while (fives < num || threes < num) {
    if (fives < num) {
      sum += fives;
      fives += 5;
    }
    if (threes < num) {
      sum += ((threes % 15 != 0) ? threes : 0 );
      threes += 3;
    }
  }

  return sum;

}

int main(void) { 
   
  // keep this function call here
  cout << ThreeFiveMultiples(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}
