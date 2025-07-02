/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** ldi.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static void load_ind(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *value1)
{
    int16_t addr = 0;
    int real_addr = 0;

    my_memmove(&addr, &arena->arena[(PC + 2 + cb[0] + cb[1]) %
        MEM_SIZE], IND_SIZE);
    addr = __builtin_bswap16(addr);
    real_addr = (PC + addr % IDX_MOD) % MEM_SIZE;
    if (real_addr < 0)
        real_addr += MEM_SIZE;
    my_memmove(value1, &arena->arena[real_addr], REG_SIZE);
}

static int load_first_parameter(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *value1)
{
    int reg = 0;

    if (cb[0] == REG) {
        reg = arena->arena[(PC + 2) % MEM_SIZE];
        if (reg >= 1 && reg <= 16)
            my_memmove(value1, head->registers[reg - 1], REG_SIZE);
        else
            return 84;
    }
    if (cb[0] == DIR) {
        my_memmove(value1,
        &arena->arena[(PC + 2) % MEM_SIZE], DIR_SIZE);
    }
    if (cb[0] == IND) {
        load_ind(arena, head, cb, value1);
    }
    return 0;
}

static int load_second_parameter(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t *val)
{
    int reg = 0;

    if (cb[0] == REG) {
        reg = arena->arena[(PC + 2) % MEM_SIZE];
        if (reg >= 1 && reg <= 16)
            my_memmove(val, head->registers[reg - 1], REG_SIZE);
        else
            return 84;
    }
    if (cb[0] == DIR) {
        my_memmove(val,
        &arena->arena[(PC + 2) % MEM_SIZE], DIR_SIZE);
    }
    if (cb[0] == IND) {
        load_ind(arena, head, cb, val);
    }
    return 0;
}

static int put_result(arena_t *arena, head_list_t *head, type_t *cb,
    uint32_t sum)
{
    int reg = 0;
    uint32_t value = 0;
    int addr = (PC + sum) % MEM_SIZE;
    char log[256];

    reg = arena->arena[(PC + 2 + cb[0] + cb[1]) % MEM_SIZE];
    if (reg >= 1 && reg <= 16) {
        if (addr < 0)
            addr += MEM_SIZE;
        my_memmove(&value, &arena->arena[addr], REG_SIZE);
        value = __builtin_bswap32(value);
        my_memmove(head->registers[reg - 1], &value, REG_SIZE);
        update_reg(arena, head, reg - 1);
        //write_color_reg(head, reg - 1);
    } else {
        return 84;
    }
    snprintf(log, 256, "%s did the instruction ldi, it load in r%d the sum %x",
     head->team->war_header->prog_name, reg, sum);
    update_log(arena, head, log);
    return 0;
}

static uint32_t sum_calcul(uint32_t *val1, uint32_t *val2)
{
    uint32_t sum = (__builtin_bswap32(*val1) +
        __builtin_bswap32(*val2)) % IDX_MOD;

    return sum;
}

int ldi(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], true);
    uint32_t val1 = 0;
    uint32_t val2 = 0;
    uint32_t sum = 0;
    bool carry = true;

    if (coding_byte[0] == NONE || coding_byte[1] == NONE ||
        coding_byte[2] != REG)
        carry = false;
    else {
        if (load_first_parameter(arena, head, coding_byte, &val1) == 84 ||
        load_second_parameter(arena, head, coding_byte, &val2) == 84)
            carry = false;
        sum = sum_calcul(&val1, &val2);
        put_result(arena, head, coding_byte, sum);
    }
    post_inst(head, coding_byte, carry);
    return 0;
}
