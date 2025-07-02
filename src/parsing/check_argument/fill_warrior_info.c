/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

static int search_args(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb)
{
    if (my_strcmp(av[*arg_pos], "-a") == 0) {
        if (fill_adresse(warrior, av, arg_pos, war_nb) == 84)
            return 84;
        else
            return 0;
    }
    if (my_strcmp(av[*arg_pos], "-n") == 0) {
        if (fill_nb_name(warrior, av, arg_pos, war_nb) == 84)
            return 84;
        else
            return 0;
    }
    if (is_a_dot_cor(av[*arg_pos]) == 0) {
        if (fill_file(warrior, av, arg_pos, war_nb) == 84)
            return 84;
        else
            return 0;
    }
    mini_printf("Invalid argument\n");
    return 84;
}

int fill_warrior_info(warrior_info_t *warrior, char **av, int *arg_pos)
{
    int war_nb = 0;

    for (; av[*arg_pos] != NULL;) {
        if (search_args(warrior, av, arg_pos, &war_nb) == 84)
            return 84;
        else
            continue;
    }
    return 0;
}
