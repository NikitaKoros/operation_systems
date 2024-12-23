#include "../include/errors.h"
#include "../include/io.h"
#include "../include/utils_lab2.h"

int main(int argc, char *argv[]) {
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

    sem_init(&semaphore, 0, maxThreads);

    read_matrix(matrix, size);

    struct timespec start_time, end_time;
    double elapsed;

    clock_gettime(CLOCK_REALTIME, &start_time);
    int determinant = calculate_determinant();

    clock_gettime(CLOCK_REALTIME, &end_time);

    if (end_time.tv_nsec < start_time.tv_nsec) {
        end_time.tv_sec -= 1;
        end_time.tv_nsec += 1000000000;
    }
    elapsed = (end_time.tv_sec - start_time.tv_sec) +
              (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;


    print_to_stdout("Determinant: ");
    char detString[20];
    int_to_string(determinant, detString, sizeof(detString));
    print_to_stdout(detString);
    print_to_stdout(".\n");

    char timeString[50];
    snprintf(timeString, sizeof(timeString), "Time taken: %.6f seconds.\n", elapsed);
    print_to_stdout(timeString);

    sem_destroy(&semaphore);

    return 0;
}
