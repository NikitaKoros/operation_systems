#include "../include/utils_lab2.h"
#include <time.h>
#include <unistd.h>

int matrix[MAX_SIZE][MAX_SIZE];
int size;
sem_t semaphore;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

char* int_to_string(int number, char* str, int bufferSize) {
    int isNegative = 0;
    if (number < 0) {
        isNegative = 1;
        number = -number;
    }

    int index = 0;

    do {
        str[index++] = number % 10 + '0';
        number /= 10;
    } while (number > 0 && index < bufferSize - 1);

    if (isNegative) {
        str[index++] = '-';
    }

    str[index] = '\0';

    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

void read_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    print_to_stdout("Enter the matrix elements (row by row):\n");
    for (int i = 0; i < size; i++) {
        char buffer[BUFF_SIZE];
        ssize_t bytesRead = read_from_stdin(buffer, sizeof(buffer));
        if (bytesRead <= 0) {
            write_to_file(STDERR_FILENO, "Error reading matrix row.\n");
            exit(EXIT_FAILURE);
        }
        
        char* token = strtok(buffer, " \t\n");
        for (int j = 0; j < size; j++) {
            if (token == NULL) {
                write_to_file(STDERR_FILENO, "Not enough elements in the row.\n");
                exit(EXIT_FAILURE);
            }
            matrix[i][j] = atoi(token);
            token = strtok(NULL, " \t\n");
        }
        
        if (token != NULL) {
            write_to_file(STDERR_FILENO, "Too many elems in a row.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int recursive_determinant(int tempMatrix[MAX_SIZE][MAX_SIZE], int n) {
    if (n == 1) {
        return tempMatrix[0][0];
    }
    if (n == 2) {
        return tempMatrix[0][0] * tempMatrix[1][1] - tempMatrix[0][1] * tempMatrix[1][0];
    }

    int determinant = 0;
    int minorMatrix[MAX_SIZE][MAX_SIZE];
    for (int j = 0; j < n; ++j) {
        for (int i = 1, x = 0; i < n; ++i, ++x) {
            for (int k = 0, y = 0; k < n; ++k) {
                if (k == j) continue;
                minorMatrix[x][y++] = tempMatrix[i][k];
            }
        }

        int minorDet = recursive_determinant(minorMatrix, n - 1);
        determinant += ((j % 2 == 0) ? 1 : -1) * tempMatrix[0][j] * minorDet;
    }

    return determinant;
}

void *calculate_minor(void *arg) {
    MinorArgs *args = (MinorArgs *)arg;

    int tempMatrix[MAX_SIZE][MAX_SIZE];
    int minorSize = size - 1;

    for (int i = 0, x = 0; i < size; ++i) {
        if (i == args->row) continue;
        for (int j = 0, y = 0; j < size; ++j) {
            if (j == args->col) continue;
            tempMatrix[x][y++] = matrix[i][j];
        }
        ++x;
    }

    int determinant = recursive_determinant(tempMatrix, minorSize);

    pthread_mutex_lock(&mutex);
    args->result = determinant * ((args->col % 2 == 0) ? 1 : -1) * matrix[args->row][args->col];
    pthread_mutex_unlock(&mutex);

    sem_post(&semaphore);
    return NULL;
}

int calculate_determinant() {
    pthread_t threads[MAX_SIZE];
    MinorArgs args[MAX_SIZE];
    int determinant = 0;

    for (int j = 0; j < size; ++j) {
        sem_wait(&semaphore);
        args[j].row = 0;
        args[j].col = j;

        if (pthread_create(&threads[j], NULL, calculate_minor, &args[j]) != 0) {
            log_errors(THREAD_CREATION_FAILED);
            exit(EXIT_FAILURE);
        }
    }

    for (int j = 0; j < size; ++j) {
        pthread_join(threads[j], NULL);
        determinant += args[j].result;
    }

    return determinant;
}
