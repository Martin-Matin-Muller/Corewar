/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** display a string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
