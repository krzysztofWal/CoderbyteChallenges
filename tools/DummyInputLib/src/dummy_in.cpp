#include <iostream>
#include <string>

#include "dummy_in.h"

std::string coderbyteInternalStdinFunction(FILE * dummy_ptr) {
    std::string temp;
    std::cin >> temp;
    return temp;
}