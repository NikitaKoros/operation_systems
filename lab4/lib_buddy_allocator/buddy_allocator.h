#ifndef _BUDDY_ALLOCATOR_
#define _BUDDY_ALLOCATOR_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/mman.h>
#include <math.h>
#include <unistd.h>
#include <cstddef>
#define NUM_SIZES 30

typedef struct Block {
    Block* next;
    size_t size;
    int is_free;
} Block;

typedef struct BuddyAllocator {
    void* memory;
    size_t total_size;
    Block* free_lists[NUM_SIZES];
} BuddyAllocator;

size_t round_to_power_of_two(size_t);
int get_power_of_two(size_t);

void* allocator_create(void* const, const size_t);
void allocator_destroy(void* const);
void* allocator_alloc(void* const, const size_t);
void allocator_free(void* const, void* const);

#ifdef __cplusplus
}
#endif

#endif // _BUDDY_ALLOCATOR_