#include "../include/errors.h"

void log_errors(Error err) {
    switch(err) {
        case THREAD_CREATION_FAILED:
            write_to_file(STDERR_FILENO, "THREAD_CREATION_FAILED\n");
            break;
        case MEM_ALLOC_FAILED:
            write_to_file(STDERR_FILENO, "MEM_ALLOC_FAILED\n");
            break;
        case WRONG_NUMBER_OF_PARAMS:
            write_to_file(STDERR_FILENO, "WRONG_NUMBER_OF_PARAMS\n");
            break;
        default:
            write_to_file(STDERR_FILENO, "UNKNOWN_ERROR\n");
    }
}