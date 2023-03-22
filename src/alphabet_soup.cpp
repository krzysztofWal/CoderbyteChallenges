/*
Alphabet Soup
#sort #string manipulation 

Have the function AlphabetSoup(str) take the str string parameter being passed and
return the string with the letters in alphabetical order (ie. hello becomes ehllo).
Assume numbers and punctuation symbols will not be included in the string. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>

std::string AlphabetSoup(std::string str) {
  // code goes here 
  /*
  std::string tmp;
  std::multimap<int,int> m; //char is the key, index is the value
  bool *u_pos = new(std::nothrow) bool[str.length()]; // keep track of uppercase
  if ( u_pos!=nullptr) {
    for (auto i{0}; i<str.length(); i++) {
      if (static_cast<int>(str.at(i)) < 97) {u_pos[i] = 1; m.insert(std::pair<int,int>(str.at(i)+32,i));}
        else {u_pos[i] = 0;  m.insert(std::pair<int,int>(str.at(i),i));}
    }
    for (auto it{m.begin()};it!=m.end();it++){
      tmp += static_cast<char>((u_pos[it->second]) ? (it->first)-32 : it->first);
    }
    
    delete[] u_pos;
    u_pos = nullptr;

    return tmp;
  } else {
    return "Error allocating";
  }
  */
  // well if there are no upper cases
  std::sort(str.begin(),str.end());
  return str;
}

int main(void) { 
  // keep this function call here
  std::cout << AlphabetSoup(coderbyteInternalStdinFunction(stdin));
  return 0;
}