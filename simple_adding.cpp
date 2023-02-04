/*
Simple Adding

Have the function SimpleAdding(num) add up all the numbers from 1 to num. For example:
if the input is 4 then your program should return 10 because 1 + 2 + 3 + 4 = 10.
For the test cases, the parameter num will be any number from 1 to 1000. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
using namespace std;

int SimpleAdding(int num) {

  // code goes here
  int sum{};
  for (;num>0; num--) {
    sum += num;
  }
  return sum;

}

int main(void) { 
   
  // keep this function call here
  cout << SimpleAdding(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}