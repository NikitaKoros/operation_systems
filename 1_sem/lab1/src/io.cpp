#include "../include/io.h"

ssize_t read_input(int input_file, std::string& message) {
    char buffer[BUFF_SIZE];
    ssize_t bytesRead;
    std::string output;
    
    while ((bytesRead = read(input_file, buffer, BUFF_SIZE)) > 0) {
        output.append(buffer, bytesRead);
        if (output.back() == '\n') {
            output.erase(output.length() - 1);
            break;
        }
    }

    if (bytesRead == -1) {
        return -1;
    }
    
    message = output;
    return static_cast<ssize_t>(output.size());
}

ssize_t read_from_stdin(std::string& message) {
    return read_input(STDIN_FILENO, message);
}

ssize_t write_to_file(int file_output, const std::string& message) {
    return write(file_output, message.c_str(), message.size());
}

void print_to_stdout(const std::string& message) {
    write_to_file(STDOUT_FILENO, message);
}