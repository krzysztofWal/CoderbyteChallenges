#ifndef __DUMMY_IN_H__
#define __DUMMY_IN_H__

#include <string>

extern "C" {
    #include "stdio.h"
}

std::string coderbyteInternalStdinFunction(FILE * dummy_ptr);

#endif