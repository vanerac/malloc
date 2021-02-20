/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** free.c file
*/

#include "my_mem.h"

void free(void *ptr)
{
    if (!ptr)
        return;
    pthread_mutex_lock(&lock);

    memblock_t *val = (memblock_t *) (((long) ptr) - sizeof(memblock_t));
    if (val->_id != 0x6d616c6c6f63)
        abort();
    if (val->_free != 'N')
        abort();
    val->_free = 'Y';
    pthread_mutex_unlock(&lock);
}