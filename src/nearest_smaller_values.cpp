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
  std::string finalSequence;
  std::stack<int> monStack;

  // for all elements in an array
  // logic here probably could be simplified - especially with the repeat of adding top
  // of the stack to the final sequence
  for (size_t i{}; i < arrLength; i++) {
    // if the stack is not empty and the element on top is smaller or equal to thr current array element
    if (!monStack.empty() && monStack.top() <= arr[i]) {
      // put the top of the stack into final Sequence
      finalSequence += std::to_string(monStack.top());
    } else {
      // if the stack is emtpy or the current element is greater than whats on top of the stack
      while (!monStack.empty() && monStack.top() > arr[i]) { 
        // pop from the top of the stack until the element is smaller or equal  
        monStack.pop(); 
      }
      // now the stack is either empty, in which case there is no smaller value to the left
      // or the stack is not empty in which case on top of it is the searched value for this
      // position - then add the top of the stack to the final sequence
      if (!monStack.empty()) { finalSequence += std::to_string(monStack.top()); }
    }
    
    // if the stack is empty now, that means there were no smaller on the left to arr[i]
    // add -1 to final sequence - this always happens for the first element (with index 0 that is)
    if (monStack.empty()) finalSequence += "-1";
    
    // push current element on the top of the stack
    // if the stack was empty that means that arr[i] is the smallest up until now so
    // no point in bothering with the previous one, if the stack was not empty
    // it means that there were smaller ones, but this larger, current one
    // may be smaller than what comes next, so save it
    monStack.push(arr[i]);
    finalSequence += " ";
  }

  return finalSequence;
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << NearestSmallerValues(A, arrLength);
  return 0;
}