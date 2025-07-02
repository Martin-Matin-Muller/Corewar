/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int is_int(char *str)
{
    for (int i = 0; i != (int)my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            continue;
        else
            return 84;
    }
    return 0;
}
