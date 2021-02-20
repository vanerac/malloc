/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** realloc.c file
*/

#include "my_mem.h"

int expand_pointer(void *ptr, size_t size)
{
    memblock_t *data = ptr - sizeof(memblock_t);

    if (data == NULL)
        abort();
    if (data->_size >= size)
        return 1;
    if (data->_next && ((size_t) ptr + size) < (size_t) data->_next) {
        data->_size = size;
        return 1;
    } else if (!data->_next) {
        while ((size_t) (data + sizeof(memblock_t) + size) > end_size(NULL))
            fetch_mem();
        data->_size = size;
        current_index((void *) (current_index(NULL) + size));
        return 1;
    } else
        return 0;
}

void *realloc(void *ptr, size_t size)
{
    if (ptr && !size) {
        free(ptr);
        return NULL;
    }

    size = ALIGN16(size);
    if (ptr && size && expand_pointer(ptr, size))
        return ptr;
    void *newptr = malloc(size);
    if (!ptr)
        return newptr;
    memcpy(newptr, ptr,
        ((memblock_t *) ((size_t) ptr - sizeof(memblock_t)))->_size);
    free(ptr);
    return newptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t demanded = nmemb * size;
    if (demanded / nmemb != size)
        return NULL;
    return realloc(ptr, nmemb * size);
}