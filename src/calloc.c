/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** calloc.c file
*/

#include "my_mem.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t demanded = nmemb * size;
    if ((demanded / nmemb) != size)
        return NULL;
    void *ptr = malloc(nmemb * size);
    if (!ptr)
        return ptr;
    memset(ptr, 0, nmemb * size);
    return ptr;
}