#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "dummy_in.h"

#define STRING_MAX_SIZE_MY_VAR 100

/* the memory block pointed to by return char* should be freed */
char* coderbyteInternalStdinFunction(FILE * dummy_ptr) {

    uint32_t size = 0;
	uint32_t capacity = 1;
	char* strArr = (char*)(malloc(capacity * sizeof(char))); 

    // check if memory was allocated
    if(strArr == NULL) { 
        printf("Error allocating memory");
        return "error"; 
    }

    char input[STRING_MAX_SIZE_MY_VAR];
    printf("Input from the console: \n");
    fgets(input, sizeof(input), stdin);

    // copy into the dynamic
    uint32_t i = 0;
    while(input[i] != '\0') {
        if(!push(strArr, i, input[i], &size, &capacity)) {
            printf("Error allocating memory");
            return "error"; 
        }
        i++;
    }
    // append '\0' on the end
    if(!push(strArr, i, '\0', &size, &capacity)) {
        printf("Error allocating memory");
        return "error"; 
    }

    printf("Debug in coderbyteInternalStdinFunction(): %s", strArr);
    return strArr;
    
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
