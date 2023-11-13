/*
Bracket Combinations
#combinatorics #tree 

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

/* O(n) - using */

// int BracketCombinations(int num) {
//   int previousCatalan{1};
//   for (int i{1};i<num;i++) {
//     previousCatalan = previousCatalan*(2*(2*i+1))/(i+2);
//    // std::cout << previousCatalan << "\n";
//   }
//   return previousCatalan;
// }

/* Recursive using dynamic programming - O(n^2) -> cost: T(n)= (n^2 + n - 2)/2 
  - that is if number of recursive calls is halved  */
int Catalan(int num, std::vector<int> &cat, int &cnt) {
  cnt++;
  
  // catalan numbers -> c(n+1) = sum_(i = 0)^n [ c(i) + c(n-i) ]
  
  // if that catalan number is already calculated
  if (cat.size() > num) {
    return cat.at(num);
  }
  // calculate cat(n)
  int sum {0};
  int tmp{};
  
  // for (int i{0}; i<num;i++) {
  //   // call recursive
  //   sum += Catalan(i, cat, cnt) * Catalan(num - i - 1, cat, cnt);
  // }

  /* number of calls in half */
  // if num is even
  if (num % 2 == 0) {
    // for example for c(4) -> c(0)c(3) + c(1)c(2) + c(2)c(1) + c(3)(c0) = 2 (c(0)c(3) + c(1)c(2))  
    for (int i{0}; i< num/2; i++) {
      sum += 2 * (Catalan(i, cat, cnt) * Catalan(num - i - 1, cat, cnt));
    }
  // if num is odd
  } else {
    // for example for c(5) -> c(0)c(4) + c(1)c(3) + c(2)c(2) + c(3)c(1) + c(4)c(0) = 
    // = 2 [c(0)c(4) + c(1)c(3)] + [c(2)]^2
    for (int i{0}; static_cast<double>(i) < num/2; i++) {
      sum += 2 * (Catalan(i, cat, cnt) * Catalan(num - i - 1, cat, cnt));
    }
    int tmp = (Catalan(static_cast<int>(num/2), cat, cnt));
    sum += tmp * tmp;
  }

  // write it to cat
  cat.push_back(sum);
  // return cat(n)
  return sum;
}

int BracketCombinations(int num) { 
  std::vector<int> cat {1, 1};
  int cnt{0};
  int res = Catalan(num, cat, cnt);
  std::cout << "called : " << cnt << " times. Value: ";
  return res;
}


int main(void) {
   
  // keep this function call here
  // std::cout << BracketCombinations(coderbyteInternalStdinFunction(stdin));
  std::cout << BracketCombinations(std::stoi(coderbyteInternalStdinFunction(stdin)));
  // std::cout << BracketCombinations(2);
  // std::cout << BracketCombinations(3);
  // std::cout << BracketCombinations(4);

  return 0;
    
}