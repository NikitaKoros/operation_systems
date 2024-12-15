#ifndef UTILS
#define UTILS

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_SIZE 1000

extern int matrix[MAX_SIZE][MAX_SIZE];
extern int size;
extern sem_t semaphore;
extern pthread_mutex_t mutex;

typedef struct {
    int row;
    int col;
    int result;
} MinorArgs;

int calculate_determinant();
void* calculate_minor(void*);
int recursive_determinant(int [MAX_SIZE][MAX_SIZE], int);
char* int_to_string(int, char*, int);
void read_matrix(int[MAX_SIZE][MAX_SIZE], int);

#endif