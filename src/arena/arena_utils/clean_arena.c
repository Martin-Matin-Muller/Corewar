/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** init !
*/

#include "../../parsing/parse_args.h"
#include "../arena.h"
#include "../src/csfml_bonus/graphical.h"

void clean_arena(unsigned char *arena)
{
    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = '\0';
}

void clean_colored_arena(sfColor *arena)
{
    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = war_colors[4];
}