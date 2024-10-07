#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "dummy_in.h"

#define STRING_DEFAULT_SIZE 50 // set to lower if you want to test reallocation of memory
// #define DEBUG_DUMMY_IN_C // just so I can see with my own idiot eyes what is happening

/* the memory block pointed to by return char* should be freed */
char* coderbyteInternalStdinFunction(FILE * stdin_ptr) {

    // string array with starting size
    // lets allocate some memory using a varaible defined in the preprocessor 
    char *strArr = (char*)malloc(STRING_DEFAULT_SIZE * sizeof(char));
    
    // if allocation failed just return string "error"
    if(!strArr) {printf("Error allocating memory\n");return "error";}

    // just for the sake of user information
    printf("Input from the console: \n");

    // how many characters we have in the buffer plus one
    uint32_t cnt = 1;
    // how many times we realocated the memory
    uint32_t overflow_cnt = 0;
    // get the next character from the input and put it in the buffer
    // returns true if the character is not a newline or EOF (see getc_wrap() function)
    while (getc_wrap(stdin_ptr, strArr + cnt - 1)) {
        // we got cnt-th character
        #ifdef DEBUG_DUMMY_IN_C 
            printf("[%d, %c]", cnt, *(strArr + cnt - 1));
        #endif
        // if this is the last possible character to put in the buffer
        // realocate memory - add a block of size STRING_DEFAULT_SIZE
        //
        // if for example first allocation is 10 characters, and we reach cnt == 10, that means we filled 10 slots in the buffer already
        // (we increase counter after cnt-th character was read)
        // (1 + overflow_cnt) - how many times we allocated the memory 
        //                      or in other words how many times we reallocated the memory plus one


        if (cnt == (1 + overflow_cnt) * STRING_DEFAULT_SIZE) {
            #ifdef DEBUG_DUMMY_IN_C 
                printf("\nNeeded to realocate stuff\n");
            #endif
            // when reallocating a block of emmory we each time add the size of STRING_DEFAULT_SIZE to the size
            // of the previous buffer - so when for example the overflow_cnt is 1 that means we have a block of size 2 * STRING_DEFAULT_SIZE.
            //                          Thus when we reallocate we need the size of 3 * STRING_DEFAULT_SIZE.
            //                          which translates to (2 + overflow_cnt) * STRING_DEFAULT_SIZE (as overflow_cnt is 1 as now)
            // IMPORTANT: we also increase overflow_cnt after the operation
            strArr = (char*)realloc((void*)strArr, (2 + overflow_cnt++) * STRING_DEFAULT_SIZE * sizeof(char));
            // if reallocation failed just return string "error"
            if(!strArr) {printf("Error allocating memory\n");return "error";}
        }
        // increment cnt
        cnt++;
        // the next character is cnt-th
    }

    #ifdef DEBUG_DUMMY_IN_C 
        printf("overflow_cnt=%d", overflow_cnt);
        for(int i=0; i<(1 + overflow_cnt) * STRING_DEFAULT_SIZE; i++) {
            printf("\n%d, %c", i, strArr[i]);
        }
        printf("\n");
    #endif

    // make the buffer the size of the final string - is it strictly necessary as the string ends with '\0' 
    //                                                and the buffer which strArr points to is just bigger size than the string
    //                                                (the memory not being lost?) - but whatever
    strArr = (char*)realloc((void*)strArr, cnt-1);
    if(!strArr) {printf("\nError reallocating memory\n");return "error";}

    // to make sure that this function works properly and that the string is properly read.
    // In case I want to call it a long time after I wrote it and I want to just call it
    printf("Check in coderbyteInternalStdinFunction(): '%s'\n", strArr);
    return strArr;
    
}

/* reads a character from provided input (like stdin) and puts it in the adress pointed by the destination char pointer */
bool getc_wrap(FILE* stdin_ptr, char* destination) {
    // get the charachter from the stdin_ptr
    char c = getc(stdin_ptr);
    // if the character is not EOF and not '\n' put it in the destination
    if (c != EOF && c != '\n' ) {
        *destination = c;
        return true;
    } else {
    // else put '\0' in the destination and return false
        *destination = '\0';
        return false;
    }
}

bool push(char *arr, uint32_t index, char value, uint32_t *size, uint32_t *capacity) {
  	if (*size > * capacity) {
  		arr = (char *)realloc(arr, sizeof(arr) * 2);
		*capacity = sizeof(arr) * 2;
	}
	if (arr != NULL) {
		arr[index] = value;
    	*size = *size + 1;
		return true;
	} else {
		return false;
	}
}
