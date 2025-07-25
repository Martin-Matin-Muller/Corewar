/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** and.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static int load_first_parameter(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *value1, int *j, char *log)
{
    int reg = 0;
    int16_t offset = 0;

    if (cb[0] == REG) {
        reg = arena->arena[(PC + 2) % MEM_SIZE];
        if (reg >= 1 && reg <= 16) {
            my_memmove(value1, head->registers[reg - 1], REG_SIZE);
            *j += snprintf(log, 256, "%s did the instruction AND between the value in r%d = %x",
     head->team->war_header->prog_name, reg, *value1);
        } else
            return 84;
    }
    if (cb[0] == DIR) {
        my_memmove(value1, &arena->arena[(PC + 2) % MEM_SIZE], DIR_SIZE);
        *j += snprintf(log, 256, "%s did the instruction  AND between the value %x",
     head->team->war_header->prog_name, *value1);
    }
    if (cb[0] == IND) {
        my_memmove(&offset, &arena->arena[(PC + 2) % MEM_SIZE],
            IND_SIZE);
        offset = __builtin_bswap16(offset);
        my_memmove(value1, &arena->arena[(PC +
            (offset % IDX_MOD)) % MEM_SIZE], REG_SIZE);
        *j += snprintf(log, 256, "%s did the instruction AND between the value %x",
     head->team->war_header->prog_name, *value1);
    }
    return 0;
}

static int load_second_parameter(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *val, int *j, char *log)
{
    int reg = 0;
    int16_t offset = 0;

    if (cb[1] == REG) {
        reg = arena->arena[(PC + 2 + cb[0]) % MEM_SIZE];
        if (reg >= 1 && reg <= 16) {
            my_memmove(val, head->registers[reg - 1], REG_SIZE);
            *j += snprintf(&log[*j], 256 - *j, " and the value in r%d = %x", reg, *val);
        } else
            return 84;
    }
    if (cb[1] == DIR) {
        my_memmove(val, &arena->arena[(PC + 2 + cb[0]) % MEM_SIZE], DIR_SIZE);
        *j += snprintf(&log[*j], 256 - *j, " and the value %x", *val);
     }
    if (cb[1] == IND) {
        my_memmove(&offset, &arena->arena[(PC + 2) % MEM_SIZE], IND_SIZE);
        offset = __builtin_bswap16(offset);
        my_memmove(val, &arena->arena[(PC +
            (offset % IDX_MOD)) % MEM_SIZE], REG_SIZE);
        *j += snprintf(&log[*j], 256 - *j, " and the value %x", *val);
    }
    return 0;
}

static int put_result(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *result, int *j, char *log)
{
    int reg = 0;

    reg = arena->arena[(PC + 2 + cb[0] + cb[1]) % MEM_SIZE];
    *result = __builtin_bswap32(*result);
    if (reg >= 1 && reg <= 16) {
        my_memmove(head->registers[reg - 1], result, REG_SIZE);
        *j += snprintf(&log[*j], 256 - *j, " and store it in r%d\n", reg);
        update_reg(arena, head, reg - 1);
        //write_color_reg(head, reg - 1);
    } else
        return 0;
    return 0;
}

int and_i(arena_t *arena, head_list_t *head)
{
    type_t *cb = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], false);
    uint32_t value1 = 0;
    uint32_t value2 = 0;
    uint32_t result = 0;
    bool carry = true;
    char *log = malloc(sizeof(char) * 256);
    int j = 0;

    if (cb[0] == NONE || cb[1] == NONE || cb[2] != REG)
        carry = false;
    else {
        if (load_first_parameter(arena, head, cb, &value1, &j, log) == 84 ||
            load_second_parameter(arena, head, cb, &value2, &j, log) == 84)
            carry = false;
        if (carry != false) {
            result = __builtin_bswap32(value1) & __builtin_bswap32(value2);
            put_result(arena, head, cb, &result, &j, log);
        }
    }
    post_inst(head, cb, carry);
    return 0;
}
