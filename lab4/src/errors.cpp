#include "../include/errors.hpp"
#include <unistd.h>

void log_errors(Error err) {
    switch(err) {
        case WRONG_NUMBER_OF_PARAMS:
            write_to_file(STDERR_FILENO, "WRONG_NUMBER_OF_PARAMS\n");
            break;
        case IMPLEMENTATION_NOT_FOUND:
            write_to_file(STDERR_FILENO, "IMPLEMENTATION_NOT_FOUND\n");
        default:
            write_to_file(STDERR_FILENO, "UNKNOWN_ERROR\n");
            break;
    }
}  