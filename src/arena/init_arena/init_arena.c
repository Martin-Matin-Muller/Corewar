/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../../parsing/parse_args.h"
#include "../arena.h"
#include <ncurses.h>
#include "../../csfml_bonus/graphical.h"
#include "op.h"

static int init_malloc_var(arena_t *arena)
{
    arena->arena = malloc(sizeof(char) * MEM_SIZE);
    arena->colored_arena = malloc(sizeof(sfColor) * MEM_SIZE);
    if (!arena->arena || !arena->colored_arena)
        return 84;
    clean_arena(arena->arena);
    clean_colored_arena(arena->colored_arena);
    arena->warriors = malloc(sizeof(warrior_info_t) * MAX_ARGS_NUMBER);
    if (!arena->warriors)
        return 84;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        arena->warriors[i].file = NULL;
        arena->warriors[i].nb_name = -1;
        arena->warriors[i].command = NULL;
        arena->warriors[i].address = -1;
        arena->warriors[i].alive = false;
        arena->warriors[i].dead = false;
        arena->warriors[i].war_header = malloc(sizeof(header_t));
        arena->warriors[i].war_color = war_colors[i];
        if (!arena->warriors[i].war_header)
            return 84;
    }
    return 0;
}

static void init_log(arena_t *arena)
{
    arena->log_to_display = malloc(sizeof(log_t));
    arena->log_to_display->head = NULL;
    arena->log_to_display->log = NULL;
}

static void init_reg(arena_t *arena)
{
    arena->reg_to_display = malloc(sizeof(reg_changed_t));
    arena->reg_to_display->head = NULL;
    arena->reg_to_display->reg = -1;
}

int init_arena(arena_t **arena_ptr, int ac)
{
    if (ac < 3) {
        write(2, "Too few warrior\n", 16);
        return 84;
    }
    *arena_ptr = malloc(sizeof(arena_t));
    if (!(*arena_ptr))
        return 84;
    (*arena_ptr)->live_cycle = 0;
    (*arena_ptr)->cycle_to_die = CYCLE_TO_DIE;
    (*arena_ptr)->actual_cycle = 0;
    (*arena_ptr)->dump = 0;
    (*arena_ptr)->total_cycle = 0;
    (*arena_ptr)->heads = NULL;
    if (init_malloc_var(*arena_ptr) == 84)
        return 84;
    init_log((*arena_ptr));
    init_reg((*arena_ptr));
    return 0;
}
