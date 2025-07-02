/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** aff.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"

int aff(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], true);
    int reg = 0;
    uint32_t reg_value = 0;
    char log[256];

    if (coding_byte[0] != REG)
        return 0;
    reg = arena->arena[(PC + 2) % MEM_SIZE];
    if (reg >= 1 && reg <= 16)
        my_memmove(&reg_value, head->registers[reg - 1], REG_SIZE);
    else
        return 84;
    reg_value = __builtin_bswap32(reg_value);
    snprintf(log, 256, "%s did the instruction aff, it display the ascii code of r%d = %x : ",
    head->team->war_header->prog_name, reg, reg_value);
    update_log(arena, head, log);
    printf("%c\n", reg_value % 256);
    post_inst(head, coding_byte, head->carry);
    return 0;
}
