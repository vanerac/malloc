/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** malloc.c file
*/

#include <stdio.h>
#include "my_mem.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

size_t mpow(size_t v, size_t p)
{
    if (p == 0)
        return 1;
    return v * mpow(v, p - 1);
}

size_t align(size_t s, int p)
{
    if (s > mpow(2, p))
        return align(s, p + 1);
    return mpow(2, p);
}

void *malloc(size_t size)
{
    pthread_mutex_lock(&lock);
    size = ALIGN16(size);// todo fix this askip
    static size_t init_size = 0;  // gets set only once
    if (init_size == 0)
        init_size = inital_size(sbrk(0));
    memblock *ret = find_mem(size);
    if (ret) {
        ret->_free = 'N';
        pthread_mutex_unlock(&lock);
        return ret->_ptr;
    }
    size_t index = current_index(NULL);
    size_t expected_range = (init_size + index + size + sizeof(memblock));
    while (expected_range > end_size(NULL))
        fetch_mem();
    void *ptr = init_memory(size, (void *) (init_size + index));
    current_index((size_t *) (index + size + sizeof(memblock)));
    pthread_mutex_unlock(&lock);
    return ptr;
}