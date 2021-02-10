/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** malloc.c file
*/

#include <stdio.h>
#include "my_mem.h"

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

    size = align(size, 0);

    size_t init_size = inital_size(NULL);  // gets set only once
    if (init_size == 0)
        init_size = inital_size(sbrk(0));

    memblock *ret = find_mem(size);

    if (ret) {
        ret->_free = 0;
        return ret->_ptr;
    }

    size_t index = current_index(NULL);
    size_t expected_range = (init_size + index + size + sizeof(memblock));

    // fetch new memory
    while (expected_range > end_size(NULL))
        fetch_mem();

    //init it
    void *ptr = init_memory(size, (void *) (init_size + index));
    // store it
    current_index((size_t *) (index + size + sizeof(memblock)));

    return ptr;
}