/*
Mean Mode
#hashmap #array 

Have the function MeanMode(arr) take the array of numbers stored in arr and return
1 if the mode equals the mean, 0 if they don't equal each other (ie. [5, 3, 3, 3,
1] should return 1 because the mode (3) equals the mean (3)). The array will not
be empty, will only contain positive integers, and will not contain more than one
mode. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool MeanMode(int arr[], int arrLength) {
  // code goes here  
  std::unordered_map<int,size_t> mp;
  int mean{};
  auto it{mp.end()};
  
  for (size_t i{}; i < arrLength; i++) {
    // update hash map
    it = mp.find(arr[i]);
    if (it != mp.end()) {
      it->second++;
    } else {
      mp[arr[i]] = 1;
    }
    mean += arr[i];
  }
  mean /= arrLength;
  // sort map by value, by creating a vector and sorting it
  std::vector<std::pair<int,size_t>> v{std::make_move_iterator(mp.begin()), 
                                        std::make_move_iterator(mp.end())};
  std::sort(v.begin(),v.end(),[](auto p1, auto p2){return p1.second > p2.second;});

  return mean == v.begin()->first;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << MeanMode(A, arrLength);
  return 0;
}