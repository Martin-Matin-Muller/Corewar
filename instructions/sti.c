/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** sti.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static uint32_t get_param(arena_t *arena, head_list_t *head,
    type_t coding_byte, int offset)
{
    int param = 0;
    uint32_t value = 0;

    if (coding_byte == REG) {
        param = arena->arena[(PC + 1 + offset) % MEM_SIZE];
        if (param >= 1 && param <= 16)
            my_memmove(&value, head->registers[param - 1], REG_SIZE);
    } else if (coding_byte == INDEX)
        my_memmove(&value, &arena->arena[(PC + 1 + offset) %
            MEM_SIZE], IND_SIZE);
    return value;
}

int sti(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], true);
    uint32_t address_to_load = 0;
    uint32_t value1 = 0;
    uint32_t value2 = 0;
    int reg = 0;
    char log[256];

    if (coding_byte[0] == REG)
        reg = arena->arena[(PC + 2) % MEM_SIZE];
    value1 = get_param(arena, head, coding_byte[1], coding_byte[0]);
    value2 = get_param(arena, head, coding_byte[2],
        (coding_byte[0] + coding_byte[1]));
    address_to_load = PC + (value1 + value2) % IDX_MOD;
    if (reg >= 1 && reg <= 16) {
        my_memmove(&arena->arena[address_to_load % MEM_SIZE],
            head->registers[reg - 1], REG_SIZE);
        write_color_arena(arena, REG_SIZE, address_to_load % MEM_SIZE, head->team);
    }
    post_inst(head, coding_byte, head->carry);
    snprintf(log, 256,"%s did the instruction sti, it load the value at the address %d into r%d\n",
     head->team->war_header->prog_name, address_to_load, reg);
    update_log(arena, head, log);
    update_reg(arena, head, reg - 1);
    //write_color_reg(head, reg - 1);
    return 0;
}
