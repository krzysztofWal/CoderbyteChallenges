#include <iostream>
#include <string>

#include "dummy_in.h"

std::string coderbyteInternalStdinFunction(FILE * dummy_ptr) {
    std::string temp;
    std::cout << "Input from the console (takes a line): " << std::endl;
    std::getline(std::cin, temp);
    // assume the string is in doubl quotes
    std::cout << "Debug in coderbyteInternalStdinFunction(): given string (without quotes): \"" 
       << temp  << "\"" << std::endl;
    return temp;
}