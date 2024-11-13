#ifndef ERRORS
#define ERRORS

#include "io.h"
#include <unistd.h>

typedef enum {
    OK,
    EXEC_ERROR,
    FORK_ERROR,
    PIPE_ERROR,
    STOP_ERROR,
    READ_ERROR,
    WRITE_FAILED,
    FILE_OPEN_ERROR,
    INVALID_INPUT,
} Error;

void log_errors(Error);

#endif