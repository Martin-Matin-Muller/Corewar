/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/
#include "my.h"
#include <string.h>

int is_an_indirect(char *to_verify)
{
    if (to_verify[0] == ':' || my_atoi(to_verify) != -4242)
        return 0;
    return 84;
}

int is_a_direct(char *to_verify)
{
    if (to_verify[0] == '%')
        if (to_verify[1] == ':' || my_atoi(to_verify + 1) != -4242)
            return 0;
    return 84;
}

int is_a_register(char *to_verify)
{
    int len = my_strlen(to_verify);

    if (len == 2 || len == 3)
        return 0;
    if (to_verify[0] == 'r')
        if (16 >= my_atoi(to_verify + 1) || my_atoi(to_verify + 1) >= 1)
            return 0;
    return 84;
}

int good_nb_parameter(char **line, int nb_of_parameter)
{
    int count = 0;

    for (int i = 0; line[i] != NULL; i++)
        count++;
    if (count != nb_of_parameter + 1)
        return 84;
    return 0;
}
