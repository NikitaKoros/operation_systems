#ifndef ERRORS
#define ERRORS

#include "io.hpp"

typedef enum {
    OK,
    WRONG_NUMBER_OF_PARAMS,
    IMPLEMENTATION_NOT_FOUND,
    LIBRARY_OPEN_ERROR,
    ALLOCATOR_CREATION_ERROR,
    ALLOCATOR_DESTRACTION_FAILED,
    MEMORY_MAPPING_FAILED,
} Error;

void log_errors(Error);

#endif