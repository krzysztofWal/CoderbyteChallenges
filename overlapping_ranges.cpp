/*
Overlapping Ranges
#set_theory #array #search 

Have the function OverlappingRanges(arr) take the array of numbers stored in arr
which will contain 5 positive integers, the first two representing a range of numbers
(a to b), the next 2 also representing another range of integers (c to d), and a
final 5th element (x) which will also be a positive integer, and return the string
true if both sets of ranges overlap by at least x numbers. For example: if arr is
[4, 10, 2, 6, 3] then your program should return the string true. The first range
of numbers are 4, 5, 6, 7, 8, 9, 10 and the second range of numbers are 2, 3, 4,
5, 6. The last element in the array is 3, and there are 3 numbers that overlap between
both ranges: 4, 5, and 6. If both ranges do not overlap by at least x numbers, then
your program should return the string false. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string OverlappingRanges(int arr[], int arrLength) {
  // code goes here  
  const int a{arr[0]};  const int b{arr[1]};
  const int c{arr[2]};  const int d{arr[3]};
  if  ((d-a+1>=arr[4] && c<=a) || 
      (b-c+1>arr[4] && b<=d) || 
      (a>=c && b<=d && b-a+1>=arr[4]) || 
      (c>=a && d<=b && d-c+1>=arr[4])) {
    return "true";
  }
  return "false";
}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << OverlappingRanges(A, arrLength);
  return 0;
    
}