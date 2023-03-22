/*
Prime Time
#prime 

Have the function PrimeTime(num) take the num parameter being passed and return the
string true if the parameter is a prime number, otherwise return the string false.
The range will be between 1 and 2^16. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

std::string PrimeTime(int num) {
  // primes (besides two) have to be odd
  if (num <= 1) return "false";
   // modulo 6 of primes is either only 5 or 1 - with exception of 2 and 3
  if (num == 2 || num == 3) return "true";
  if (num % 6 != 1 && num % 6 != 5) return "false";

  for (int i{3};i<=sqrt(num);i+=2) {
    if (num%i==0) return "false";
  }
  
  return "true";
}

int main(void) { 
  // keep this function call here
  size_t primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
                    83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
                    173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
                    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367,
                    373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                    467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587,
                    593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683,
                    691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
                    821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
                    937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
  // ^ source: https://www.adda247.com/school/prime-numbers-between-1-to-100/
  std::vector<size_t> prime_vec;
  for (size_t i{}; i < 1000; i++) {
    if (PrimeTime(i) == "true") prime_vec.push_back(i);
  }
  if (sizeof(primes)/sizeof(size_t) != prime_vec.size()) {
    std::cout << "Error";
  } else {
    for (size_t i{}; i < prime_vec.size(); i++) {
      if (primes[i] != prime_vec.at(i)) {
        std::cout << primes[i] << " is not equal to " << prime_vec.at(i) << std::endl;
      }
    }
  }
  return 0;
}