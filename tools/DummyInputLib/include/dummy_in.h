#ifndef __DUMMY_IN_H__
#define __DUMMY_IN_H__

#ifdef CODERBYTE_CHALLENGES_SRC_CPP_FLAG

/* Cpp implementation*/

#include <string>

extern "C" {
    #include "stdio.h"
}

std::string coderbyteInternalStdinFunction(FILE * dummy_ptr);

#else // CODERBYTE_CHALLENGES_SRC_CPP_FLAG
/* c implementation */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* the memory block pointed to by return char* should be freed */
char * coderbyteInternalStdinFunction(FILE * stdin_ptr);

/* 1) put char from stdin_ptr in *destination if not EOF and return true
   2) if EOF or '\n' put '\0' to *destination and return false */
bool getc_wrap(FILE* stdin_ptr, char* destination);


#endif // CODERBYTE_CHALLENGES_SRC_CPP_FLAG

#endif // __DUMMY_IN_H__