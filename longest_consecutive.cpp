/*
Longest Consecutive
#dynamic #sequences #array #sort 

Have the function LongestConsecutive(arr) take the array of positive integers stored
in arr and return the length of the longest consecutive subsequence (LCS). An LCS
is a subset of the original list where the numbers are in sorted order, from lowest
to highest, and are in a consecutive, increasing order. The sequence does not need
to be contiguous and there can be several different subsequences. For example: if
arr is [4, 3, 8, 1, 2, 6, 100, 9] then a few consecutive sequences are [1, 2, 3,
4], and [8, 9]. For this input, your program should return 4 because that is the
length of the longest consecutive subsequence. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <unordered_set>

int LongestConsecutive(int arr[], int arrLength) {
  // code goes here
  // use unordered set with average constant time insertion 
  // and saying if the set contains an element
  size_t cnt, max{};
  int el;

  std::unordered_set<int> us;
  for (size_t i{}; i < arrLength; i++) {us.insert(arr[i]);}

  for (size_t i{0}; i < arrLength; i++) {
    cnt = 1;
    el = arr[i] + 1;
    while (us.find(el) != us.end()) {cnt++;el++;}
    if (cnt > max) max = cnt;
  }

  return max;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << LongestConsecutive(A, arrLength);
  return 0;
}