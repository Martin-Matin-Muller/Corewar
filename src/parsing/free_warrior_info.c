/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include "parse_args.h"

void free_warrior_info(warrior_info_t *warrior)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (warrior[i].file != NULL)
            free(warrior[i].file);
        if (warrior[i].war_header != NULL)
            free(warrior[i].war_header);
        if (warrior[i].command != NULL)
            free(warrior[i].command);
    }
}
