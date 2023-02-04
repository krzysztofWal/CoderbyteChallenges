/*
Longest Increasing Sequence

Have the function LongestIncreasingSequence(arr) take the array of positive integers
stored in arr and return the length of the longest increasing subsequence (LIS).
A LIS is a subset of the original list where the numbers are in sorted order, from
lowest to highest, and are in increasing order. The sequence does not need to be
contiguous or unique, and there can be several different subsequences. For example:
if arr is [4, 3, 5, 1, 6] then a possible LIS is [3, 5, 6], and another is [1, 6].
For this input, your program should return 3 because that is the length of the longest
increasing subsequence. 

Optimal: o(n log n), achieved: o(n log n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int LongestIncreasingSequence(int arr[], int arrLength) {
    // code goes here  
    size_t cnt{ 1 };
    std::vector<int> withEnds{ arr[0] };
    std::vector<int>::iterator it;

    for (size_t i{ 1 }; i < arrLength; i++) {
        if (arr[i] > withEnds.back()) {
            // append to the vector
            if (cnt >= withEnds.size()) {
                withEnds.push_back(arr[i]);
            } else {
            // replace at given position
                withEnds.at(cnt) = arr[i];
            }
            cnt++;
        } else if (arr[i] < withEnds.front()) {
            // set to the be the first thing
            withEnds.at(0) = arr[i];
        } else {
            // find position with an element smaller than that and keep 
            // it and previous elements on the list - using binary search
            *((std::upper_bound(withEnds.begin(),withEnds.end(),arr[i]))) = arr[i];
        }

    }
 
    return  withEnds.size();
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << LongestIncreasingSequence(A, arrLength);
  return 0;
}