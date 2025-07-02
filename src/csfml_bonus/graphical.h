/*
** EPITECH PROJECT, 2025
** project_name
** File description:
** ...
*/

#ifndef GRAPHICAL_H
    #define GRAPHICAL_H

    #include "../../include/op.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>

    #define MAX_SPEED 0
    #define MIN_SPEED 100000

extern const sfColor war_colors[];

typedef struct {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font;
    int speed;
} window_t;

void draw_arena(window_t *window, arena_t *arena);
void draw_cycles(window_t *window, arena_t *arena);
void draw_players(window_t *window, arena_t *arena);
void draw_control(window_t *window);
void draw_register(window_t *window, reg_changed_t *log);
void draw_log(window_t *window, log_t *log);
void write_color_arena(arena_t *arena, type_t size, int pos, warrior_info_t *warrior);
//void write_color_reg(head_list_t *head, int reg);

void corewar_events(window_t *window);

void init_window(window_t *window);

#endif //GRAPHICAL_H
