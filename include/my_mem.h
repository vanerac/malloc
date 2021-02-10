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

struct  mem_block {
    //int _id ;//= 0x6d616c6c6f63;

    size_t _size;// = 0;

    unsigned char _free;// = 0;

    void *_ptr;// = NULL;

    memblock *_next;// = NULL;
    memblock *_prev;
};

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

//// TODO RM ME
//
//int
//
//int
//
//#define RES_LEN     30
//
//void
//
//void

#endif //C_MY_MEM_H
