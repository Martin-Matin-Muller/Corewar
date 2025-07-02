/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** live.c
*/

#include <stdio.h>
#include <ncurses.h>
#include "../include/my.h"
#include "../include/op.h"

static int find_warrior_by_name(warrior_info_t *warriors, char *war_name)
{
    for (int i = 0; warriors[i].file != NULL; i++) {
        if (my_strcmp(warriors[i].war_header->prog_name, war_name) == 0)
            return i;
    }
    return -1;
}

int live(arena_t *arena, head_list_t *head)
{
    uint32_t nb_of_player = 0;
    char *name_of_player;
    int right_war = 0;
    char log[256];

    my_memmove(&nb_of_player,
        &arena->arena[(PC + 1) % MEM_SIZE], DIR_SIZE);
    nb_of_player = __builtin_bswap32(nb_of_player);
    name_of_player = find_warrior_by_number(arena->warriors, nb_of_player);
    if (name_of_player) {
        if ((int)arena->total_cycle < arena->dump || arena->dump == 0) {
            mini_printf("The player %d(%s)is alive.\n",
            nb_of_player, name_of_player);
            snprintf(log, 256, "The player %d(%s)is alive.\n",
            nb_of_player, name_of_player);
            update_log(arena, head, log);
        }
        arena->live_cycle += 1;
        right_war = find_warrior_by_name(arena->warriors, name_of_player);
        if (right_war != -1 && arena->warriors[right_war].dead == false)
            arena->warriors[right_war].alive = true;
    }
    PC = (PC + DIR_SIZE + 1) % MEM_SIZE;
    return 0;
}
