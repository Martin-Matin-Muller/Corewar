/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../../parsing/parse_args.h"
#include "../arena.h"

static void index_case(type_t args_type[4])
{
    for (int i = 0; i < 4; i++) {
        if (args_type[i] == DIR || args_type[i] == IND)
            args_type[i] = INDEX;
    }
    return;
}

static void fill_tab(type_t *args_type, int nb)
{
    int mask = 0b00000011;
    int type = 0;

    for (int i = 3; i >= 0; i--) {
        type = nb & mask;
        if (type == 0b01)
            args_type[i] = REG;
        if (type == 0b11)
            args_type[i] = IND;
        if (type == 0b10)
            args_type[i] = DIR;
        if (type == 0b00)
            args_type[i] = NONE;
        nb = nb >> 2;
    }
    return;
}

type_t *read_coding_byte(int nb, bool is_index)
{
    type_t *args_type = malloc(sizeof(type_t) * 4);

    if (!args_type)
        return NULL;
    fill_tab(args_type, nb);
    if (is_index)
        index_case(args_type);
    return args_type;
}
