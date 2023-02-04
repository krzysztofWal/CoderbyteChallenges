/*
Boggle Solver

Have the function BoggleSolver(strArr) read the array of strings stored in strArr,
which will contain 2 elements: the first element will represent a 4x4 matrix of letters,
and the second element will be a long string of comma-separated words each at least
3 letters long, in alphabetical order, that represents a dictionary of some arbitrary
length. For example: strArr can be: ["rbfg, ukop, fgub, mnry", "bog,bop,gup,fur,ruk"].
Your goal is to determine if all the comma separated words as the second parameter
exist in the 4x4 matrix of letters. For this example, the matrix looks like the following:


Optimal: o(n^2), achieved: o(n^2)
*/

#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

std::vector<size_t> GetIndex(const std::string_view& v) {
  std::vector<size_t> tmpV;
  size_t pos{ v.find(",") };
  while (pos != std::string::npos) {
    tmpV.push_back(pos);
    pos = v.find(",", tmpV.back() + 1);
  }
  tmpV.push_back(v.length());
  return tmpV;
}

std::vector<std::string_view> GetWords(const std::string_view& sv, std::vector<size_t>&& vec) {
  std::vector<std::string_view> us{ sv.substr(0,vec.at(0)) };
  for (size_t i{ 1 }; i < vec.size(); i++) us.emplace_back(sv.substr(vec.at(i - 1) + 1, vec.at(i) - vec.at(i - 1) - 1));
  return us;
}

std::vector<std::vector<char>> GetArr(const std::string& s, const std::vector<size_t>& vec) {
  const size_t firstDim{ vec.size() };
  const size_t secDim{ vec.at(0) };
  size_t cnt{};
  std::vector<std::vector<char>> arrAsVec(firstDim, std::vector<char>(secDim, ' '));
  for (size_t i{}; i < secDim; i++) arrAsVec.at(0).at(i) = s.at(i); // fill first row
  for (size_t i{ 1 }; i < firstDim; i++) { // fill other rows
    cnt = 0;
    for (size_t j{ vec.at(i - 1) + 2 }; j < vec.at(i); j++) arrAsVec.at(i).at(cnt++) = s.at(j);
  }
  return arrAsVec;
}

bool DepthFirstSearch(const std::string_view& sv, std::vector<std::vector<char>>& v,
  long long i, long long j, size_t n, size_t m, size_t ind) {
  if (i < 0 || j < 0 || i == n || j == m ||
      v.at(i).at(j) != sv.at(ind)) return false; // when outside bounds or
  // the string is unachievable in this sequence

  if (ind == sv.length() - 1) return true;

  char temp = v.at(i).at(j);
  v.at(i).at(j) = '-'; // 'keeping track' of 'used' tiles
  // when the function is popped of the
  // stack and 'moves backwards' in the sequence
  // the tiles become 'unused'

  bool exp =  DepthFirstSearch(sv, v, i - 1, j - 1, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i - 1, j, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i - 1, j + 1, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i, j + 1, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i + 1, j + 1, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i + 1, j, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i + 1, j - 1, n, m, ind + 1) ||
              DepthFirstSearch(sv, v, i, j - 1, n, m, ind + 1);
  v.at(i).at(j) = temp;
  return exp;
}

std::string BoggleSolver(std::string strArr[], int arrLength) {
  std::string_view fView = strArr[0];
  std::string_view sView = strArr[1];
  size_t wordCnt{};
  std::string tmp;
  bool breakFlag{};
  auto words = GetWords(sView, GetIndex(sView)); // std::vector<std::string_view>
  auto arrAsVec = GetArr(strArr[0], GetIndex(fView)); // std::vector<std::vector<char>> 

  for (const auto& sv : words) { // iterate over dictionary, result is a string
    breakFlag = false;
    for (size_t i{}; i < arrAsVec.size() && !breakFlag; i++) {
      for (size_t j{}; j < arrAsVec.at(0).size() && !breakFlag; j++) { // iterate every element in the array
        if (DepthFirstSearch(sv, arrAsVec, i, j, arrAsVec.size(), arrAsVec.at(0).size(), 0)) {
            wordCnt++;
            breakFlag = true;
        }
      }
    }
    if (!breakFlag) { tmp += sv; tmp += ","; }
  }
  if (words.size() == wordCnt) {
    return "true";
  } else {
    tmp.pop_back();
    return tmp;
  }
}

int main(void) { 
  // keep this function call here
  std::string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << BoggleSolver(A, arrLength);
  return 0;
}

// std::cout << "DFS :" << ind << " :" << v.at(i).at(j) << " i:" << i << " j:" << j << std::endl;
// std::cout << sv << std::endl;
// std::cout << "Found " << sv << std::endl;
// size_t i{};
// for (const auto &el : arrAsVec) {
//   for (const auto &c : el) std::cout << i++ << ":" << c << " ";
//   std::cout << std::endl;
// }