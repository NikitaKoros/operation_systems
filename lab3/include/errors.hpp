#ifndef ERRORS
#define ERRORS

#include "io.hpp"

typedef enum {
    OK,
    PIPE_ERROR,
    STOP_ERROR,
    READ_ERROR,
    WRITE_FAILED,
    FILE_OPEN_ERROR,
    INVALID_INPUT,
} Error;

void log_errors(Error);

#endif