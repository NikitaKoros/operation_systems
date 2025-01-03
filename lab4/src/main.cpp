#include <cstddef>

#include "../include/errors.hpp"
#include "../include/io.hpp"

typedef void* (*create_func)(void* const, const size_t);
typedef void (*destroy_func)(void* const);
typedef void* (*alloc_func)(void* const, const size_t);
typedef void (*free_func)(void* const, void* const);

static create_func allocator_create = NULL;
static destroy_func allocator_destroy = NULL;
static alloc_func allocator_alloc = NULL;
static free_func allocator_free = NULL;

void* stub_allocator_create(void* const memory, const size_t size) {}

void stub_allocator_destroy(void* const allocator) {}

void* stub_allocator_alloc(void* const allocator, const size_t) {}

void stub_allocator_free(void* const, void* const memory) {}

int main(int argc, char** argv) {
    if (argc < 2) {
        log_errors(WRONG_NUMBER_OF_PARAMS)
    }

    return 0;
}
