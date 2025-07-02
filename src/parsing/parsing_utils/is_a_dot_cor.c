/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int is_a_dot_cor(char *file)
{
    int len = my_strlen(file);

    if (len < 5)
        return 84;
    if (file[len - 1] == 'r' &&
        file[len - 2] == 'o' &&
        file[len - 3] == 'c' &&
        file[len - 4] == '.')
        return 0;
    else
        return 84;
    return 0;
}
