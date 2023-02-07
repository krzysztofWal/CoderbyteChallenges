/*
Multiple Brackets
#stack #search 


Have the function MultipleBrackets(str) take the str parameter being passed and return
1 #ofBrackets if the brackets are correctly matched and each one is accounted for.
Otherwise return 0. For example: if str is "(hello [world])(!)", then the output
should be 1 3 because all the brackets are matched and there are 3 pairs of brackets,
but if str is "((hello [world])" the the output should be 0 because the brackets
do not correctly match up. Only "(", ")", "[", and "]" will be used as brackets.
If str contains no brackets return 1

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>

std::string MultipleBrackets(std::string str) {
  // code goes here
  int open_c{}, open_s{}, cnt{};

  for (const char &el : str) {
    switch (el) {
      case '(':
        open_c++;
        cnt++;
        break;
      case '[':
        open_s++;
        cnt++;
        break;
      case ')':
        open_c--;
        break;
      case ']':
        open_s--;
        break;
      default:
        break;
    }
    if (open_s < 0 || open_c < 0) return "0";
  }
  if (open_c != 0 || open_s != 0) return "0";

  return "1 " + std::to_string(cnt);
}

int main(void) { 
  // keep this function call here
  std::cout << MultipleBrackets(coderbyteInternalStdinFunction(stdin));
  return 0;
}