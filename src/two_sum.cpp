/*
Two Sum
#hashmap #dynamic #array #search 

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

// comparing pairs by their firs element
struct {
  bool operator()(const std::pair<size_t, size_t> &p1, 
    const std::pair<size_t, size_t> &p2) const {
      return p1.first < p2.first;
  }
} PairCompare;

std::string TwoSum(int arr[], int arrLength) {
  
  std::string tmp;
  // unordered map for 
  std::unordered_map<int, size_t> mp;
  std::unordered_map<int, size_t>::iterator it;
  std::vector<std::pair<size_t,size_t>> v;
  
  // let Di be difference between the zero element and the i-th element
  // in the array 
  // indexes i of the array are stored in the map mp with Di as their key 
  // mp[Di] = i

  // from the second to the last element
  for (size_t i{1}; i < arrLength; i++) {
    // if there is a position saved in the map with arr[i] as the key
    // in other words -> is there a position p such that arr[p] + arr[i] = arr[0]
    // p is some value of 'iteration variable' i from previous pass of this loop
    it = mp.find(arr[i]);
    // if it is, add this p alongside i in the vector (as a pair)
    if (it != mp.end()) 
      v.emplace_back(std::pair<size_t,size_t>(it->second,i));
    
    // add the current i value to the map with difference Di as its key
    // for potentially matching it with next values of i
    mp[arr[0]-arr[i]] = i;
  }

  //sort vector of pairs by their first element, that is by the first
  // index from the pair
  std::sort(v.begin(), v.end(), PairCompare);

  // add found pairs to the return string
  for (const auto &el : v) {
    tmp += std::to_string(arr[el.first]) + "," + 
          std::to_string(arr[el.second]) + " ";
  }
  
  if (tmp.empty()) tmp = "-1 ";
  //remove the last character -which is always a trailing space ' '
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