/*
** EPITECH PROJECT, 2025
** the .h of arena
** File description:
** arena.h
*/

#ifndef ARENA_H
    #define ARENA_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <alloca.h>
    #include <string.h>
    #include "../../include/my.h"
    #include "op.h"

//init_arena.c
//init the arena struct
int init_arena(arena_t **arena_ptr, int ac);

//free_arena.c
//free the arena struct
void free_arena(arena_t *arena);

//clean_arena.c
//fill the arena with 00
void clean_arena(unsigned char *arena);

//clean_colored_arena.c
//fill the colors
void clean_colored_arena(sfColor *arena);

//place_warriors.c
//place the warrior's instruction at equidistance in the arena
void place_warriors(arena_t *arena);

//get_equidistance.c
//get the equidistance
int get_equidistance_value(arena_t *arena);

#endif
