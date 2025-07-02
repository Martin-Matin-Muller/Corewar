/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../../parsing/parse_args.h"
#include "../arena.h"

int get_equidistance_value(arena_t *arena)
{
    int total_prog_size = 0;
    int nb_warriors = 0;
    int equidistance_value = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (arena->warriors[i].file != NULL)
            total_prog_size += arena->warriors[i].war_header->prog_size;
    }
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (arena->warriors[i].file != NULL)
            nb_warriors++;
    }
    equidistance_value = (MEM_SIZE - total_prog_size) / nb_warriors;
    return equidistance_value;
}
