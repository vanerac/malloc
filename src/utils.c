/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** utils.c file
*/

#include <string.h>
#include "my_mem.h"

size_t inital_size(void *size)
{
    static size_t ret = -1;
    if (size && size < (void *) ret)
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

memblock *my_blocks()
{
    static memblock val = {._ptr = NULL};
    return &val;
}

void *find_mem(size_t size)
{
    // todo find blocks following each other
    memblock *cursor = my_blocks(NULL);
    memblock *ret = NULL;
    int i = 0;
    for (;
        cursor && cursor->_next;
        cursor = cursor->_next) {
        ++i;
        if (!ret && cursor->_size >= size && cursor->_free == 1)
            ret = cursor; // fits
        else if (ret && cursor->_size >= size && ret->_size < cursor->_size &&
            cursor->_free == 1)
            *ret = *cursor; // fits better
    }
    return ret;
}

void* init_memory(size_t size, void *ptr)
{

    memblock ret;
    ret._size = size;
    ret._free = 0;
    ret._ptr = (void *) (((long) ptr) + sizeof(memblock));
    ret._next = NULL;
    ret._prev = NULL;

    memcpy(ptr, &ret, sizeof(memblock));

    memblock *btr = my_blocks();
    for (; btr && btr->_next; btr = btr->_next);
    if (btr->_ptr) {
        // TODO FIX
        ((memblock *) ptr)->_prev = btr;
        btr->_next = ptr;
    } else
        *btr = *(memblock *) ptr;

    return ret._ptr;
}

void fetch_mem()
{
    end_size(sbrk(getpagesize()));

    // TODO Assert thread safety : ptr == request
}