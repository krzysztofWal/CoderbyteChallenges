/*
Look Say Sequence

Have the function LookSaySequence(num) take the num parameter being passed and return
the next number in the sequence according to the following rule: to generate the
next number in a sequence read off the digits of the given number, counting the number
of digits in groups of the same digit. For example, the sequence beginning with 1
would be: 1, 11, 21, 1211, ... The 11 comes from there being "one 1" before it and
the 21 comes from there being "two 1's" before it. So your program should return
the next number in the sequence given num. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string LookSaySequence(int num) {
  // code goes here  
  std::string sNum = std::to_string(num);
  std::string tmp;
  size_t i{}, cnt{1};
  char prev = sNum.at(i++);
  while (i < sNum.length() ) {
    if (sNum.at(i) != prev) {
      tmp += std::to_string(cnt);
      tmp.push_back(prev);
      cnt = 0;
    }
    cnt++;
    prev = sNum.at(i++);
  }
  tmp += std::to_string(cnt);
  tmp.push_back(sNum.back());

  return tmp;
}

int main(void) { 
  // keep this function call here
  std::cout << LookSaySequence(coderbyteInternalStdinFunction(stdin));
  return 0;
}