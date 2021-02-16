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

memblock_t **my_blocks()
{
    static memblock_t *val = NULL;
    return &val;
}

size_t append_frees(memblock_t *ptr, size_t needed, int *appened)
{
    if (needed <= 0) {
        return 0;
    } else if (ptr->_next && ptr->_next->_free == 'Y') {
        (*appened)++;
        return ptr->_size +
            append_frees(ptr->_next, needed - ptr->_size, appened);
    } else
        return ptr->_size;
}

void *find_mem(size_t size)
{
    // todo cut block that are really too big
    memblock_t **cursor = my_blocks();
    memblock_t *ret = NULL;
    for (; *cursor && (*cursor)->_next; cursor = &(*cursor)->_next) {
        if ((*cursor)->_free != 'Y')
            continue;
        size_t c_size = (*cursor)->_size;
        if (!ret && c_size >= size)
            ret = (*cursor); // fits
        else if (ret && c_size >= size && ret->_size < c_size)
            ret = *cursor; // fits better
    }
    return ret;
}

void *init_memory(size_t size, void *ptr)
{
    memblock_t ret;
    ret._id = 0x6d616c6c6f63;
    ret._size = size;
    ret._free = 'N';
    ret._ptr = (void *) (((long) ptr) + sizeof(memblock_t));
    ret._next = NULL;

    memcpy(ptr, &ret, sizeof(memblock_t));

    memblock_t **btr = my_blocks();
    for (; *btr && (*btr)->_next; btr = &(*btr)->_next);
    if (*btr) {
        ((memblock_t *) ptr)->_prev = *btr;
        (*btr)->_next = ptr;
    } else {
        ((memblock_t *) ptr)->_prev = NULL;
        *btr = (memblock_t *) ptr;
    }


    return ret._ptr;
}

void fetch_mem()
{
    void *expand = sbrk(getpagesize() * 2);
    if (expand == (void *) -1)
        abort();
    end_size(sbrk(0));
}