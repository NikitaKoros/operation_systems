#include "../include/utils_lab3.hpp"
#include "../include/io.hpp"

constexpr const char* SHM_NAME = "/my_shm";
constexpr const char* SEM_NAME = "/my_sem";
constexpr size_t SHM_SIZE = 256;

int main() {
    int shm_fd;
    void* shm_ptr;
    sem_t* sem;

    // Open shared memory
    shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (shm_fd == -1) {
        write_to_file(STDERR_FILENO, "SHM_OPEN_ERROR\n");
        return 1;
    }

    // Map shared memory
    shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        write_to_file(STDERR_FILENO, "MMAP_ERROR\n");
        close(shm_fd);
        return 1;
    }
    close(shm_fd);

    // Open semaphore
    sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED) {
        write_to_file(STDERR_FILENO, "SEM_OPEN_ERROR\n");
        munmap(shm_ptr, SHM_SIZE);
        return 1;
    }

    while (true) {
        // Wait on semaphore
        if (sem_wait(sem) == -1) {
            write_to_file(STDERR_FILENO, "SEM_WAIT_ERROR\n");
            break;
        }

        // Read data from shared memory
        char buffer[SHM_SIZE];
        std::strncpy(buffer, (char*)shm_ptr, SHM_SIZE);
        buffer[SHM_SIZE - 1] = '\0'; // Ensure null-termination
        std::string data(buffer);

        if (data == "exit") {
            break;
        }

        // Process data
        if (is_valid(data)) {
            // Write to stdout
            write_to_file(STDOUT_FILENO, data + "\n");
        } else {
            // Write error to stderr
            write_to_file(STDERR_FILENO, "Invalid input: " + data + "\n");
        }

        // Signal semaphore
        if (sem_post(sem) == -1) {
            write_to_file(STDERR_FILENO, "SEM_POST_ERROR\n");
            break;
        }
    }

    // Clean up
    munmap(shm_ptr, SHM_SIZE);
    sem_close(sem);
    return 0;
}

bool is_valid(const std::string& line) {
    return !line.empty() && std::isupper(line[0]);
}