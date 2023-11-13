/*
Boggle Solver
#matrix #hashmap #dynamic

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

// return position of character separator in provided string
std::vector<size_t> GetIndex(const std::string_view &sv, char separator) {
  
  std::vector<size_t> tmpV;
  size_t pos{sv.find(separator)};
  
  while (pos != std::string::npos) {
    tmpV.push_back(pos);
    pos = sv.find(separator, tmpV.back() + 1);
  }
  
  // tmpV.push_back(sv.length());
  return tmpV;
}

// get words form string sv based on separator locations from vec
std::vector<std::string_view> GetWords(const std::string_view &sv, std::vector<size_t> &&vec) {

  vec.push_back(sv.length());
  std::vector<std::string_view> us{sv.substr(0, vec.at(0))};

  for (size_t i{1}; i < vec.size(); i++)
    us.emplace_back(sv.substr(vec.at(i - 1) + 2, vec.at(i) - vec.at(i - 1) - 2));
  return us;
}

std::vector<std::vector<char>> GetArr(const std::string_view &sv, std::vector<size_t> &&vec) {
  
  vec.push_back(sv.length());
  
  const size_t firstDim{vec.size()};
  const size_t secDim{vec.at(0)};

  size_t cnt{};
  std::vector<std::vector<char>> arrAsVec(firstDim, std::vector<char>(secDim, ' '));

  // fill first row
  for (size_t i{}; i < secDim; i++) {
    arrAsVec.at(0).at(i) = sv.at(i); 
  }
  // fill other rows
  for (size_t i{1}; i < firstDim; i++) {
    cnt = 0;
    for (size_t j{vec.at(i - 1) + 1}; j < vec.at(i); j++)
      arrAsVec.at(i).at(cnt++) = sv.at(j);
  }

  return arrAsVec;
}

bool DepthFirstSearch(const std::string_view &wordWeSeek, std::vector<std::vector<char>> &charMatrix,
                      long long i, long long j, size_t vecDimOne, size_t vecDimTwo, size_t howFarIntoTheWord){

  // when outside the bounds of the 2D matrix or the string is unachievable
  // in this sequence (because the character at position howFarIntoTheWord is wrong)
  if (i < 0 || j < 0 || i == vecDimOne || j == vecDimTwo || charMatrix.at(i).at(j) != wordWeSeek.at(howFarIntoTheWord)) {
    // there is no sense in getting 'lower' on the 'recursion tree'
    return false;
  }

  // check if all the characters in the wordWeSeek have been found
  if (howFarIntoTheWord == wordWeSeek.length() - 1) {
    // if we got this far into the 'recursive' tree that means that the word
    // is found (we reached the bottom), otherwise, we would 'fall' out of this branch before
    return true;
  }

  // take character with coordinates (i,j) and save it
  char character = charMatrix.at(i).at(j);

  // change charMatrix(i,j) to '-' - make it 'used'
  // when the function is popped of the stack and 'moves backwards' in this branch
  // the tiles become 'unused'
  charMatrix.at(i).at(j) = '-';

  // branch the search into all neighbouring tiles in search of the next
  // character in wordWeSeek
  // whether they exist will be handled by the called instance of the function
  bool exp = DepthFirstSearch(wordWeSeek, charMatrix, i - 1, j - 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i - 1, j, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i - 1, j + 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i, j + 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i + 1, j + 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i + 1, j, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i + 1, j - 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1) ||
             DepthFirstSearch(wordWeSeek, charMatrix, i, j - 1, vecDimOne, vecDimTwo, howFarIntoTheWord + 1);

  // return the 'used' character into position
  charMatrix.at(i).at(j) = character;

  return exp;
}

std::string BoggleSolver(std::string strArr[], int arrLength)
{

  std::string notFoundWords{};

  // input parameters as string views
  std::string_view fView = strArr[0]; // words
  std::string_view sView = strArr[1]; // matrix

  char separator {','};

  // count found words
  size_t wordCnt{};

  bool wordFound{};

  // get vector of words
  auto words = GetWords(fView, GetIndex(fView, separator)); // std::vector<std::string_view>
  // get letter 2-D layer as vector of vectors
  auto arrAsVec = GetArr(sView, GetIndex(sView, separator)); // std::vector<std::vector<char>>

  // iterate over words
  for (const auto &word : words) {
    wordFound = false;
    // iterate over 2-D vector of chars, i-> first dimension, j-> second dimention
    for (size_t i{}; i < arrAsVec.size() && !wordFound; i++) {
      for (size_t j{}; j < arrAsVec.at(0).size() && !wordFound; j++)
      { // iterate every element in the array
        // for each element of the 2-D matrix  do Depth First Search
        // it returns true a word is found
        if (DepthFirstSearch(word, arrAsVec, i, j, arrAsVec.size(), arrAsVec.at(0).size(), 0))
        {
          // update the counter of found words if the word is found and break from the loop
          wordCnt++;
          wordFound = true;
        }
      }
    }
    // if the word was not found add it to the string onf not-found words
    if (!wordFound) {
      notFoundWords += word;
      notFoundWords += ",";
    }
  }

  if (words.size() == wordCnt) {
    return "true";
  } else {
    // remove "," from the end of notFoundWords
    notFoundWords.pop_back();
    // return concatenated words that have not been found
    return notFoundWords;
  }
}


#ifndef CODERBYTE_CHALLENGES_TEST_CPP_FLAG // for use with google tests
int main(void) {
  // keep this function call here
  // std::string A[] = coderbyteInternalStdinFunction(stdin);
  std::string A[] = {"bst, heap, tree", "bsh,tee,arh"};
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << BoggleSolver(A, arrLength);
  return 0;
}
#endif

// std::cout << "DFS :" << ind << " :" << v.at(i).at(j) << " i:" << i << " j:" << j << std::endl;
// std::cout << sv << std::endl;
// std::cout << "Found " << sv << std::endl;
// size_t i{};
// for (const auto &el : arrAsVec) {
//   for (const auto &c : el) std::cout << i++ << ":" << c << " ";
//   std::cout << std::endl;
// }