/*
Moving Median
#data science #array #search 

Have the function MovingMedian(arr) read the array of numbers stored in arr which
will contain a sliding window size, N, as the first element in the array and the
rest will be a list of numbers. Your program should return the Moving Median for
each element based on the element and its N-1 predecessors, where N is the sliding
window size. The final output should be a string with the moving median corresponding
to each entry in the original array separated by commas.
 
Note that for the first few elements (until the window size is reached), 
the median is computed on a smaller number of entries. For example: 
if arr is [3, 1, 3, 5, 10, 6, 4, 3, 1] then your program should output 
"1,2,3,5,6,6,4,3" 

Optimal: o(n), achieved: o(n)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define FLOAT_PREC 1

std::string MovingMedian(int arr[], int arrLength) {
  
    // code goes here
    std::string tmp{};
    int N{ *arr }; // window size
    int mdl{}; // index of middle element (or 'right middle' when even number of elements)
    int end_my{}; // index of last used element + 1 (offset for n_th element)
    try {
        int* arr_cp = new int[N];
        for (auto i{ 0 }; i < N; i++) { arr_cp[i] = arr[i+1]; } // populate array with N first elements
        for (auto i{ 1 }; i < arrLength; i++) {
            // get current median window, when window has constant number of elements and 'moves' along arr elements
            if (i > N) {for (size_t j{ 0 }; j < N; j++) {arr_cp[j] = arr[i - N + 1 + j]; } }
            
            end_my = ((i > N) ? N : i);
            mdl = static_cast<int>(end_my/2); // calculate nth_element's position
            std::nth_element(arr_cp, arr_cp + mdl, arr_cp + end_my);  // set proper nth element

            // if nth_element is in the middle
            if (end_my % 2 != 0) { 
                tmp += std::to_string(arr_cp[mdl]);
            } else {
             // if nth_element not in the middle, take nth and nth-1 and calculate mean
                std::nth_element(arr_cp, arr_cp + mdl - 1, arr_cp + end_my); // get element before tmp_nr
             //   printArray<int>(arr_cp, N);
                if ((arr_cp[mdl] + arr_cp[mdl - 1]) % 2 == 0) { // when mean is an integer
                    tmp += std::to_string((arr_cp[mdl] + arr_cp[mdl-1]) / 2);
                } else { // when mean is floting point
                    tmp += std::to_string((arr_cp[mdl] + *(arr_cp + mdl)) / 2.0);
                    tmp.resize(tmp.length() - 6 + FLOAT_PREC); // given default floating point sprint precision == 6
                }
            }
            tmp += ",";
        }

        // free allocated memory
        delete[] arr_cp;
        arr_cp = nullptr;

        tmp.pop_back(); // remove last comma
        return tmp;
    }
    catch (std::exception& ex) { std::cout << ex.what() << std::endl; return ""; } 
}

int main(void) { 
  // keep this function call here
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  std::cout << MovingMedian(A, arrLength);
  return 0;
}