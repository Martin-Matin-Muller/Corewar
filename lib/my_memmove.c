/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** memmove for corewar
*/

#include <stddef.h>
#include "op.h"

void my_memmove(void *dest, void *src, size_t n)
{
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    char *temp = malloc(sizeof(char) * n);

    for (int i = 0; i < (int) n; i++)
        temp[i % MEM_SIZE] = csrc[i % MEM_SIZE];
    for (int i = 0; i < (int) n; i++)
        cdest[i % MEM_SIZE] = temp[i % MEM_SIZE];
    free(temp);
}
