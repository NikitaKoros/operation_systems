#include "../include/io.h"

ssize_t read_input(int input_file, char *message, size_t message_size) {
    char buffer[BUFF_SIZE];
    ssize_t bytesRead;
    size_t totalBytes = 0;

    if (message == NULL || message_size == 0) {
        return -1;
    }

    while ((bytesRead = read(input_file, buffer, BUFF_SIZE)) > 0) {
        if (totalBytes + bytesRead > message_size - 1) {
            return -1;
        }

        memcpy(message + totalBytes, buffer, bytesRead);
        totalBytes += bytesRead;

        if (message[totalBytes - 1] == '\n') {
            message[totalBytes - 1] = '\0';
            break;
        }
    }

    if (bytesRead == -1) {
        return -1;
    }

    message[totalBytes] = '\0';
    return (ssize_t)totalBytes;
}

ssize_t read_from_stdin(char *message, size_t message_size) {
    return read_input(STDIN_FILENO, message, message_size);
}

ssize_t write_to_file(int file_output, const char *message) {
    size_t len = strlen(message);
    ssize_t bytesWritten = write(file_output, message, len);
    return bytesWritten;
}

void print_to_stdout(const char *message) {
    write_to_file(STDOUT_FILENO, message);
}
