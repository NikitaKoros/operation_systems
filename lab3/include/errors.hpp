#ifndef ERRORS
#define ERRORS

#include "io.hpp"

typedef enum {
    OK,
    SHM_OPEN_ERROR,
    MMAP_ERROR,
    SEM_OPEN_ERROR,
    SEM_WAIT_ERROR,
    SEM_POST_ERROR,
    
    TRUNCATE_ERROR,
    FORK_ERROR,
    EXECL_ERROR,
    
    READ_ERROR,
    WRITE_FAILED,
    FILE_OPEN_ERROR,
} Error;

void log_errors(Error);

#endif