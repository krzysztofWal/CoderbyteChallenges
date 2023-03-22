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
using std::string, std::cout;

std::unordered_set<std::string_view> GetSet(const std::string_view &sv) {
  std::unordered_set<std::string_view> us;
  size_t pos{}, pos_{};

  pos = sv.find(",");
  us.insert(sv.substr(pos_,pos-pos_));
  pos_ = pos;
  pos = sv.find(",",pos_+1);
  while (pos < std::string::npos) { 
    us.insert(sv.substr(pos_+1,pos-pos_-1));
    pos_ = pos;
    pos = sv.find(",",pos_+1);
  }
  return us;
}

string WordSplit(string strArr[], int arrLength) {
  // code goes here
  std::string_view fView = strArr[0];
  std::string_view sView = strArr[1];
  std::unordered_set<std::string_view> words = GetSet(sView);

  for (size_t i{}; i < fView.length() - 1; i++) {
    if( words.find(fView.substr(0,i+1)) != words.end() &&
        words.find(fView.substr(i+1,fView.length()-i-1)) != words.end() ) {
        return (strArr[0].substr(0,i+1) + "," + strArr[0].substr(i+1,fView.length()-i-1));
    }
  }
  
  return "not possible";
}

int main(void) { 
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << WordSplit(A, arrLength);
  return 0;
}