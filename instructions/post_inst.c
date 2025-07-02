/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** post instructions
*/

#include "op.h"

int post_inst(head_list_t *head, type_t *coding_byte, bool carry)
{
    if (coding_byte) {
        PC = (PC + 1) % MEM_SIZE;
        for (int i = 0; i < 4; i++) {
            PC = (PC + coding_byte[i]) % MEM_SIZE;
        }
        free(coding_byte);
    }
    PC = (PC + 1) % MEM_SIZE;
    head->carry = carry;
    return 0;
}
