/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** free.c file
*/

#include "my_mem.h"

void free(void *ptr) {
    if (!ptr)
        return;
    memblock *val = (memblock *)((long )ptr -  sizeof(memblock));
    val->_free = 1;
    if (val->_prev && val->_next) {
        val->_prev = val->_next;
        val->_next->_prev = val->_prev;
    }
}