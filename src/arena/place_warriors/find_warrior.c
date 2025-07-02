/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** find the warrior with his number
*/

#include "../../../include/op.h"

char *find_warrior_by_number(warrior_info_t *warriors, uint32_t war_number)
{
    for (int i = 0; i < MAX_ARGS_NUMBER && warriors[i].file != NULL; i++) {
        if (war_number == (uint32_t)warriors[i].nb_name)
            return warriors[i].war_header->prog_name;
    }
    return NULL;
}
