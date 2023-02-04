/*
Arith Geo

Have the function ArithGeo(arr) take the array of numbers stored in arr and return
the string "Arithmetic" if the sequence follows an arithmetic pattern or return "Geometric"
if it follows a geometric pattern. If the sequence doesn't follow either pattern
return -1. An arithmetic sequence is one where the difference between each of the
numbers is consistent, where as in a geometric sequence, each term after the first
is multiplied by some constant or common ratio. Arithmetic example: [2, 4, 6, 8]
and Geometric example: [2, 6, 18, 54]. Negative numbers may be entered as parameters,
0 will not be entered, and no array will contain all the same elements. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using namespace std;

string ArithGeo(int arr[], size_t arrLength) {
  
  // code goes here 
  size_t ind{arrLength-1};
  double temp{};

  temp = arr[ind] / static_cast<double>(arr[ind-1]); 
  while(--ind >= 1) {
    if (temp != arr[ind] / static_cast<double>(arr[ind-1])) {ind = arrLength-1; break;}
    temp = arr[ind] / static_cast<double>(arr[ind-1]);
  } 
  if (ind == arrLength-1) {temp = arr[ind] - arr[ind-1];}
    else {return "Geometric";}
  while(--ind >= 1) {
    if (temp != arr[ind] - arr[ind-1]) {ind = arrLength-1; break;}
    temp = arr[ind] - arr[ind-1];
  }
  if (ind != arrLength-1) {return "Arithmetic";}
  return "-1";

}

int main(void) { 
   
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArithGeo(A, arrLength);
  return 0;
    
}