#include <dlfcn.h>
#include <sys/mman.h>
#include <unistd.h>

#include <cstddef>
#include <map>

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

void load_library_functions(char* lib_path) {
    void* library = dlopen(lib_path, RTLD_LOCAL | RTLD_NOW);
    if (!library) {
        return;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        log_errors(WRONG_NUMBER_OF_PARAMS);
        write_to_file(STDOUT_FILENO, "Using Emergency Implementations\n");
        load_emergency_functions();
    } else {
        load_library_functions(argv[1]);
        if (!allocator_create || !allocator_destroy || !allocator_alloc || !allocator_free) {
            log_errors(LIBRARY_OPEN_ERROR);
            write_to_file(STDOUT_FILENO, "Using Emergency Implementations\n");
            load_emergency_functions();
        }
        write_to_file(STDOUT_FILENO, "Library Loaded Successfully\n");
    }

    return 0;
}
