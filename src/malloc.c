/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** malloc.c file
*/

#include <stdio.h>
#include "my_mem.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

size_t inital_size(void *size)
{
    static size_t ret = 0;
    if (size)
        ret = (size_t) size;
    return ret;
}

size_t current_index(size_t *index)
{
    static size_t ret = 0;
    if (index)
        ret = (size_t) index;
    return ret;
}

size_t end_size(size_t *size)
{
    static size_t ret = 0;
    if (size)
        ret = (size_t) size;

    return ret;
}

memblock_t **my_blocks(void)
{
    static memblock_t *val = NULL;
    return &val;
}

void *malloc(size_t size)
{
    pthread_mutex_lock(&lock);
    size = ALIGN16(size);
    static size_t init_size = 0;
    if (init_size == 0)
        init_size = inital_size(sbrk(0));
    memblock_t *ret = find_mem(size);
    if (ret) {
        ret->_free = 'N';
        pthread_mutex_unlock(&lock);
        return ret->_ptr;
    }
    size_t index = current_index(NULL);
    size_t expected_range = (init_size + index + size + sizeof(memblock_t));
    while (expected_range > end_size(NULL))
        fetch_mem();
    void *ptr = init_memory(size, (void *) (init_size + index));
    current_index((size_t *) (index + size + sizeof(memblock_t)));
    pthread_mutex_unlock(&lock);
    return ptr;
}