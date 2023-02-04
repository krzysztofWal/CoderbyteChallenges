/*
Sum Multiplier

Have the function SumMultiplier(arr) take the array of numbers stored in arr and
return the string true if any two numbers can be multiplied so that the answer is
greater than double the sum of all the elements in the array. If not, return the
string false. For example: if arr is [2, 5, 6, -6, 16, 2, 3, 6, 5, 3] then the sum
of all these elements is 42 and doubling it is 84. There are two elements in the
array, 16 * 6 = 96 and 96 is greater than 84, so your program should
return the string true. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <numeric>
#include <set>
#include <algorithm>
using std::cout;

const char * SumMultiplier(int arr[], const size_t arrLength) {
  // code goes here 
  int sum{2 * std::accumulate(arr, arr+arrLength, 0)};
  std::nth_element(arr,arr+arrLength-1,arr+arrLength);
  std::nth_element(arr,arr+arrLength-2,arr+arrLength);
  if (arr[arrLength-2] * arr[arrLength-1] > sum) return "true"; 
  return "false";
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << SumMultiplier(A, arrLength);
  return 0;
}