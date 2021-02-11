/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** free.c file
*/

#include "my_mem.h"
#include <stdlib.h>


/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** print a nbr on stdout
*/

#include "my_mem.h"

void free(void *ptr)
{
    if (!ptr)
        return;
    pthread_mutex_lock(&lock);

    memblock *val = (memblock *) (((long) ptr) - sizeof(memblock));
    if (val->_id != 0x6d616c6c6f63)
        abort();
    if (val->_free != 'N')
        abort();
    val->_free = 'Y';
    pthread_mutex_unlock(&lock);
}