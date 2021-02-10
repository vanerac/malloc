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


    size_t init_size = inital_size(NULL);  // gets set only once
    if (init_size == 0)
        init_size = inital_size(sbrk(0));

//
//

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