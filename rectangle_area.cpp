/*
Rectangle Area

Have the function RectangleArea(strArr) take the array of strings stored in strArr,
which will only contain 4 elements and be in the form (x y) where x and y are both
integers, and return the area of the rectangle formed by the 4 points on a Cartesian
grid. The 4 elements will be in arbitrary order. For example: if strArr is ["(0 0)",
"(3 0)", "(0 2)", "(3 2)"] then your program should return 6 because the width of
the rectangle is 3 and the height is 2 and the area of a rectangle is equal to the
width * height

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <array>
using namespace std;

double RectangleArea(string strArr[], int arrLength) {
  // code goes here
  std::array<double,8> pntArr;
  std::array<double,6> lenArr; 
  size_t sb{};
  // put coordinates in pntArr
  for (size_t i{}; i < arrLength; i++) {
    sb = strArr[i].find(" ");
    pntArr[2*i] = std::stoi(strArr[i].substr(1,sb-1));
    pntArr[2*i+1] = std::stoi(strArr[i].substr(sb+1,strArr[i].length()-1));
  }
  // calculate distance between all points
  sb = 0;
  for (size_t i{}; i < 4; i++) {
    for (size_t j{i+1}; j < 4; j++) {
      lenArr[sb++] = std::sqrt(std::pow(pntArr.at(2*j)-pntArr.at(2*i),2) + std::pow(pntArr.at(2*j+1)-pntArr.at(2*i+1),2));
    }
  }
  // sort the distances between points and return first value multipled by second
  std::sort(lenArr.begin(),lenArr.end()); 
  return lenArr.at(2)*lenArr.at(0);

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << RectangleArea(A, arrLength);
  return 0;
    
}

      // std::cout << "sqrt( (" << pntArr.at(2*j) << " - " << pntArr.at(2*i) << " )^2 + ("
      //           << pntArr.at(2*j+1) << " - " << pntArr.at(2*i+1) << " )^2 ) = " 
                // << lenArr.at(sb-1) << std::endl;
  // for (const auto &el : pntArr) {std::cout << el << " ";} std::cout << "\n";
  // for (const auto &el : lenArr) {std::cout << el << " ";} std::cout << "\n";