/*
Division Stringified

Have the function DivisionStringified(num1,num2) take both parameters being passed,
divide num1 by num2, and return the result as a string with properly formatted commas.
If an answer is only 3 digits long, return the number with no commas (ie. 2 / 3 should
output "1"). For example: if num1 is 123456789 and num2 is 10000 the output should
be "12,346". 

Optimal: o(-), achieved: o(-) - not calculated
*/
#include <iostream>
#include <string>
#include <cmath>

std::string DivisionStringified(int num1, int num2) {
  // code goes here
  int res = round(num1/static_cast<double>(num2));
  int cnt{1}, diff{10};
  std::string str;

  while (diff > 9) {
    diff = res / pow(10,cnt++);
  }

  while (cnt > 1) {
    if (cnt % 3 == 0) str+= ",";
    diff = res / pow(10,cnt-1);
    res -= diff * pow(10,cnt-1);
    str +=  to_string(diff);
    cnt--;
  }
  str +=  to_string(res);

  return str;
}

int main(void) { 
  // keep this function call here
  cout << DivisionStringified(coderbyteInternalStdinFunction(stdin));
  return 0;
}