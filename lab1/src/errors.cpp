#include "../include/errors.h"

void log_errors(Error err) {
    ssize_t num;
    switch(err) {
        case EXEC_ERROR:
            write_to_file(STDERR_FILENO, "EXEC_ERROR\n");
            break;
        case FORK_ERROR:
            write_to_file(STDERR_FILENO, "FORK_ERROR\n");
            break;
        case PIPE_ERROR:
            write_to_file(STDERR_FILENO, "PIPE_ERROR\n");
            break;
        case STOP_ERROR:
            write_to_file(STDERR_FILENO, "STOP_ERROR\n");
            break;
        case READ_ERROR:
            write_to_file(STDERR_FILENO, "READ_FAILED\n");
            break;
        case WRITE_FAILED:
            write_to_file(STDERR_FILENO, "WRITE_FAILED\n");
            break;
        case INVALID_INPUT:
            write_to_file(STDERR_FILENO, "INVALID_INPUT\n");
            break;
        case FILE_OPEN_ERROR:
            write_to_file(STDERR_FILENO, "FILE_OPEN_ERROR\n");
            break;
        default:
            write_to_file(STDERR_FILENO, "UNKNOWN_ERROR\n");
            break;
    }
}  