/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** st.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static void load_value(arena_t *arena, head_list_t *head,
    type_t *coding_byte, uint32_t *value_to_load, int *j, char *log)
{
    int reg = 0;
    uint32_t position_to_load = 0;

    if (coding_byte[1] == REG) {
        reg = arena->arena[(PC + 2 + coding_byte[0]) % MEM_SIZE];
        if (reg >= 1 && reg <= 16) {
            my_memmove(head->registers[reg - 1],
                value_to_load, REG_SIZE);
            *j += snprintf(&log[*j], 256 - *j, " into the register r%d\n",reg);
            update_reg(arena, head, reg - 1);
            //write_color_reg(head, reg - 1);
        }
    } else if (coding_byte[1] == IND) {
        my_memmove(&position_to_load, &arena->arena[(PC +
            2 + coding_byte[0]) % MEM_SIZE], coding_byte[1]);
        position_to_load = __builtin_bswap16(position_to_load);
        *value_to_load = __builtin_bswap32(*value_to_load);
        *value_to_load = __builtin_bswap16(*value_to_load);
        my_memmove(&arena->arena[PC + 2 + position_to_load % IDX_MOD],
            value_to_load, coding_byte[1]);
        write_color_arena(arena, IND, PC + 2 + position_to_load % IDX_MOD, head->team);
    snprintf(&log[*j], 256 - *j, " at the position %d\n",
    PC + 2 + position_to_load % IDX_MOD);
    }
}

int case_st(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], false);
    uint32_t value_to_load = 0;
    int reg = 0;
    char *log = malloc(sizeof(char) * 256);
    int j = 0;

    if (coding_byte[0] == REG) {
        reg = arena->arena[(PC + 2) % MEM_SIZE];
        if (reg >= 1 && reg <= 16) {
            my_memmove(&value_to_load, head->registers[reg - 1],
                REG_SIZE);
    j += snprintf(log, 256, "%s did the instruction st, it store the value in r%d = %x",
    head->team->war_header->prog_name, reg, value_to_load);
        }
    }
    load_value(arena, head, coding_byte, &value_to_load, &j, log);
    post_inst(head, coding_byte, head->carry);
    free(log);
    return 0;
}
