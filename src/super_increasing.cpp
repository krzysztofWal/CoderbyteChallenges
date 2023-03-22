/*
Super Increasing
#array 

Have the function Superincreasing(arr) take the array of numbers stored in arr and
determine if the array forms a superincreasing sequence where each element in the
array is greater than the sum of all previous elements. The array will only consist
of positive integers. For example: if arr is [1, 3, 6, 13, 54] then your program
should return the string "true" because it forms a superincreasing sequence. If a
superincreasing sequence isn't formed, then your program should return the string
"false" 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string Superincreasing(int arr[], int arrLength) {
  // code goes here
  for (size_t i{1}; i < arrLength; i++) {
    if (arr[i] <= arr[i-1]) {return "false";}
    arr[i] += arr[i-1];
  }
  return "true";
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << Superincreasing(A, arrLength);
  return 0;
}