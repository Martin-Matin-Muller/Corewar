/*
** EPITECH PROJECT, 2025
** op
** File description:
** all instructions
*/

#include "op.h"

const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive", &live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &case_ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", &case_st},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &add},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", &sub},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3", &and_i},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3", &or_i},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3", &xor_i},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &zjmp},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", &ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", &sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &fork_i},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &lld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", &lldi},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &lfork},
    {"aff", 1, {T_REG}, 16, 2, "aff", &aff},
    {0, 0, {0}, 0, 0, 0, NULL}
};
