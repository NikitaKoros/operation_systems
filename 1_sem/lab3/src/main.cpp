#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>

#include "../include/errors.hpp"
#include "../include/io.hpp"
#include "../include/utils_lab3.hpp"

void PrintSemaphoreValue(sem_t* sem, std::string str) {
    std::cout << str;
    int value;
    if (sem_getvalue(sem, &value) == 0) {
        std::cout << "Semaphore value: " << value << std::endl;
    } else {
        perror("sem_getvalue");
    }
}

int main() {
    std::string file_name;
    print_to_stdout("Enter file name for output: ");
    if (read_input(STDIN_FILENO, file_name) == -1) {
        log_errors(READ_ERROR);
        return 1;
    }

    int file_output = open(file_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0600);
    if (file_output == -1) {
        log_errors(FILE_OPEN_ERROR);
        return 1;
    }

    int shm_fd;
    SharedData* shared_data = NULL;
    sem_t* sem = NULL;

    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        log_errors(SHM_OPEN_ERROR);
        return 1;
    }

    if (ftruncate(shm_fd, sizeof(SharedData)) == -1) {
        log_errors(TRUNCATE_ERROR);
        close(shm_fd);
        return 1;
    }

    shared_data =
        (SharedData*)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) {
        log_errors(MMAP_ERROR);
        close(shm_fd);
        return 1;
    }
    close(shm_fd);
    
    shared_data->is_valid = -1;
    
    sem_unlink(SEM_NAME);
    sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        log_errors(SEM_OPEN_ERROR);
        munmap(shared_data, sizeof(SharedData));
        shm_unlink(SHM_NAME);
        return 1;
    }    
    
    pid_t child_pid = fork();
    if (child_pid == -1) {
        log_errors(FORK_ERROR);
        munmap(shared_data, sizeof(SharedData));
        shm_unlink(SHM_NAME);
        sem_close(sem);
        sem_unlink(SEM_NAME);
        return 1;
    }

    if (child_pid == 0) {
        dup2(file_output, STDOUT_FILENO);
        close(file_output);

        execl("./child_exec", "child_exec", NULL);
        log_errors(EXECL_ERROR);
        return 1;
    }

    std::string user_input;
    print_to_stdout("Enter strings (type 'exit' to quit):\n");
    
    while (read_input(STDIN_FILENO, user_input)) {
        if (user_input == "exit") {
            break;
        }
        user_input += "\n";
        
        if (sem_wait(sem) == -1) {
            log_errors(SEM_WAIT_ERROR);
            continue;
        }
        
        strncpy(shared_data->line, user_input.c_str(), MAX_LINE_LENGTH - 1);
        shared_data->line[MAX_LINE_LENGTH - 1] = '\0';
        shared_data->is_valid = -1;
        if (sem_post(sem) == -1) {
            log_errors(SEM_POST_ERROR);
            continue;
        }
        
        while (true) {

            if (sem_wait(sem) == -1) {
                log_errors(SEM_WAIT_ERROR);
                continue;
            }
            
            if (shared_data->is_valid != -1) {
                if (!shared_data->is_valid) {
                    print_to_stdout("Invalid input " + std::string(shared_data->line));
                }
                shared_data->is_valid = -2;
                
                if (sem_post(sem) == -1) {
                    log_errors(SEM_WAIT_ERROR);
                    continue;
                }
                
                break;
            }
            
            if (sem_post(sem) == -1) {
                log_errors(SEM_WAIT_ERROR);
                continue;
            }
        }
    }
    sem_close(sem);
    sem_unlink(SEM_NAME);
    munmap(shared_data, sizeof(SharedData));
    shm_unlink(SHM_NAME);

    return 0;
}


