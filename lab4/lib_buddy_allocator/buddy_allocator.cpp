#include "buddy_allocator.h"

size_t round_to_power_of_two(size_t size) {
    size_t power = 1;
    while (power < size) {
        power <<= 1;
    }
    return power;
}

int get_power_of_two(size_t size) {
    return (int)log2(size);
}

void* allocator_create(void* const memory, const size_t size) {
    if (!memory || size < sizeof(Block)) {
        return NULL;
    }

    BuddyAllocator* allocator =
        (BuddyAllocator*)mmap(nullptr, sizeof(BuddyAllocator), PROT_READ | PROT_WRITE,
                              MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (allocator == MAP_FAILED) {
        return NULL;
    }

    allocator->memory = memory;
    allocator->total_size = size;

    for (size_t i = 0; i < NUM_SIZES; i++) {
        allocator->free_lists[i] = NULL;
    }
    
    size_t block_size = round_to_power_of_two(size);
    int power_exponent = get_power_of_two(block_size);
    
    Block* initial_block = (Block*)memory;
    initial_block->size = block_size;
    initial_block->is_free = 1;
    
    //initial_block->next = allocator->free_lists[cur_power_exponent]; ??
    initial_block->next = NULL;
    allocator->free_lists[power_exponent] = initial_block; // what if initial block is too big
    
    return allocator;
}

void allocator_destroy(void* const buddy_allocator) {
    if (!buddy_allocator) return;
    
    BuddyAllocator* allocator = (BuddyAllocator*) buddy_allocator;
    munmap(allocator, sizeof(BuddyAllocator));
}

void* allocator_alloc(void* const buddy_allocator, const size_t size) {
    if (!buddy_allocator || size == 0) return NULL;
    
    BuddyAllocator* allocator = (BuddyAllocator*)buddy_allocator;
    
    size_t block_size = round_to_power_of_two(size);
    int power_exponent = get_power_of_two(block_size);
    
    for (int i = power_exponent; i < NUM_SIZES; i++) {
        if (allocator->free_lists[i]) {
            Block* block = allocator->free_lists[i];
            allocator->free_lists[i] = block->next;
            
            while (i > power_exponent) {
                i--;
                size_t smaller_block_size = 1 << i;
                Block* buddy = (Block*)((char*)block + smaller_block_size);
                buddy->size = smaller_block_size;
                buddy->is_free = 1;
                buddy->next = allocator->free_lists[i];
                allocator->free_lists[i] = buddy;
                
                block->size = smaller_block_size;
            }
            
            block->is_free = 0;
            return (void*)((char*)block + sizeof(Block));
        }
    }
    
    return NULL;
}

void allocator_free(void* const buddy_allocator, void* const memory) {
    if (!buddy_allocator || !memory) return;
    
    BuddyAllocator* allocator = (BuddyAllocator*)buddy_allocator;
    
    Block* block = (Block*)((char*)memory - sizeof(Block));
    
    block->is_free = 1;
    size_t block_size = block->size;
    int power_exponent = get_power_of_two(block_size);
    
    while (power_exponent < NUM_SIZES - 1) {
        size_t block_offset = (char*)block - (char*)allocator->memory;
        size_t buddy_offset = block_offset ^ block_size;
        Block* buddy = (Block*)((char*)allocator->memory + buddy_offset);
        
        if (!buddy->is_free || buddy->size != block_size) {
            break;
        }
        
        Block** list = &allocator->free_lists[power_exponent];
        while (*list && *list != buddy) {
            list = &(*list)->next;
        }
        if (*list) {
            *list = buddy->next;
        }
        
        if (buddy_offset < block_offset) {
            block = buddy;
        }
        block_size *= 2;
        block->size = block_size;
        power_exponent++;
    }
    
    block->next = allocator->free_lists[power_exponent];
    allocator->free_lists[power_exponent] = block;
}
