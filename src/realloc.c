/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** realloc.c file
*/

#include "my_mem.h"

void *realloc(void *ptr, size_t size)
{
    if (!size) {
        free(ptr);
        return NULL;
    }
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