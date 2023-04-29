/*
Third greatest
#array #sort #search 

Have the function ThirdGreatest(strArr) take the array of strings stored in strArr
and return the third largest word within it. So for example: if strArr is ["hello",
"world", "before", "all"] your output should be world because "before" is 6 letters
long, and "hello" and "world" are both 5, but the output should be world because
it appeared as the last 5 letter word in the array. If strArr was ["hello", "world",
"after", "all"] the output should be after because the first three words are all
5 letters long, so return the last one. The array will have at least three strings
and each string will only contain letters. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <vector>

void PutToVec(size_t opt, std::vector<std::pair<size_t,int>> &v, std::pair<size_t,int> &&p) {
  switch (opt) {
    case 0:
      v.at(2) = v.at(1);
      v.at(1) = v.at(0);
      break;
    case 1:
      v.at(2) = v.at(1);
      break;
    case 2:
      break;
  }
  v.at(opt) = p;
}

std::string ThirdGreatest(std:: string strArr[], size_t const arrLength) {
  // code goes here
  std::vector<std::pair<size_t,int>> max(3);
  std::vector<size_t> len(arrLength);
  size_t cnt{};

  for (size_t i{}; i < arrLength; i++) {
    len.at(i) = strArr[i].length();
  }

    for (size_t i{0}; i < arrLength; i++) {
    if (len.at(i) > max.at(0).second) {
      PutToVec(0,max,std::pair<size_t,int>(i,len.at(i)));
    } else if (len.at(i) <= max.at(0).second && len.at(i) > max.at(1).second) {
      PutToVec(1,max,std::pair<size_t,int>(i,len.at(i)));
    } else if (len.at(i) <= max.at(1).second && len.at(i) >= max.at(2).second) {
      PutToVec(2,max,std::pair<size_t,int>(i,len.at(i)));
    }
    // std::cout << strArr[max.at(0).first] << " " <<
    //           strArr[max.at(1).first] << " " <<
    //           strArr[max.at(2).first] << std::endl; 
  }

  return strArr[max.at(2).first];
}

int main(void) { 
  // keep this function call here
  std::string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << ThirdGreatest(A, arrLength);
  return 0;
}