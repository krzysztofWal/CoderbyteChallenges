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
#include <string>

const char * ArithGeoII(int arr[], const size_t arrLength) {
  // code goes here  
  size_t ind{arrLength-1};
  int  tmpDiffArith{};
  double tmpDiffGeo{};
  int diffArith{ arr[ind] - arr[ind - 1] };
  double diffGeo{ arr[ind] / static_cast<double>(arr[ind -1])};
  bool arithStop{}, geoStop{};

  while (--ind > 0 && (!arithStop || !geoStop)) {
    tmpDiffArith = arr[ind] - arr[ind -1];
    tmpDiffGeo = arr[ind] / static_cast<double>(arr[ind - 1]);
    if (tmpDiffArith != diffArith) arithStop = true;
    if (tmpDiffGeo != diffGeo) geoStop = true;
    diffGeo = tmpDiffGeo;
    diffArith = tmpDiffArith;
  }

  if (!arithStop) {
    return "Arithmetic";
  } else if (!geoStop) {
    return "Geometric";
  } else {
    return "-1";
  }
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << ArithGeoII(A, arrLength);
  return 0;
}