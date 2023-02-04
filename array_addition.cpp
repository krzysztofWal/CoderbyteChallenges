/*
Array addition

Have the function ArrayAddition(arr) take the array of numbers stored in arr and
return the string true if any combination of numbers in the array (excluding the
largest number) can be added up to equal the largest number in the array, otherwise
return the string false. For example: if arr contains [4, 6, 23, 10, 1, 3] the output
should return true because 4 + 6 + 10 + 3 = 23. The array will not be empty, will
not contain all the same elements, and may contain negative numbers. 

Optimal: o(n^2), achieved: o(n^2)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ArrayAddition(int arr[],int N) { 
	
  int max{*std::max_element(arr,arr+N)};
  int sum{};
  size_t k{};

  // if all without max are needeed 
  for (size_t i{}; i < N; i++) {
    if (arr[i] != max) sum += arr[i];
  }
  
  if(max == sum) return "true";

  for (size_t i{}; i < N; i++) {
    if (arr[i] != max) {
      sum = 0;
      k = i + 1;
      for (size_t j{}; j < N - 1; j++) {
        if (k == N) k = 0;
        if (arr[k] != max) {
          sum += arr[k];
          if (sum == max) return "true";
        }
        k++;   
      }
    }
  }
  return "false";
}

int main() { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  int A[] = gets(stdin);
  cout << ArrayAddition(A, sizeof(A) / sizeof(*A));
  return 0;
    
}