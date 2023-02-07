/*
Find Intersection
#array #tree 

Have the function FindIntersection(strArr) read the array of strings stored in strArr
which will contain 2 elements: the first element will represent a list of comma-separated
numbers sorted in ascending order, the second element will represent a second list
of comma-separated numbers (also sorted). Your goal is to return a comma-separated
string containing the numbers that occur in elements of strArr in sorted order. If
there is no intersection, return the string false. 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define DEBUG 0

std::string FindIntersection(std::string strArr[], int arrLength) {
    // code goes here  
    std::string tmp_str{};
    std::vector<int> vec{};
    std::string str{};
    size_t pos{};
    size_t old_pos{};
    bool flag{ true };

    for (int i{}; i < arrLength; i++) {
        str = strArr[i];
        str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
        old_pos = 0; pos = 0; flag = true; //reset variables
        while (flag) {
            if (str.find(",", old_pos) != std::string::npos) {
                pos = str.find(",", old_pos);
            } else {
                pos = str.length();
                flag = false;
            }
            vec.emplace_back(std::stoi(str.substr(old_pos, pos - old_pos)));

            if (DEBUG) { std::cout << "old_pos :" << old_pos << " pos :" << pos << std::endl; }
            if (DEBUG) { std::cout << "str: '" + str + "' substr_m: '" + str.substr(old_pos, pos - old_pos) + "'" << std::endl; }
            
            old_pos = pos +1;
        }
    }

    std::sort(vec.begin(), vec.end());
    int previous{ vec.at(0) };
    
    for (size_t i{1}; i < vec.size();i++) { // extract duplicates
        if (DEBUG) { std::cout << "previous: "<< previous<< " vec.at: " << vec.at(i) << std::endl; }
        if (previous == vec.at(i)) { tmp_str += "," + std::to_string(vec.at(i)); };
        previous = vec.at(i);
    }
    if (tmp_str.empty()) {
      tmp_str = "false";
    } else {
      tmp_str.erase(tmp_str.begin(), tmp_str.begin()+1);
    }
    return tmp_str;
}

int main(void) { 
  // keep this function call here
  std::string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << FindIntersection(A, arrLength);
  return 0;
}