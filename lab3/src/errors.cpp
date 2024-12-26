#include "../include/errors.hpp"
#include <unistd.h>

void log_errors(Error err) {
    switch(err) {
        case SHM_OPEN_ERROR:
            write_to_file(STDERR_FILENO, "SHM_OPEN_ERROR\n");
            break;
        case MMAP_ERROR:
            write_to_file(STDERR_FILENO, "MMAP_ERROR\n");
            break;
        case SEM_OPEN_ERROR:
            write_to_file(STDERR_FILENO, "SEM_OPEN_ERROR\n");
            break;
        case TRUNCATE_ERROR:
            write_to_file(STDERR_FILENO, "TRUNCATE_ERROR\n");
            break;
        case FORK_ERROR:
            write_to_file(STDERR_FILENO, "FORK_ERROR\n");
            break;
        case EXECL_ERROR:
            write_to_file(STDERR_FILENO, "EXECL_ERROR\n");
            break;
        case SEM_POST_ERROR:
            write_to_file(STDERR_FILENO, "SEM_POST_ERROR\n");
            break;
        case READ_ERROR:
            write_to_file(STDERR_FILENO, "READ_FAILED\n");
            break;
        case WRITE_FAILED:
            write_to_file(STDERR_FILENO, "WRITE_FAILED\n");
            break;
        case FILE_OPEN_ERROR:
            write_to_file(STDERR_FILENO, "FILE_OPEN_ERROR\n");
            break;
        default:
            write_to_file(STDERR_FILENO, "UNKNOWN_ERROR\n");
            break;
    }
}  