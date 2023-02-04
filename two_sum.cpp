/*
Two Sum

Have the function TwoSum(arr) take the array of integers stored in arr, and determine
if any two numbers (excluding the first element) in the array can sum up to the first
element in the array. For example: if arr is [7, 3, 5, 2, -4, 8, 11], then there
are actually two pairs that sum to the number 7: [5, 2] and [-4, 11]. Your program
should return all pairs, with the numbers separated by a comma, in the order the
first number appears in the array. Pairs should be separated by a space. So for the
example above, your program would return: 5,2 -4,11
 
If there are no two numbers that sum to the first element in the array, return -1

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

struct {
  bool operator()(const std::pair<size_t, size_t> &p1, 
  const std::pair<size_t, size_t> &p2) const {return p1.first < p2.first;}
} PairCompare;

std::string TwoSum(int arr[], int arrLength) {
  
  std::string tmp;
  std::unordered_map<int, size_t> mp;
  std::unordered_map<int, size_t>::iterator it;
  std::vector<std::pair<size_t,size_t>> v;
  
  for (size_t i{1}; i < arrLength; i++) {
    it = mp.find(arr[i]);
    // if in a map there is a postion of an element which added to arr[i] gives arr[0]
    // add that position along with the current one to the vector
    if (it != mp.end()) v.emplace_back(std::pair<size_t,size_t>(it->second,i));
    // add position to map with difference as a key
    mp[arr[0]-arr[i]] = i;
  }

  std::sort(v.begin(), v.end(), PairCompare);
  for (const auto &el : v) {
    tmp += std::to_string(arr[el.first]) + "," + 
          std::to_string(arr[el.second]) + " ";
  }
  
  if (tmp.empty()) tmp = "-1 ";
  tmp.pop_back();

  return tmp;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << TwoSum(A, arrLength);
  return 0;
}