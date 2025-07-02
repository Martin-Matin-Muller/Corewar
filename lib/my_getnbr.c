/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** my_getnbr
*/
#include "my.h"

static int is_numb(char c)
{
    if ('0' <= c && c <= '9') {
        return 1;
    }
    return 0;
}

static int check_sign(char c)
{
    int sign = 1;

    if (c == '-') {
        sign = sign * -1;
    }
    return sign;
}

int my_getnbr(const char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    while (str[i] != '\0') {
        while (is_numb(str[i]) == 0) {
            sign = sign * check_sign(str[i]);
            i++;
        }
        while (is_numb(str[i]) == 1) {
            nb = nb * 10;
            nb = nb + (str[i] - '0');
            i++;
        }
        return (nb * sign);
    }
}
