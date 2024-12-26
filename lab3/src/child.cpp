#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>

#include "../include/errors.hpp"
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
    
    int shm_fd;
    SharedData* shared_data;
    sem_t* sem;

    shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (shm_fd == -1) {
        log_errors(SHM_OPEN_ERROR);
        return 1;
    }
    
    shared_data =
        (SharedData*)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_data == MAP_FAILED) {
        log_errors(MMAP_ERROR);
        close(shm_fd);
        return 1;
    }
    
    sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        log_errors(SEM_OPEN_ERROR);
        close(shm_fd);
        munmap(shared_data, sizeof(SharedData));
        return 1;
    }
    
    while (true) {
        
        if (sem_wait(sem) == -1) {
            log_errors(SEM_WAIT_ERROR);
            continue;
        }
        
        if (shared_data->is_valid == -1) {
            std::cout << shared_data->is_valid;
            if(is_valid(std::string(shared_data->line))) {
                shared_data->is_valid = 1;
                print_to_stdout(std::string(shared_data->line));
            } else {
                shared_data->is_valid = 0;
            }
        }
        if (sem_post(sem) == -1) {
            log_errors(SEM_WAIT_ERROR);
            continue;
        }
        
    }
    sem_close(sem);
    munmap(shared_data, sizeof(SharedData));
    close(shm_fd);
    return 0;
}

bool is_valid(std::string line) {
    return !line.empty() && std::isupper(line[0]);
}
