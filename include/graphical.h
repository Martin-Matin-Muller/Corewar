/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** ncurses graphical
*/

#ifndef GRAPHICAL_H
    #define GRAPHICAL_H

    #include "op.h"
    #include <fcntl.h>
    #include <ncurses.h>


void draw_arena_ncurses(WINDOW *win, arena_t *arena);
void print_stats_ncurses(WINDOW *win, arena_t *arena);
#endif //GRAPHICAL_H
