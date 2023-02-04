/*
Counting Minutes I

Have the function CountingMinutesI(str) take the str parameter being passed which
will be two times (each properly formatted with a colon and am or pm) separated by
a hyphen and return the total number of minutes between the two times. The time will
be in a 12 hour clock format. For example: if str is 9:00am-10:00am then the output
should be 60. If str is 1:00pm-11:00am the output should be 1320. 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
#include <array>
#include <string_view>

int CountingMinutesI(std::string str) {
  size_t pos{}, pos_{}, ind{};
  std::array<std::string,4> arr;
  int diff{};

  while(pos < str.length()) {
    if (str.at(pos) == ':' || str.at(pos) == '-' || pos == str.length()-1) {
      arr.at(ind++) = str.substr(pos_,pos-pos_);
      pos_ = pos+1;
    }
    pos++;
  }
  diff = (std::stoi(arr.at(2)) + ((arr.at(3).at(2)=='p') ? 12 : 0)) * 60 +
          std::stoi(arr.at(3)) - 
          (std::stoi(arr.at(0)) + ((arr.at(1).at(2)=='p') ? 12 : 0)) * 60 -
          std::stoi(arr.at(1));
  return (diff < 0) ? (24 * 60 + diff) : diff;
}

int main(void) { 
  // keep this function call here
  std::cout << CountingMinutesI(coderbyteInternalStdinFunction(stdin));
  return 0;
}