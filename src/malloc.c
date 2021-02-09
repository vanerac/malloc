/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** malloc.c file
*/

#include <stdio.h>
#include "my_mem.h"

void *malloc(size_t size)
{

    void *sz = sbrk(0);
    size_t init_size = inital_size(sz);  // gets set only once

    memblock *ret = find_mem(size);
    if (ret) {
        ret->_free = 0;
        return ret->_ptr;
    }

    size_t index = current_index(NULL);
    if ((init_size + index + size) > end_size(NULL))
        // fetch new memory
        fetch_mem();

    //init it
    void *ptr = init_memory(size, (void *) (init_size + index));
    // store it
    current_index((size_t *) (index + size + sizeof(memblock)));
    return ptr;
}