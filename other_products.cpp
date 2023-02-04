/*
Other Products

Have the function OtherProducts(arr) take the array of numbers stored in arr and
return a new list of the products of all the other numbers in the array for each
element. For example: if arr is [1, 2, 3, 4, 5] then the new array, where each location
in the new array is the product of all other elements, is [120, 60, 40, 30, 24].
The following calculations were performed to get this answer: [(2*3*4*5), (1*3*4*5),
(1*2*4*5), (1*2*3*5), (1*2*3*4)]. You should generate this new array and then return
the numbers as a string joined by a hyphen: 120-60-40-30-24. The array will contain
at most 10 elements and at least 1 element of only positive integers. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
using namespace std;

std::string OtherProducts(int arr[], int arrLength) {
  
  // code goes here
  size_t prod;
  size_t stop;
  std::string tmp{};
  for (size_t i{}; i < arrLength; i++) {
    prod = 1;
    stop = static_cast<size_t>(i==arrLength-1);
    for (size_t j{}; j < arrLength - stop; j++) {
      if (j==i) {j++;}
      prod *= arr[j];
    }
    tmp += std::to_string(prod) + "-";
  }
  tmp.pop_back();
  return tmp;

}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << OtherProducts(A, arrLength);
  return 0;
    
}