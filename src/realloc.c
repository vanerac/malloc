/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** realloc.c file
*/

#include "my_mem.h"

int expandPointer(void *ptr, size_t size)
{
    memblock *data = ptr - sizeof(memblock);

    if (data == NULL)
        abort(); // invalid pointer
    if (data->_size >= size)
        return 1;

    //     else
    if (data->_next && ((size_t) ptr + size) < (size_t) data->_next) {
        data->_size = size;
        return 1;
    } else if (!data->_next) {
        while ((size_t) (data + sizeof(memblock) + size) > end_size(NULL))
            fetch_mem();
        data->_size = size;
        current_index((void *) (current_index(NULL) + size));
        return 1;
    } else
        return 0;
}

void *realloc(void *ptr, size_t size)
{
    if (!size) {
        free(ptr);
        return NULL;
    }

    size = ALIGN16(size);
    if (ptr && size && expandPointer(ptr, size))
        return ptr;
    void *newptr = malloc(size);
    if (!ptr)
        return newptr;
    memcpy(newptr, ptr,
        ((memblock *) ((size_t) ptr - sizeof(memblock)))->_size);
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