#include "../include/child.h"
#include <unistd.h>

int main() {
    std::string line;
    char buffer[1024];
    
    ssize_t bytes_read;
    while ((bytes_read = read_input(STDIN_FILENO, line)) > 0) {
        if (is_valid(line)) {
            print_to_stdout(line + '\n');
        } else {
            write_to_file(STDERR_FILENO, "Invalid input: " + line + '\n');
        }
    }
    
    return 0;
}

bool is_valid(std::string line) {
    return !line.empty() && std::isupper(line[0]);
}