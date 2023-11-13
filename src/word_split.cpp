/*
Word Split
#hashmap #dynamic #array #search 

Have the function WordSplit(strArr) read the array of strings stored in strArr, which
will contain 2 elements: the first element will be a sequence of characters, and
the second element will be a long string of comma-separated words, in alphabetical
order, that represents a dictionary of some arbitrary length. For example: strArr
can be: ["hellocat", "apple,bat,cat,goodbye,hello,yellow,why"]. Your goal is to determine
if the first element in the input can be split into two words, where both words exist
in the dictionary that is provided in the second input. In this example, the first
element can be split into two words: hello and cat because both of those words are
in the dictionary.

Your program should return the two words that exist in the dictionary separated by
a comma. So for the example above, your program should return hello,cat. There will
only be one correct way to split the first element of characters into two words.
If there is no way to split string into two words that exist in the dictionary, return
the string not possible. The first element itself will never exist in the dictionary
as a real word. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string_view> GetSet(const std::string_view &sv) {
  
  char separator{','};
  std::unordered_set<std::string_view> tmpSet;
  int currentPostion{}, previousPosition{-1};

  // assuming that there are no trailing and leading spaces in the list of
  // words

  // find the first occurrence of separator
  currentPostion = sv.find(separator);

  // until we have reached the end of the string
  while (currentPostion < std::string::npos) { 
    // add the word to the set
    tmpSet.insert(sv.substr(previousPosition+1, currentPostion-previousPosition-1));
    previousPosition = currentPostion;
    currentPostion = sv.find(separator, previousPosition+1);
  }

  // add the last entry (or the first if there is only one)
  tmpSet.insert(sv.substr(previousPosition+1, sv.length()-1));
  
  return tmpSet;
}

std::string WordSplit(std::string strArr[], int arrLength) {
  // code goes here
  std::string_view fView = strArr[0];
  std::string_view sView = strArr[1];
  //create an unordered set of words from the second string
  std::unordered_set<std::string_view> words = GetSet(sView);

  // for every character in the first string
  for (size_t i{}; i < fView.length() - 1; i++) {
    // if you can find the words created by reading the first string
    // from 0 to i-th character and from i+1 to the last character
    // return those two words
    if( words.find(fView.substr(0, i+1)) != words.end() &&
          words.find(fView.substr(i+1, fView.length()-i-1)) != words.end() ) {
        return (strArr[0].substr(0,i+1) + "," + strArr[0].substr(i+1,fView.length()-i-1));
    }
  }
  
  return "not possible";
}

#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests
int main(void) { 
  // keep this function call here
  // string A[] = coderbyteInternalStdinFunction(stdin);
  std::string A[] = {"helloworld", "hello,group,mope,tope,world"};
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << WordSplit(A, arrLength);
  return 0;
} 
#endif