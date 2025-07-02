/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include <sys/stat.h>
#include "../parse_args.h"

static void change_same_value(int *first_def, warrior_info_t *warriors, int i)
{
    for (int j = 0; j < MAX_ARGS_NUMBER; j++) {
        if (i != j &&
            warriors[i].nb_name == warriors[j].nb_name) {
            warriors[j].nb_name++;
            *first_def = 0;
            return;
        }
    }
    return;
}

void set_nb_name(warrior_info_t *warriors)
{
    int default_nb = 1;
    int first_def = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (warriors[i].file == NULL)
            continue;
        if (warriors[i].nb_name == -1) {
            warriors[i].nb_name = default_nb;
            default_nb++;
        }
    }
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        first_def = 0;
        while (first_def == 0) {
            first_def = 1;
            change_same_value(&first_def, warriors, i);
        }
    }
}
