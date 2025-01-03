#ifndef ERRORS
#define ERRORS

#include "io.hpp"

typedef enum {
    OK,
    WRONG_NUMBER_OF_PARAMS,
    IMPLEMENTATION_NOT_FOUND,
    LIBRARY_OPEN_ERROR
} Error;

void log_errors(Error);

#endif