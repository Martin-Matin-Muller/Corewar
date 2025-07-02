/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** parse and fill a information structure
*/

#include <sys/stat.h>
#include "../parse_args.h"

static int verify_if_header_valid(warrior_info_t *warrior, int i, FILE *file)
{
    struct stat sb;

    if (stat(warrior[i].file, &sb) == -1 ||
        (long unsigned int) sb.st_size < sizeof(header_t))
        return 84;
    fread(warrior[i].war_header, sizeof(header_t), 1, file);
    warrior[i].war_header->magic = __builtin_bswap32(
                                    warrior[i].war_header->magic);
    warrior[i].war_header->prog_size = __builtin_bswap32(
                                    warrior[i].war_header->prog_size);
    if (warrior[i].war_header->magic != 15369203 ||
            ((int) sb.st_size - (int) sizeof(header_t)) !=
            warrior[i].war_header->prog_size)
        return 84;
    return 0;
}

static int verify_valid_file(warrior_info_t *warrior, int i)
{
    FILE *file;

    file = fopen(warrior[i].file, "rb");
    if (file == NULL)
        return 84;
    if (verify_if_header_valid(warrior, i, file) == 84 ||
        fill_warrior_cmd(warrior, file, i)) {
        fclose(file);
        return 84;
    }
    set_nb_name(warrior);
    fclose(file);
    return 0;
}

int check_file(warrior_info_t *warrior)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (warrior[i].file == NULL)
            continue;
        if (verify_valid_file(warrior, i) == 84)
            return 84;
    }
    return 0;
}
