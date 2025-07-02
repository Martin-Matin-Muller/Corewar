/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** displays the number given as parameter
*/

#include "../../include/my.h"

int expo(int base, int exp)
{
    int i;
    int result = 1;

    for (i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int del(long nb)
{
    long i;
    long div = 0;
    long recup_nb = 0;

    for (i = 1; nb >= i;) {
        div = i;
        i = i * 10;
    }
    for (; div >= 1;) {
        recup_nb = nb / div;
        my_putchar((recup_nb % 10 + 48));
        div = div / 10;
    }
    return 0;
}

int my_put_nbr(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = (nb * (-1));
    } else if (nb == 0) {
        my_putchar(48);
    }
    del(nb);
    return nb;
}
