/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** my_mem.h file
*/

#ifndef C_MY_MEM_H
#define C_MY_MEM_H

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>


/*
 * TODO Musts:
 *  You allocation strategy must be like follow:
 *  - you must align your memory on a power of 2.
 *  - the break must always be aligned on a multiple of 2 pages.
 *  - you must implement the best fit algorithm.
 *
 * TODO Store:
 *  - Inital memory pos (on startup, before first fetch)
 *  - End fetched page
 *  - Current Index on page (not allocated to a ptr)
 *  - List of allocated ptr (linked list)
 *
 * TODO Pointer Structure :
 *  - Is Malloced Id ?
 *  - Is Free
 *  - Size
 *  - Ptr (return this for malloc)
 *  - Ptr to next Pointer Block
 * */

// TODO bonus clear free on exit ??
typedef struct mem_block memblock;

struct mem_block {
    long _id;
    size_t _size;
    unsigned char _free;
    void *_ptr;
    memblock *_next;
};

#define ALIGN16(x) (((x) + ((16) - 1)) & ~((16) - 1))

extern pthread_mutex_t lock;

size_t end_size(size_t *size);

size_t inital_size(void *size);

memblock **my_blocks();

void *find_mem(size_t size);

void *init_memory(size_t size, void *ptr);

size_t current_index(size_t *index);

void fetch_mem();

void *malloc(size_t size);

void free(void *ptr);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);

void *reallocarray(void *ptr, size_t nmemb, size_t size);

size_t align(size_t s, int p);

#endif //C_MY_MEM_H
