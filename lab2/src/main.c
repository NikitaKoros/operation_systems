#include "../include/io.h"
#include "../include/errors.h"
#include "../include/utils_lab2.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        log_errors(WRONG_NUMBER_OF_PARAMS);
        return 1;
    }
    
    size = atoi(argv[1]);
    int maxThreads = atoi(argv[2]);
    
    if (size <= 0 || size > MAX_SIZE) {
        write_to_file(STDERR_FILENO, "Invalid matrix size.\n");
        return 1;
    }
    
    //sem_init(&semaphore, 0, maxThreads);
    
    read_matrix(matrix, size);
    
    clock_t start_time = clock();
    int determinant = calculate_determinant();
    clock_t end_time = clock();
    
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    print_to_stdout("Determinant: ");
    char detString[20];
    int_to_string(determinant, detString, sizeof(detString));
    print_to_stdout(detString);
    print_to_stdout(".\n");
    
    char timeString[50];
    snprintf(timeString, sizeof(timeString), "Time taken: %.6f seconds.\n", time_taken);
    print_to_stdout(timeString);
    
    sem_destroy(&semaphore);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}