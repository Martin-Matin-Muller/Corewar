/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** zjmp.c
*/

#include <stdio.h>
#include <ncurses.h>
#include "../include/my.h"
#include "../include/op.h"

int zjmp(arena_t *arena, head_list_t *head)
{
    int16_t offset = 0;
    int new_pc = 0;
    char log[256];

    my_memmove(&offset, &arena->arena[(PC + 1) % MEM_SIZE], IND_SIZE);
    offset = __builtin_bswap16(offset);
    if (head->carry) {
        new_pc = PC + offset % IDX_MOD;
        if (new_pc < 0)
            new_pc += MEM_SIZE;
        new_pc = new_pc % MEM_SIZE;
        PC = new_pc;
        snprintf(log, 256, "%s did the instruction zjmp, it jump at the position %d\n",
     head->team->war_header->prog_name, PC);
        update_log(arena, head, log);
    } else {
        PC = (PC + 1 + IND_SIZE) % MEM_SIZE;
        snprintf(log, 256, "%s did the instruction zjmp, it jump at the position %d\n",
     head->team->war_header->prog_name, PC);
        update_log(arena, head, log);
    }
    return 0;
}
