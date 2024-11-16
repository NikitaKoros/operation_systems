#include <string>
#include <unistd.h>
#include "../include/io.h"
#include "../include/errors.h"
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char* argv[]) {
    std::string file_name;
    print_to_stdout("Enter file name for output: ");
    read_from_stdin(file_name);
    
    int file_output = open(file_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0600);
    if (file_output == -1) {
        log_errors(FILE_OPEN_ERROR);
        return 1;
    }
    
    int pipe1[2], pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        log_errors(PIPE_ERROR);
        return 1;
    }
    
    pid_t child_pid = fork();

    if (child_pid == -1) {
        log_errors(FORK_ERROR);
        return 1;
    }

    if (child_pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDERR_FILENO);
        dup2(file_output, STDOUT_FILENO);
        
        close(pipe1[0]);
        close(pipe2[1]);
        close(file_output);
            
        char *args[] = {(char*)"child_exec", NULL};
        execv("./child_exec", args);
        log_errors(EXEC_ERROR);
        
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        return 1;
    } 
    
    // Parent process
    
    close(pipe1[0]);
    close(pipe2[1]);
    
    std::string user_input;
    print_to_stdout("Enter strings (type 'exit' to quit):\n");
    while(read_input(STDIN_FILENO, user_input)) {
        if (user_input == "exit") break;
        user_input += "\n";
        write_to_file(pipe1[1], user_input);
    }
    
    close(pipe1[1]);
    
    std::string error_messages;
    
    while (read_input(pipe2[0], error_messages)) {
        print_to_stdout(error_messages + '\n');
        return 0;
    }
    
    close(pipe2[0]);
    close(file_output);
    return 0;
}
