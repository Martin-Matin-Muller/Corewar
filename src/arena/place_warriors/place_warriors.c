/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../../parsing/parse_args.h"
#include "../arena.h"
#include "../src/csfml_bonus/graphical.h"

static void write_in_arena(arena_t *arena, int i, int current_pos)
{
    for (int j = 0; j < arena->warriors[i].war_header->prog_size; j++) {
        if ((current_pos + j) >= MEM_SIZE) {
            arena->arena[(current_pos + j) % MEM_SIZE] =
                arena->warriors[i].command[j];
            arena->colored_arena[(current_pos + j) % MEM_SIZE] = war_colors[i];
        } else {
            arena->arena[current_pos + j] = arena->warriors[i].command[j];
            arena->colored_arena[(current_pos + j) % MEM_SIZE] = war_colors[i];
        }
    }
}

void place_warriors(arena_t *arena)
{
    int equidistance_value = get_equidistance_value(arena);
    int current_pos = 0;
    int save = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (arena->warriors[i].file == NULL)
            continue;
        if (arena->warriors[i].address != -1)
            current_pos = arena->warriors[i].address;
        write_in_arena(arena, i, current_pos);
        add_head(&arena->heads, &arena->warriors[i], current_pos, 0);
        arena->warriors[i].nb_process = 1;
        save = __builtin_bswap32(arena->warriors[i].nb_name);
        my_memmove(arena->heads->registers[0], &save, REG_SIZE);
        current_pos +=
            equidistance_value + arena->warriors[i].war_header->prog_size;
        if (current_pos > MEM_SIZE)
            current_pos = current_pos % MEM_SIZE;
    }
}
