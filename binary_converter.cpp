/*
Binary Converter

Have the function BinaryConverter(str) return the decimal form of the binary value.
For example: if 101 is passed return 5, or if 1000 is passed return 8.

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>

std::string BinaryConverter(const std::string &str) {
  // code goes here  
  return std::to_string(std::stoul(str,nullptr,2));
}

int main(void) { 
   
  // keep this function call here
  std::cout << BinaryConverter(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}