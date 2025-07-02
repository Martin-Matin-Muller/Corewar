/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** fork.c
*/

#include <stdio.h>
#include "my.h"
#include "op.h"

void copy_head(head_list_t **reading_heads, head_list_t *head, int position)
{
    head_list_t *new_head = malloc(sizeof(head_list_t));
    if (!new_head)
        return;

    new_head->team = head->team;
    new_head->position = position;
    new_head->cooldown = head->cooldown;
    new_head->pending_instruction = 0;
    new_head->carry = head->carry;
    new_head->registers = malloc(sizeof(char *) * REG_NUMBER);
    if (!new_head->registers)
        return;
    for (int i = 0; i < REG_NUMBER; i++) {
        new_head->registers[i] = malloc(REG_SIZE);
        if (!new_head->registers[i])
            return;
        my_memmove(new_head->registers[i], head->registers[i], REG_SIZE);
    }
    new_head->reg_color = malloc(sizeof(sfColor *) * REG_NUMBER);
    if (!new_head->reg_color)
        return;
    for (int i = 0; i < REG_NUMBER; i++) {
        new_head->reg_color[i] = malloc(sizeof(sfColor) * REG_SIZE);
        if (!new_head->reg_color[i])
            return;
        for (int j = 0; j < REG_SIZE; j++) {
            new_head->reg_color[i][j] = head->reg_color[i][j];
        }
    }

    new_head->next = *reading_heads;
    *reading_heads = new_head;
}

int fork_i(arena_t *arena, head_list_t *head)
{
    uint16_t new_position = 0;
    char log[256];

    my_memmove(&new_position,
        &arena->arena[(PC + 1) % MEM_SIZE], IND_SIZE);
    new_position = __builtin_bswap16(new_position);
    new_position = (int16_t)new_position;
    new_position = PC + new_position % IDX_MOD;
    copy_head(&arena->heads, head, new_position);
    head->team->nb_process += 1;
    PC = (PC + IND_SIZE) % MEM_SIZE;
    post_inst(head, NULL, head->carry);
    snprintf(log, 256, "%s did the instruction fork, it create another processus at %d\n",
     head->team->war_header->prog_name, new_position);
    update_log(arena, head, log);
    return 0;
}
