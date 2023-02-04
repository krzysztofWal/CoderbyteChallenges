/*
Powers Of Two

Have the function PowersofTwo(num) take the num parameter being passed which will
be an integer and return the string true if it's a power of two. If it's not return
the string false. For example if the input is 16 then your program should return
the string true but if the input is 22 then the output should be the string false.


Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const char * PowersofTwo(int num) {
  
  // code goes here
  while (num > 1) {
    if (num % 2 != 0) return "false";
    num = num/2;
  }
  return "true";

}

int main(void) { 
   
  // keep this function call here
  cout << PowersofTwo(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}