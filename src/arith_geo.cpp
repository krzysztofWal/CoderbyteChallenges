/*
Arith Geo II
#sequences #array 

Have the function ArithGeoII(arr) take the array of numbers stored in arr and return
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

const char * ArithGeoII(int arr[], const size_t arrLength) {
  // code goes here  
  size_t ind{arrLength-1};
  int  tmp_diff{};
  double tmp_ratio{};
  bool canBeArith{true}, canBeGeo{true};

  // calculate arr[end]-arr[end-1] and arr[end]/arr[end-1]
  int previous_diff{ arr[ind] - arr[ind - 1] };
  double previous_ratio{ arr[ind] / static_cast<double>(arr[ind -1 ])};
  ind--; // shift index to previous to last

  // starting at the previous to last element
  // if there is still a chance of it being either
  while (ind > 0 && (canBeArith || canBeGeo) ) {
    // calculate the difference and the ratio
    tmp_diff = arr[ind] - arr[ind -1];
    tmp_ratio = arr[ind] / static_cast<double>(arr[ind - 1]);
    // if there is no more chance for it to be arithmetic set proper flag
    if (tmp_diff != previous_diff) canBeArith = false;
    // if there is no more chance for it to be geometric set proper flag
    if (tmp_ratio != previous_ratio) canBeGeo = false;

    previous_diff = tmp_diff;
    previous_ratio = tmp_ratio;

    ind--;
  }

  // as all of the elements cannot be the same if it is not arithmetic
  // it is either geometric or neither
  if (canBeArith) {
    return "Arithmetic";
  } else if (canBeGeo) {
    return "Geometric";
  } else {
    return "-1";
  }
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests
int main(void) { 
  // keep this function call here
  // int A[] = coderbyteInternalStdinFunction(stdin);
  int A[] = {11, 13, 15, 17, 19};
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << ArithGeoII(A, arrLength);
  return 0;
}
#endif