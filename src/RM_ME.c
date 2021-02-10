/*
** EPITECH PROJECT, 2021
** ${FOLDER_NAME}
** File description:
** RM_ME.c file
*/

/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** print a nbr on stdout
*/

#include <unistd.h>
#include <string.h>

int mputnbr(long nb)
{
    long len = 0;
    long divider = 0;
    char c = '?';
    long ret = 0;

    if (nb <= 0) {
        ret = write(2, (!nb ? "0" : "-"), 1) < 1;
        nb *= -1;
    }
    for (long cpy = nb; cpy; (cpy /= 10), ++len);
    while (--len >= 0 && !ret) {
        divider = 1;
        for (long cpy = len; cpy; (divider *= 10), --cpy);
        c = (nb / divider) + 48;
        ret = write(2, &c, 1) < 1;
        nb -= (nb / divider) * divider;
    }
    return ret;
}

int mputnbrn(long nb)
{
    mputnbr(nb);
    write(2, "\n", 1);
    return 1;
}

#define RES_LEN     30

void change_base(long long int nb, char *base)
{
    char res[RES_LEN + 1] = {};
    res[RES_LEN] = '\0';
    int base_len = 16;
    int val;

    for (int i = RES_LEN - 1; nb > 0; --i) {
        val = nb % base_len;
        nb /= base_len;
        res[i] = base[val];
    }
    write(2, res, RES_LEN);
}

void printAdrr(void *addr)
{
    write(2, "[0x", 3);
    change_base((long)addr, "0123456789abcdef");
    write(2, "]", 1);
}

void print(char *s) {
    write(2, s, strlen(s));
}