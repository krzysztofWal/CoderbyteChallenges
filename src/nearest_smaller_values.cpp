/*
Nearest Smaller Values
#data science #dynamic #array 

Have the function NearestSmallerValues(arr) take the array of integers stored in
arr, and for each element in the list, search all the previous values for the nearest
element that is smaller than (or equal to) the current element and create a new list
from these numbers. If there is no element before a certain position that is smaller,
input a -1. For example: if arr is [5, 2, 8, 3, 9, 12] then the nearest smaller values
list is [-1, -1, 2, 2, 3, 9]. The logic is as follows:

For 5, there is no smaller previous value so the list so far is [-1]. For 2, there
is also no smaller previous value, so the list is now [-1, -1]. For 8, the nearest
smaller value is 2 so the list is now [-1, -1, 2]. For 3, the nearest smaller value
is also 2, so the list is now [-1, -1, 2, 2]. This goes on to produce the answer
above. Your program should take this final list and return the elements as a string
separated by a space: -1 -1 2 2 3 9

Optimal: o(n), achieved: o(n)
*/
#include <iostream>
#include <string>
#include <stack>

std::string NearestSmallerValues(int arr[], int arrLength) {
  // code goes here  
  std::string tmp;
  std::stack<int> monStack;

  for (size_t i{}; i < arrLength; i++) {
    if (!monStack.empty() && monStack.top() <= arr[i]) {
      tmp += std::to_string(monStack.top());
    } else {
      while (!monStack.empty() && monStack.top() > arr[i]) { monStack.pop(); }
      if (!monStack.empty()) tmp += std::to_string(monStack.top());
    }
    
    if (monStack.empty()) tmp += "-1";
    
    monStack.push(arr[i]);
    tmp += " ";
  }

  return tmp;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << NearestSmallerValues(A, arrLength);
  return 0;
}