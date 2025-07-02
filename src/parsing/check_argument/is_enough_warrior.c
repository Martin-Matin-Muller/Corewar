/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "../parse_args.h"

int is_enough_warrior(warrior_info_t *warrior)
{
    int nb_warrior = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (warrior[i].file != NULL)
            nb_warrior++;
    }
    if (nb_warrior <= 1) {
        mini_printf("Too few warrior\n");
        return 84;
    }
    return 0;
}
