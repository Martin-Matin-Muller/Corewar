/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include <sys/stat.h>
#include "../parse_args.h"

int fill_warrior_cmd(warrior_info_t *warrior, FILE *file, int i)
{
    warrior[i].command =
        malloc(sizeof(char) * warrior[i].war_header->prog_size);
    if (!warrior[i].command)
        return 84;
    fseek(file, 0, SEEK_CUR);
    fread(warrior[i].command, sizeof(char),
        warrior[i].war_header->prog_size, file);
    return 0;
}
