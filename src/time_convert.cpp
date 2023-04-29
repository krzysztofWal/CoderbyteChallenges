/*
Time Convert
#string manipulation 

Have the function TimeConvert(num) take the num parameter being passed and return
the number of hours and minutes the parameter converts to (ie. if num = 63 then the
output should be 1:3). Separate the number of hours and minutes with a colon

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
std::string TimeConvert(int num) {
  // code goes here  
  std::string tmp{};
  tmp = std::to_string(num/60) + ":" + std::to_string(num%60); 
  return tmp;
}

int main(void) { 
  // keep this function call here
  std::cout << TimeConvert(coderbyteInternalStdinFunction(stdin));
  return 0;
}