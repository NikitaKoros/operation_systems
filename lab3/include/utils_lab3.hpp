#ifndef UTILS_3
#define UTILS_3
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>

#define SHM_NAME "/my_shared_memory"
#define SEM_NAME "/semaphore"
#define MAX_LINE_LENGTH 1024

typedef struct {
    char line[MAX_LINE_LENGTH];
    int is_valid;
} SharedData;

bool is_valid(std::string);
#endif