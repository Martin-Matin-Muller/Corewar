/*
** EPITECH PROJECT, 2025
** project_name
** File description:
** ...
*/

#include "graphical.h"

const sfColor war_colors[] = {

    (sfColor){0, 255, 0},
    (sfColor){0, 0, 255},
    (sfColor){255, 0, 0},
    (sfColor){255, 255, 0},
    (sfColor){255, 255, 255}
};

void write_color_arena(arena_t *arena, type_t size, int pos, warrior_info_t *warrior)
{
    for (int i = pos; i < (size + pos); i++) {
        arena->colored_arena[i].r = warrior->war_color.r;
        arena->colored_arena[i].g = warrior->war_color.g;
        arena->colored_arena[i].b = warrior->war_color.b;
    }
}

//void write_color_reg(head_list_t *head, int reg)
//{
//    for (int i = 0; i < REG_SIZE; i++) {
//        head->reg_color[reg][i].r = head->team->war_color.r;
//        head->reg_color[reg][i].g = head->team->war_color.g;
//        head->reg_color[reg][i].b = head->team->war_color.b;
//    }
//}

bool is_reading_head(arena_t *arena, int index)
{
    for (head_list_t *head = arena->heads; head != NULL; head = head->next) {
        if (head->position == (unsigned int)index)
            return true;
    }
    return false;
}

void update_reg(arena_t *arena, head_list_t *head, int reg)
{
    arena->reg_to_display->head = head;
    arena->reg_to_display->reg = reg;
}

void draw_register(window_t *window, reg_changed_t *log)
{
    const float start_x = 110.f + 1500.f;
    const float start_y = 19.f;
    char hex[3];
    sfVector2f pos;

    if (log->head == NULL || (log->reg < 0 && log->reg > 15))
        return;
    for (int j = 0; j < REG_NUMBER; j++) {
        for (int k = 0; k < REG_SIZE; k++) {
            snprintf(hex, sizeof(hex), "%02x", (unsigned char)log->head->registers[j][k]);
            sfText *text = sfText_create();
            sfText_setFont(text, window->font);
            sfText_setCharacterSize(text, 14);
            sfText_setString(text, hex);
            if (j % 2 != 0) {
                pos = (sfVector2f){
                    start_x + k * 24.f + 100,
                    start_y + (j - 1) * 10.f
                };
            } else {
                pos = (sfVector2f){
                    start_x + k * 24.f,
                    start_y + j * 10.f
                };
            }
            sfText_setPosition(text, pos);
            sfText_setFillColor(text, log->head->reg_color[j][k]);
            sfRenderWindow_drawText(window->window, text, NULL);
            sfText_destroy(text);
        }
    }
}

void draw_control(window_t *window)
{
    char *controls[] = {
        "Slow Down : Ctrl + arrow Left",
        "Speed up : Ctrl + arrow Right",
        "Quit : Ctrl + Q"
    };

    for (int i = 0; i < 3; i++) {
        sfText *control = sfText_create();
        sfVector2f pos = {.x = 50 + 650 * i, .y = 910};
        sfText_setFont(control, window->font);
        sfText_setCharacterSize(control, 25);
        sfText_setString(control, controls[i]);
        sfText_setPosition(control, pos);
        sfText_setFillColor(control, sfWhite);
        sfRenderWindow_drawText(window->window, control, NULL);
        sfText_destroy(control);
    }
}

void draw_player(window_t *window, arena_t *arena, int i)
{
    sfText *war_name = sfText_create();
    sfText *alive = sfText_create();
    sfText *processes = sfText_create();
    sfVector2f pos_war_name = {.x = 50 + 400 * i, .y = 5};
    sfVector2f pos_alive = {.x = 50 + 400 * i, .y = 25};
    sfVector2f pos_processes = {.x = 50 + 400 * i, .y = 50};
    char *is_alive = arena->warriors[i].alive ? "alive" : "not alive";
    char *processes_str = malloc(sizeof(char) * 32);

    snprintf(processes_str, 32, "Nb processes : %d", arena->warriors[i].nb_process);
    sfText_setFont(war_name, window->font);
    sfText_setCharacterSize(war_name, 25);
    sfText_setString(war_name, arena->warriors[i].war_header->prog_name);
    sfText_setPosition(war_name, pos_war_name);
    sfText_setFillColor(war_name, sfWhite);
    sfRenderWindow_drawText(window->window, war_name, NULL);
    sfText_destroy(war_name);

    sfText_setFont(alive, window->font);
    sfText_setCharacterSize(alive, 25);
    if (arena->warriors[i].dead == true) {
        sfText_setString(alive, "dead");
        sfText_setFillColor(alive, sfRed);
    } else {
        sfText_setString(alive, is_alive);
        sfText_setFillColor(alive, sfWhite);
    }
    sfText_setPosition(alive, pos_alive);
    sfRenderWindow_drawText(window->window, alive, NULL);
    sfText_destroy(alive);

    sfText_setFont(processes, window->font);
    sfText_setCharacterSize(processes, 25);
    sfText_setString(processes, processes_str);
    sfText_setPosition(processes, pos_processes);
    sfText_setFillColor(processes, sfWhite);
    sfRenderWindow_drawText(window->window, processes, NULL);
    sfText_destroy(processes);
    free(processes_str);
}

void draw_players(window_t *window, arena_t *arena)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (arena->warriors[i].file != NULL)
            draw_player(window, arena, i);
    }
}

void draw_cycle(window_t *window, char *text, sfVector2f pos)
{
    sfText *text_to_display = sfText_create();

    sfText_setFont(text_to_display, window->font);
    sfText_setCharacterSize(text_to_display, 25);
    sfText_setString(text_to_display, text);
    sfText_setPosition(text_to_display, pos);
    sfText_setFillColor(text_to_display, sfWhite);
    sfRenderWindow_drawText(window->window, text_to_display, NULL);
    sfText_destroy(text_to_display);
}

void draw_cycles(window_t *window, arena_t *arena)
{
    char *cycle_to_die = malloc(64);
    char *total_cycle = malloc(64);
    char *live_cycle = malloc(64);
    sfVector2f pos_ctd = {.x = 150, .y = 125};
    sfVector2f pos_tc = {.x = 750, .y = 125};
    sfVector2f pos_lc = {.x = 1350, .y = 125};

    sprintf(cycle_to_die, "Cycle to die : %d / %d", arena->actual_cycle, arena->cycle_to_die);
    sprintf(total_cycle, "Total cycle : %d", arena->total_cycle);
    sprintf(live_cycle, "Live cycle : %d / %d", arena->live_cycle, NBR_LIVE);
    draw_cycle(window, cycle_to_die, pos_ctd);
    draw_cycle(window, total_cycle, pos_tc);
    draw_cycle(window, live_cycle, pos_lc);
    free(cycle_to_die);
    free(total_cycle);
    free(live_cycle);
}

void draw_arena(window_t *window, arena_t *arena)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        char hex[3];
        snprintf(hex, sizeof(hex), "%02x", arena->arena[i]);

        sfText *text = sfText_create();
        sfText_setFont(text, window->font);
        sfText_setCharacterSize(text, 16);
        sfText_setString(text, hex);

        sfVector2f pos = {
            (i % 128) * 14.f + 35,
            (i / 128) * 15.f + 175
        };
        sfText_setPosition(text, pos);
        sfColor temp = sfRed;
        if (!is_reading_head(arena, i)) {
            temp.r = arena->colored_arena[i].r;
            temp.g = arena->colored_arena[i].g;
            temp.b = arena->colored_arena[i].b;
        }
        sfText_setFillColor(text, temp);
        sfRenderWindow_drawText(window->window, text, NULL);
        sfText_destroy(text);
    }
}

void corewar_events(window_t *window)
{
    if (window->event.type == sfEvtClosed || (window->event.type == sfEvtKeyPressed &&
        (window->event.key.code == sfKeyQ && window->event.key.control == true)))
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtKeyPressed) {
        if ((window->event.key.code == sfKeyRight && window->event.key.control == true) && window->speed > MAX_SPEED)
            window->speed -= 5000;
        if ((window->event.key.code == sfKeyLeft && window->event.key.control == true) && window->speed < MIN_SPEED)
            window->speed += 5000;
    }
}

void init_window(window_t *window)
{
    window->mode = sfVideoMode_getDesktopMode();
    window->window = sfRenderWindow_create(window->mode, "Corewar",
        sfResize | sfClose, NULL);
    window->font = sfFont_createFromFile("B-CPE-200_corewar_binaries/B-CPE-200_binaries/vm/media/font/Teko-Regular.ttf");
    window->speed = 60000;
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfImage* icon = sfImage_createFromFile("/home/martin-muller/B-CPE-200-NCY-2-1-corewar-martin.muller/bonus/src/csfml_bonus/logo.png");
    if (!icon) {
        printf("image not found\n");
        return;
    }
    const sfUint8* pixels = sfImage_getPixelsPtr(icon);
    sfVector2u size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(window->window, size.x, size.y, pixels);
}
