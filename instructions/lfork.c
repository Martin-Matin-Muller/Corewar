/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** lfork.c
*/

#include <stdio.h>
#include "my.h"
#include "op.h"

int lfork(arena_t *arena, head_list_t *head)
{
    uint16_t new_position = 0;
    char log[256];

    my_memmove(&new_position,
        &arena->arena[(PC + 1) % MEM_SIZE], IND_SIZE);
    new_position = __builtin_bswap16(new_position);
    new_position = (int16_t)new_position;
    new_position = (new_position + PC);
    copy_head(&arena->heads, head, new_position);
    head->team->nb_process += 1;
    post_inst(head, NULL, head->carry);
    snprintf(log, 256, "%s did the instruction fork, it create another processus at %d\n",
     head->team->war_header->prog_name, new_position);
    update_log(arena, head, log);
    return 0;
}
