/*
** EPITECH PROJECT, 2024
** my revstr
** File description:
** just like my evil str
*/

#include "my.h"

void my_char_swap(char *a, char *b)
{
    char temp1 = *a;
    char temp2 = *b;

    *a = temp2;
    *b = temp1;
}

char *my_revstr(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; i++) {
        my_char_swap(&str[i], &str[length - i - 1]);
    }
    return str;
}
