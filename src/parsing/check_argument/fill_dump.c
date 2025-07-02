/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int fill_dump(char **av, int *dump, int *arg_pos)
{
    if (my_strcmp(av[1], "-dump") == 0) {
        if (is_int(av[2]) == 84) {
            mini_printf("Invalid value after -dump\n");
            return 84;
        }
        *dump = my_atoi(av[2]);
        *arg_pos = 3;
    }
    return 0;
}
