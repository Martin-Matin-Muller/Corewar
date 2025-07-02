/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/
#include "my.h"
#include <string.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int count = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[count] = src[i];
        count++;
    }
    dest[count] = '\0';
    return dest;
}
