/*
Max Subarray
#array 

Have the function MaxSubarray(arr) take the array of numbers stored in arr and determine
the largest sum that can be formed by any contiguous subarray in the array. For example,
if arr is [-2, 5, -1, 7, -3] then your program should return 11 because the sum is
formed by the subarray [5, -1, 7]. Adding any element before or after this subarray
would make the sum smaller. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>

int MaxSubarray(int arr[], int arrLength) {
  // code goes here
  int cs{}, bs{INT32_MIN};
  for (size_t i{}; i < arrLength; i++) {
    cs = std::max(arr[i],cs + arr[i]);
    bs = std::max(cs, bs);
  }
  return bs;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << MaxSubarray(A, arrLength);
  return 0;
}