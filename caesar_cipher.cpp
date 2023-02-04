/*
Caesar Cipher

Have the function CaesarCipher(str,num) take the str parameter and perform a Caesar
Cipher shift on it using the num parameter as the shifting number. A Caesar Cipher
works by shifting each letter in the string N places in the alphabet (in this case
N will be num). Punctuation, spaces, and capitalization should remain intact. For
example if the string is "Caesar Cipher" and num is 2 the output should be "Ecguct
Ekrjgt". 

Optimal: o(-), achieved: o(-) - not calculated
*/

#include <iostream>
#include <string>
using namespace std;

char shift_char(char s, int st, int en, int num) {
  if (s + num > en) {return static_cast<char>(st+s+num-en-1);}
        else {return static_cast<char>(num+s);}
}

string CaesarCipher(string str, int num) {
  
  char s;
  // code goes here  
  for (int i{0}; i<str.length(); i++) {
    s = str.at(i);
    if (s <= 122 && s >= 97) { //lowercase
      str.at(i) = shift_char(s,97,122,num);
     } else if (s <= 90 && s >= 65) {
      str.at(i) = shift_char(s,65,90,num);
     }
  }
  return str;

}

int main(void) { 
   
  // keep this function call here
  cout << CaesarCipher(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}