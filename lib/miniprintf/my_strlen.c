/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** len the string
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i;
    int nb = 0;

    for (i = 0; str[i] != '\0'; i++) {
        nb += 1;
    }
    return nb;
}
