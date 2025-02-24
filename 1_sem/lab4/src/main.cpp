#include <dlfcn.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>

#include <cstddef>
#include <ctime>
#include <map>
#include <string>
#include <iostream>

#include "../include/errors.hpp"
#include "../include/io.hpp"

typedef void* (*create_func)(void* const, const size_t);
typedef void (*destroy_func)(void* const);
typedef void* (*alloc_func)(void* const, const size_t);
typedef void (*free_func)(void* const, void* const);

static create_func allocator_create = nullptr;
static destroy_func allocator_destroy = nullptr;
static alloc_func allocator_alloc = nullptr;
static free_func allocator_free = nullptr;

std::map<void*, size_t> allocated_blocks;

void* stub_allocator_create(void* const memory, const size_t size) {
    return memory;
}

void stub_allocator_destroy(void* const allocator) {
    write_to_file(STDOUT_FILENO, "Emergency allocator destroyed\n");
    return;
}

void* stub_allocator_alloc(void* const allocator, const size_t size) {
    void* ptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (ptr == MAP_FAILED) {
        return nullptr;
    }
    allocated_blocks[ptr] = size;
    return ptr;
}

void stub_allocator_free(void* const allocator, void* const memory) {
    munmap(memory, allocated_blocks[memory]);
    allocated_blocks.erase(memory);
}

void load_emergency_functions() {
    allocator_create = stub_allocator_create;
    allocator_destroy = stub_allocator_destroy;
    allocator_alloc = stub_allocator_alloc;
    allocator_free = stub_allocator_free;
}

void load_library_functions(char* lib_path, void** cur_library) {
    void* library = dlopen(lib_path, RTLD_LAZY);
    if (!library) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return;
    }

    allocator_create = (create_func)dlsym(library, "allocator_create");
    if (!allocator_create) {
        write_to_file(STDERR_FILENO, "Failed to load 'allocator_create'\n");
    }
    
    allocator_destroy = (destroy_func)dlsym(library, "allocator_destroy");
    if (!allocator_destroy) {
        write_to_file(STDERR_FILENO, "Failed to load 'allocator_destroy'\n");
    }
    
    allocator_alloc = (alloc_func)dlsym(library, "allocator_alloc");
    if (!allocator_alloc) {
        write_to_file(STDERR_FILENO, "Failed to load 'allocator_alloc'\n");
    }
    
    allocator_free = (free_func)dlsym(library, "allocator_free");
    if (!allocator_free) {
        write_to_file(STDERR_FILENO, "Failed to load 'allocator_free'\n");
    }

    *cur_library = library;
}

double calculate_time(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main(int argc, char** argv) {
    void* library = NULL;
    if (argc < 2) {
        log_errors(WRONG_NUMBER_OF_PARAMS);
        write_to_file(STDOUT_FILENO, "Using Emergency Implementations\n");
        load_emergency_functions();
    } else {
        load_library_functions(argv[1], &library);
        if (!allocator_create || !allocator_destroy || !allocator_alloc || !allocator_free) {
            log_errors(LIBRARY_OPEN_ERROR);
            write_to_file(STDOUT_FILENO, "Using Emergency Implementations\n");
            load_emergency_functions();
        }
        write_to_file(STDOUT_FILENO, "Library Loaded Successfully\n");
    }

    size_t memory_size = 1024 * 1024;
    void* memory = mmap(NULL, memory_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    if (memory == MAP_FAILED) {
        log_errors(MEMORY_MAPPING_FAILED);
        return 1;
    }

    void* allocator = allocator_create(memory, memory_size);
    if (!allocator) {
        log_errors(ALLOCATOR_CREATION_ERROR);
        munmap(memory, memory_size);
        return 1;
    }
    print_to_stdout("Allocator created successfully\n");
    
    
    // Тестинг
    struct timespec start, end;
    double time_used;
    size_t data_size = 1030;

    clock_gettime(CLOCK_MONOTONIC, &start);
    void* ptr1 = allocator_alloc(allocator, data_size);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    time_used = calculate_time(start, end);
    if (ptr1) {
        print_to_stdout("Time of allocation of " + std::to_string(data_size) +
                        " bytes: " + std::to_string(time_used) + " second\n");
    } else {
        print_to_stdout("Allocation failed\n");
    }
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    allocator_free(allocator, ptr1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    time_used = calculate_time(start, end);
    
    print_to_stdout("Time of freeing of " + std::to_string(data_size) +
                        " bytes: " + std::to_string(time_used) + " second\n");
    
    /////////////////////////////////////////////////////////////////////////////
    
    data_size = 10567;

    clock_gettime(CLOCK_MONOTONIC, &start);
    void* ptr2 = allocator_alloc(allocator, data_size);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    time_used = calculate_time(start, end);
    if (ptr1) {
        print_to_stdout("Time of allocation of " + std::to_string(data_size) +
                        " bytes: " + std::to_string(time_used) + " second\n");
    } else {
        print_to_stdout("Allocation failed\n");
    }
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    allocator_free(allocator, ptr2);
    clock_gettime(CLOCK_MONOTONIC, &end);

    time_used = calculate_time(start, end);
    
    print_to_stdout("Time of freeing of " + std::to_string(data_size) +
                        " bytes: " + std::to_string(time_used) + " second\n");
    
    /////////////////////////////////////////////////////////////////////
    
    void * test[1000];
    size_t size = 1234;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 1000; i++) {
        test[i] = allocator_alloc(allocator, size);
    }
    for (int i = 0; i < 1000; i++) {
        allocator_free(allocator, test[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    time_used = calculate_time(start, end);
    
    print_to_stdout("Time of 1000 allocations and freeings of " + std::to_string(data_size) +
                        " bytes: " + std::to_string(time_used) + " second\n");
    
    allocator_destroy(allocator);
    munmap(memory, memory_size);
    
    if (library) {
        dlclose(library);
    }
    
    return 0;
}
