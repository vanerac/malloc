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

typedef struct mem_block memblock_t;

struct mem_block {
    long _id;
    size_t _size;
    unsigned char _free;
    void *_ptr;
    memblock_t *_next;
    memblock_t *_prev;
};

#define ALIGN16(x) (((x) + ((16) - 1)) & ~((16) - 1))

extern pthread_mutex_t lock;

size_t end_size(size_t *size);

size_t inital_size(void *size);

memblock_t **my_blocks(void);

void *find_mem(size_t size);

void *init_memory(size_t size, void *ptr);

size_t current_index(size_t *index);

void fetch_mem(void);

void *malloc(size_t size);

void free(void *ptr);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);

void *reallocarray(void *ptr, size_t nmemb, size_t size);


#endif
