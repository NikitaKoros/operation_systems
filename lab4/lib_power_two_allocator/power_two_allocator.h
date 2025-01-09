#ifndef _2N_ALLOCATOR_
#define _2N_ALLOCATOR_

#ifdef __cplusplus
extern "C" {
#endif
#include <unistd.h>
#include <math.h>
#include <cstddef>
#include <sys/mman.h>

#define MIN_BLOCK_SIZE 8
#define MAX_BLOCK_SIZE 1024
#define MAX_BLOCK_INDEX 22

typedef struct Block {
    struct Block* next;
    size_t size;
} Block;

typedef struct TwonAllocator {
    Block* free_lists[MAX_BLOCK_INDEX];
    void* memory;
    size_t total_size;
} TwonAllocator;

size_t round_to_power_of_two(size_t);
int get_power_of_two(size_t);

void* allocator_create(void* const, const size_t);
void allocator_destroy(void* const);
void* allocator_alloc(void* const, const size_t);
void allocator_free(void* const, void* const);

#ifdef __cplusplus
}

#endif
#endif // _2N_ALLOCATOR_