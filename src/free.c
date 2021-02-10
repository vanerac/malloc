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
    print("free: ");
    printAdrr(ptr);

    if (!ptr)
        return print("\n");

    print(" size : ");
    memblock *val = (memblock *) (((long) ptr) - sizeof(memblock));
    mputnbrn(val->_size);

    val->_free = 1;
}