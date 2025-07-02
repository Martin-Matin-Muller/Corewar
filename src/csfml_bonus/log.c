/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** log functions
*/

#include "graphical.h"
#include "../../include/my.h"
#include "../../include/op.h"

void draw_log(window_t *window, log_t *log)
{
    sfText *log_text = sfText_create();
    sfVector2f pos = {.x = 50, .y = 950};

    if (log->head != NULL && log->log != NULL) {
        sfText_setFont(log_text, window->font);
        sfText_setCharacterSize(log_text, 25);
        sfText_setString(log_text, log->log);
        sfText_setPosition(log_text, pos);
        sfText_setFillColor(log_text, sfWhite);
        //sfText_setFillColor(log_text, log->head->team->war_color);
        sfRenderWindow_drawText(window->window, log_text, NULL);
        sfText_destroy(log_text);
    }
}

void update_log(arena_t *arena, head_list_t *head, char *log)
{
    arena->log_to_display->head = head;
    if (arena->log_to_display->log)
        free(arena->log_to_display->log);
    if (log)
        arena->log_to_display->log = my_strdup(log);
}