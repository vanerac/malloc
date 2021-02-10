/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** malloc.c file
*/

#include <stdio.h>
#include "my_mem.h"

size_t mpow(size_t v, size_t p)
{
    if (p == 0)
        return 1;
    return v * mpow(v, p - 1);
}

size_t align(size_t s, int p)
{
    if (s > mpow(2, p))
        return align(s, p + 1);
    return mpow(2, p);
}

void *malloc(size_t size)
{
    print("malloc start: ");
    mputnbr(size);

    size = align(size, 0);

    print(" aligned to: ");
    mputnbrn(size);

    size_t init_size = inital_size(NULL);  // gets set only once
    if (init_size == 0)
        init_size = inital_size(sbrk(0));

    //
    //

    memblock *ret = find_mem(size);

    if (ret) {
        ret->_free = 0;
        print("Found Memory: ");
        printAdrr(ret);
        print("\n");
        return ret->_ptr;
    }

    size_t index = current_index(NULL);
    size_t expected_range = (init_size + index + size + sizeof(memblock));
    print("Expected range: ");
    printAdrr((void *) expected_range);
    print("\n");
    // fetch new memory


    while (expected_range > end_size(NULL))
        fetch_mem();

    //init it
    void *ptr = init_memory(size, (void *) (init_size + index));
    // store it
    current_index((size_t *) (index + size + sizeof(memblock)));

    print("Sanity check: ");
    printAdrr(ptr);
    print(" + ");
    mputnbr((size + sizeof(memblock)));
    print(" = ");
    printAdrr((void *) expected_range);
    print(" < ");
    printAdrr(sbrk(0));
    print(" => ");
    int t = ((void *) expected_range < sbrk(0)) + '0';
    write(2, &t, 1);
    print("\n");
    print("end malloc, return ptr: ");
    printAdrr(ptr);
    print("\n\n");
    return ptr;
}