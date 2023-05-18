#ifndef __DUMMY_IN_H__
#define __DUMMY_IN_H__

#ifdef CODERBYTE_CHALLENGES_SRC_CPP_FLAG

/* Cpp implementation*/

#include <string>

extern "C" {
    #include "stdio.h"
}

std::string coderbyteInternalStdinFunction(FILE * dummy_ptr);

#else
/* c implementation */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/* the memory block pointed to by return char* should be freed */
char * coderbyteInternalStdinFunction(FILE * dummy_ptr);

/* use realloc to allocate memory dynamically  */
bool push(char *arr, uint32_t index, char value, uint32_t *size, uint32_t *capacity);


#endif // CODERBYTE_CHALLENGES_SRC_CPP_FLAG

#endif // __DUMMY_IN_H__