/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** free.c file
*/

#include "my_mem.h"

void free(void *ptr)
{
    // TODO magic number check first bytes

    if (!ptr)
        return;
    memblock *val = (memblock *) (((long) ptr) - sizeof(memblock));

    val->_free = 1;
}