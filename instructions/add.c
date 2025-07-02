/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** add.c
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/op.h"
#include "../src/csfml_bonus/graphical.h"

static int *find_reg(bool *carry, arena_t *arena,
                     head_list_t *head, type_t *coding_byte)
{
    int *regs = malloc(sizeof(int) * 3);

    for (int i = 0; i < 3; i++)
        regs[i] = -1;
    if (coding_byte[0] == REG && coding_byte[1] == REG &&
        coding_byte[2] == REG) {
        regs[0] = arena->arena[(PC + 2)] %
            MEM_SIZE;
        regs[1] = arena->arena[(PC + 2 + coding_byte[0])] %
            MEM_SIZE;
        regs[2] = arena->arena[(PC + 2 + coding_byte[0] +
            coding_byte[1])] % MEM_SIZE;
    } else
        *carry = false;
    return regs;
}

static uint32_t calcul_value3(uint32_t *value1, uint32_t *value2,
    head_list_t *head, int *regs)
{
    uint32_t value3 = 0;

    *value1 = __builtin_bswap32(*((int *)head->registers[regs[0] - 1]));
    *value2 = __builtin_bswap32(*((int *)head->registers[regs[1] - 1]));
    value3 = *value1 + *value2;
    return value3;
}

int add(arena_t *arena, head_list_t *head)
{
    type_t *coding_byte = read_coding_byte(
        (int)arena->arena[(PC + 1) % MEM_SIZE], false);
    uint32_t value1 = 0;
    uint32_t value2 = 0;
    uint32_t value3 = 0;
    bool carry = true;
    int *regs = find_reg(&carry, arena, head, coding_byte);
    char log[256];

    if (regs[0] < 1 || regs[0] > 16 ||
        regs[1] < 1 || regs[1] > 16 ||
        regs[2] < 1 || regs[2] > 16) {
        post_inst(head, coding_byte, false);
        free(regs);
        return 0;
    }
    value3 = __builtin_bswap32(calcul_value3(&value1, &value2, head, regs));
    my_memmove(head->registers[regs[2] - 1], &value3, REG_SIZE);
    post_inst(head, coding_byte, carry);
    value3 = __builtin_bswap32(value3);
    snprintf(log, 256, "%s did the instruction add, it add r%d = %x, r%d = %x into r%d now equals to %x\n",
    head->team->war_header->prog_name, regs[0], value1, regs[1], value2, regs[2], value3);
    update_log(arena, head, log);
    update_reg(arena, head, regs[2] - 1);
    //write_color_reg(head, regs[2] - 1);
    free(regs);
    return 0;
}
