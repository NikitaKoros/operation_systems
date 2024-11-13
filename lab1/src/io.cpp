#include "../include/io.h"


// ssize_t read_input(int input_file, std::string& message) {
//     char buffer[BUFF_SIZE];
//     ssize_t bytesRead;
//     std::string output;
    
//     while ((bytesRead = read(input_file, buffer, BUFF_SIZE))) {
//         output.append(buffer, bytesRead);
//     }
    
//     if(bytesRead == -1) {
//         return -1;
//     }
    
//     message = output;
//     return static_cast<ssize_t>(output.size());
// }

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
        return -1;  // Ошибка при чтении
    }
    
    message = output;
    return static_cast<ssize_t>(output.size());  // Возвращаем количество считанных символов
}


ssize_t read_from_stdin(std::string& message) {
    return read_input(STDIN_FILENO, message);
}

// ssize_t read_line(int input_file, std::string& message) {
//     char buffer[BUFF_SIZE];
//     ssize_t bytes_read;
//     std::string output;
    
//     while ((bytes_read = read(input_file, buffer, BUFF_SIZE)) > 0) {
//         for (int i = 0; i < bytes_read; i++) {
//             if (buffer[i] == '\n') {
//                 message = output;
//                 return 
//             }
//         }
//     }
// }

ssize_t write_to_file(int file_output, const std::string& message) {
    return write(file_output, message.c_str(), message.size());
}

void print_to_stdout(const std::string& message) {
    write_to_file(STDOUT_FILENO, message);
}