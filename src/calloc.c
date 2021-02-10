/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** calloc.c file
*/

#include "my_mem.h"

void *calloc(size_t nmemb, size_t size) {

    write(2, "calloc\n", 7);
    void *ptr = malloc(nmemb * size);
    memset(ptr, 0, nmemb * size);
    return ptr;
}