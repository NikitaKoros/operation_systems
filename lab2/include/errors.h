#ifndef ERROR
#define ERROR

#include "io.h"

typedef enum {
    OK,
    WRONG_NUMBER_OF_PARAMS,
    MEM_ALLOC_FAILED,
    THREAD_CREATION_FAILED,
} Error;

void log_errors(Error);

#endif