/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** head linked_list functions
*/
#include <time.h>
#include <stdio.h>
#include <ncurses.h>
#include "../include/my.h"
#include "../include/op.h"
#include "csfml_bonus/graphical.h"

static int init_registers(head_list_t *head)
{
    uint32_t set_value = 0;

    head->registers = malloc(sizeof(char *) * REG_NUMBER);
    if (!head->registers)
        return 84;
    for (int i = 0; i < REG_NUMBER; i++) {
        head->registers[i] = malloc(sizeof(char) * REG_SIZE);
        if (!head->registers[i])
            return 84;
        my_memmove(head->registers[i], &set_value, REG_SIZE);
    }
    head->reg_color = malloc(sizeof(sfColor *) * REG_NUMBER);
    if (!head->reg_color)
        return 84;
    for (int i = 0; i < REG_NUMBER; i++) {
        head->reg_color[i] = malloc(sizeof(sfColor) * REG_SIZE);
        if (!head->registers[i])
            return 84;
        for (int j = 0; j < REG_SIZE; j++) {
            head->reg_color[i][j] = sfWhite;
        }
    }
    return 0;
}

void add_head(head_list_t **reading_heads, warrior_info_t *team,
    unsigned int position, int cooldown)
{
    head_list_t *new_head = malloc(sizeof(head_list_t));

    if (new_head == NULL)
        return;
    new_head->team = team;
    new_head->position = position;
    new_head->cooldown = cooldown;
    new_head->pending_instruction = 0;
    new_head->carry = false;
    init_registers(new_head);
    new_head->next = *reading_heads;
    *reading_heads = new_head;
}

static int free_registers(head_list_t *head)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        if (head->registers[i])
            free(head->registers[i]);
        if (head->reg_color[i])
            free(head->reg_color[i]);
    }
    free(head->registers);
    free(head->reg_color);
    return 0;
}

void free_head_list(head_list_t *curr)
{
    if (curr == NULL)
        return;
    free_registers(curr);
    free_head_list(curr->next);
    free(curr);
}

static int find_instructions(char value)
{
    for (int i = 0; op_tab[i].code != 0; i++) {
        if (value == op_tab[i].code)
            return i;
    }
    return -1;
}

static void do_instruction(arena_t *arena, head_list_t *tmp)
{
    int attempts = 0;
    int index = -1;

    while (attempts < MEM_SIZE) {
        index = find_instructions(arena->arena[tmp->position]);
        if (index != -1)
            break;
        tmp->position = (tmp->position + 1) % MEM_SIZE;
        attempts++;
    }
    if (index != -1) {
        tmp->cooldown = op_tab[index].nbr_cycles - 1;
        tmp->pending_instruction = index;
    }
}

int move_head(arena_t *arena)
{
    head_list_t *tmp = arena->heads;

    while (tmp) {
        if (tmp->cooldown > 0)
            tmp->cooldown -= 1;
        else {
            do_instruction(arena, tmp);
            printf("\n");
        }
        if (tmp->cooldown == 0 && tmp->pending_instruction != -1) {
            op_tab[tmp->pending_instruction].inst(arena, tmp);
            tmp->pending_instruction = -1;
        }
        tmp = tmp->next;
    }
    arena->actual_cycle += 1;
    arena->total_cycle += 1;
    return 0;
}
