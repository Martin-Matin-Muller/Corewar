/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include <sys/stat.h>
#include "../parse_args.h"

int check_argument(warrior_info_t *warrior, char **av, int *dump)
{
    int arg_pos = 1;

    if (fill_dump(av, dump, &arg_pos) == 84)
        return 84;
    if (fill_warrior_info(warrior, av, &arg_pos) == 84)
        return 84;
    if (is_enough_warrior(warrior) == 84)
        return 84;
    return 0;
}
