/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../parsing/parse_args.h"

//have to add a free_list
void free_arena(arena_t *arena)
{
    if (arena) {
        if (arena->warriors) {
            free_warrior_info(arena->warriors);
            free(arena->warriors);
        }
        if (arena->arena)
            free(arena->arena);
        if (arena->heads)
            free_head_list(arena->heads);
        free(arena);
    }
}
