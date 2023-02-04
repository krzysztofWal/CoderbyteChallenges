/*
Array Rotation

Have the function ArrayRotation(arr) take the arr parameter being passed which will
be an array of non-negative integers and circularly rotate the array starting from
the Nth element where N is equal to the first integer in the array. For example:
if arr is [2, 3, 4, 1, 6, 10] then your program should rotate the array starting
from the 2nd position because the first element in the array is 2. The final array
will therefore be [4, 1, 6, 10, 2, 3], and your program should return the new array
as a string, so for this example your program would return 4161023. The first element
in the array will always be an integer greater than or equal to 0 and less than the
size of the array. 

Optimal: o(-), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <queue>


std::string ArrayRotation(int arr[], int arrLength) {
  std::string retVal;
  int i{ arr[0] };
  for (int j{ 0 }; j < arrLength;j++) {
      retVal += std::to_string(arr[i]);
      i = (i + 1 == arrLength) ? 0 : i + 1;
  }
  return retVal;
}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << ArrayRotation(A, arrLength);
  return 0;
    
}