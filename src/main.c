/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** THE MAIIIIIIIIIN !
*/

#include "parsing/parse_args.h"
#include "arena/arena.h"
#include "op.h"
#include "csfml_bonus/graphical.h"

static int is_game_over(warrior_info_t last_alive, int alive)
{
    if (alive == 1) {
        mini_printf("The player %d(%s)has won.\n",
            last_alive.nb_name, last_alive.war_header->prog_name);
        return 1;
    } else if (alive == 0) {
        mini_printf("all programs are dead, it's a tie\n");
        return 1;
    }
    return 0;
}

int check_live(arena_t *arena)
{
    int alive = 0;
    warrior_info_t last_alive;

    if (arena->actual_cycle < arena->cycle_to_die)
        return 0;
    for (int i = 0; i < MAX_ARGS_NUMBER &&
        arena->warriors[i].file != NULL; i++) {
        if (arena->warriors[i].alive == true) {
            alive += 1;
            last_alive = arena->warriors[i];
            arena->warriors[i].alive = false;
        } else
            arena->warriors[i].dead = true;
    }
    if (is_game_over(last_alive, alive) == 1)
        return 1;
    arena->actual_cycle = 0;
    return 0;
}

void write_char_as_hex(char c)
{
    char hex[] = "0123456789abcdef";
    char output[2];

    output[0] = hex[(c >> 4) & 0xF];
    output[1] = hex[c & 0xF];
    write(1, output, 2);
}

static void dump_arena(arena_t *arena)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        write_char_as_hex(arena->arena[i]);
        if ((i + 1) % 32 == 0)
            write(1, "\n", 1);
    }
}

void corewar(arena_t *arena) {
    window_t window = { 0 };

    init_window(&window);

    if (!window.window)
        return;
    while (sfRenderWindow_isOpen(window.window) && check_live(arena) == 0) {
        while (sfRenderWindow_pollEvent(window.window, &window.event)) {
            corewar_events(&window);
        }
        move_head(arena);
        if (arena->live_cycle >= NBR_LIVE) {
            arena->cycle_to_die -= CYCLE_DELTA;
            arena->live_cycle = 0;
        }
        sfRenderWindow_clear(window.window, sfBlack);
        draw_players(&window, arena);
        draw_arena(&window, arena);
        draw_cycles(&window, arena);
        draw_control(&window);
        draw_log(&window, arena->log_to_display);
        draw_register(&window, arena->reg_to_display);
        sfRenderWindow_display(window.window);
        sfSleep((sfTime){.microseconds = window.speed});
    }
    sfRenderWindow_destroy(window.window);
}

static int dump_help(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf("USAGE\n"
        "\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n"
        "DESCRIPTION\n"
        "\t-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn't\n"
        "\talready over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n"
        "\t-n prog_number sets the next program's number. By default, the first free number in the\n"
        "\tparameter order\n"
        "\t-a load_address sets the next program's loading address. When no address is specified,\n"
        "\toptimize the addresses so that the processes are as far away from each other as\n"
        "\tpossible. The addresses are MEM_SIZE modulo.\n"
        "BONUS\n"
        "\tOn the branch bonus, we have a graphical representation of the arena, with some information\n"
        "\tabout the champion.\n"
        "\tYou can directly put .s champion file as argument instead of the .cor champion file.\n"
        );
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    arena_t *arena = NULL;

    if (dump_help(ac, av) == 1)
        return 0;
    if (init_arena(&arena, ac) == 84) {
        free_arena(arena);
        return 84;
    }
    if (check_argument(arena->warriors, av, &arena->dump) == 84 ||
        check_file(arena->warriors) == 84) {
        free_arena(arena);
        return 84;
    }
    place_warriors(arena);
    corewar(arena);
    free_arena(arena);
    return 0;
}
