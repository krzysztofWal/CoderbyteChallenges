/*
Rectangle Area
#geometry #array 

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

double RectangleArea(std::string strArr[], int arrLength) {
  // code goes here

  // array for storing all points coordinates
  std::array<double,8> pntArr;
  // array for storing distances between each points (sides + diagonals)
  std::array<double,6> lenArr; 
  size_t sb{};
  // put coordinates in pntArr
  for (size_t i{}; i < arrLength; i++) {
    // find space postion -> coordinates given as "(x y)"
    sb = strArr[i].find(" ");
    // extract numbers and put it in pntArr [x1 y1 x2 y2 x3 y3 x4 y4]
    pntArr.at(2*i) = std::stoi(strArr[i].substr(1,sb-1));
    pntArr.at(2*i+1) = std::stoi(strArr[i].substr(sb+1,strArr[i].length()-1));
  }
  // calculate distance between all points
  sb = 0;
  for (size_t i{}; i < 4; i++) {
    for (size_t j{i+1}; j < 4; j++) {
      lenArr[sb++] = std::sqrt(std::pow(pntArr.at(2*j)-pntArr.at(2*i),2) + std::pow(pntArr.at(2*j+1)-pntArr.at(2*i+1),2));
    }
  }
  // sort the distances between points
  // first two values are shorter sides, next two values are longer sides
  // and the two last (the longest) are the diagonals
  std::sort(lenArr.begin(),lenArr.end()); 
  // multiply the lengths of the sides
  return lenArr.at(2)*lenArr.at(0);
}

int main(void) { 
  // keep this function call here
  // std::string A[] = coderbyteInternalStdinFunction(stdin);
  std::string A[] = {"(1 -2)", "(3 -2)", "(1 3)", "(3 3)"};
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << RectangleArea(A, arrLength);
  return 0;
}

// std::cout << "sqrt( (" << pntArr.at(2*j) << " - " << pntArr.at(2*i) << " )^2 + ("
//           << pntArr.at(2*j+1) << " - " << pntArr.at(2*i+1) << " )^2 ) = " 
//           << lenArr.at(sb-1) << std::endl;
// for (const auto &el : pntArr) {std::cout << el << " ";} std::cout << "\n";
// for (const auto &el : lenArr) {std::cout << el << " ";} std::cout << "\n";