/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int fill_file(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb)
{
    warrior[*war_nb].file = my_strdup(av[*arg_pos]);
    if (warrior[*war_nb].file == NULL)
        return 84;
    (*war_nb)++;
    (*arg_pos)++;
    return 0;
}
