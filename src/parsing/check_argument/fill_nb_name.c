/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int fill_nb_name(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb)
{
    if (av[*arg_pos + 1] == NULL || is_a_dot_cor(av[*arg_pos + 1]) == 0) {
        mini_printf("No value after -n\n");
        return 84;
    }
    if (is_int(av[*arg_pos + 1]) == 84) {
        mini_printf("Invalid value after -n\n");
        return 84;
    }
    warrior[*war_nb].nb_name = my_atoi(av[*arg_pos + 1]);
    if (warrior[*war_nb].nb_name == -4242)
        return 84;
    *arg_pos += 2;
    return 0;
}
