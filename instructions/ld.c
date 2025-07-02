/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** ld.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static void get_param(type_t *coding_byte, uint32_t *value_to_load,
    arena_t *arena, head_list_t *head, int *j, char *log)
{
    int addr = 0;
    int16_t offset = 0;

    if (coding_byte[0] == DIR) {
        my_memmove(value_to_load, &arena->arena[(PC + 2) %
            MEM_SIZE], DIR_SIZE);
        *value_to_load = __builtin_bswap32(*value_to_load);
    }
    if (coding_byte[0] == IND) {
        offset = 0;
        my_memmove(&offset, &arena->arena[(PC + 2) % MEM_SIZE],
            IND_SIZE);
        offset = __builtin_bswap16(offset);
        addr = (PC + (offset % IDX_MOD)) % MEM_SIZE;
        my_memmove(value_to_load, &arena->arena[addr % MEM_SIZE], REG_SIZE);
        *value_to_load = __builtin_bswap32(*value_to_load);
    }
    *j += snprintf(log, 256, "%s did the instruction ld, it load the value %x into ",
    head->team->war_header->prog_name, *value_to_load);
}

int case_ld(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], false);
    uint32_t value_to_load = 0;
    int reg = 0;
    bool carry = false;
    char *log = malloc(sizeof(char) * 256);
    int j = 0;

    get_param(coding_byte, &value_to_load, arena, head, &j, log);
    if (coding_byte[1] == REG) {
        reg = arena->arena[(PC + 2 + coding_byte[0]) % MEM_SIZE];
        if (reg >= 1 && reg <= 16) {
            value_to_load = PC + value_to_load % IDX_MOD;
            my_memmove(head->registers[reg - 1],
                &value_to_load, REG_SIZE);
            carry = true;
            snprintf(&log[j], 256 - j," r%d\n", reg);
            update_log(arena, head, log);
            update_reg(arena, head, reg - 1);
            //write_color_reg(head, reg - 1);
        }
    }
    post_inst(head, coding_byte, carry);
    return 0;
}
