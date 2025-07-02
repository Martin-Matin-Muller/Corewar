/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** find the first occurence of a parameter in a string
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>

int my_strstr(char *str, char const *to_find)
{
    int nb_str = my_strlen(str);
    int nb_find = my_strlen(to_find);

    for (int i = 0; i < nb_str - nb_find; i++) {
        if (my_strncmp(&str[i], to_find, nb_find) == 0) {
            return 1;
        }
    }
    return 0;
}
