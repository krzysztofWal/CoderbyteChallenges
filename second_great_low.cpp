/*
Second Great Low

Have the function SecondGreatLow(arr) take the array of numbers stored in arr and
return the second lowest and second greatest numbers, respectively, separated by
a space. For example: if arr contains [7, 7, 12, 98, 106] the output should be 12
98. The array will not be empty and will contain at least 2 numbers. It can get tricky
if there's just two numbers! 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <set>
#include <string>

std::string ToString(const std::pair<int,int> &p) {
  return std::to_string(p.first) + " " + std::to_string(p.second);
}

std::string SecondGreatLow(int arr[], int arrLength) {
  
  // code goes here
  std::pair<int,int> tmp{};
  std::set<int> setTmp{};
  std::set<int>::iterator it{};

  if (arrLength > 2) {
    for (size_t i{0};i<arrLength;i++) {
      setTmp.insert(arr[i]);
    }
    it = setTmp.upper_bound(*setTmp.begin());
    if (it != setTmp.end()) {tmp.first = *it;}
    it = setTmp.lower_bound(*(--(--setTmp.end())));
    if (it != setTmp.begin()) {tmp.second = *it;}
  } else if (arr[0] > arr[1]) {
    tmp = std::pair<int,int>(arr[0],arr[1]);
  } else {
    tmp = std::pair<int,int>(arr[1],arr[0]);
  }

  return ToString(tmp);
}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << SecondGreatLow(A, arrLength);
  return 0;
    
}