/*
Bracket Combinations

Have the function BracketCombinations(num) read num which will be an integer greater
than or equal to zero, and return the number of valid combinations that can be formed
with num pairs of parentheses. For example, if the input is 3, then the possible
combinations of 3 pairs of parenthesis, namely: ()()(), are ()()(), ()(()), (())(),
((())), and (()()). There are 5 total combinations when the input is 3, so your program
should return 5. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int BracketCombinations(int num) {
  int previousCatalan{1};
  for (int i{1};i<num;i++) {
    previousCatalan = previousCatalan*(2*(2*i+1))/(i+2);
   // std::cout << previousCatalan << "\n";
  }
  return previousCatalan;

}

int main(void) { 
   
  // keep this function call here
  cout << BracketCombinations(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}