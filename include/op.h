/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** op.h
*/

#ifndef _OP_H_
    #define _OP_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <SFML/Graphics/Color.h>


    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

/*
**
*/
typedef char args_type_t;

    #define T_REG 1 /* register */
    #define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4 /*ind is relative (ld 1,r1 put (1+pc) -> r1 (4 bytes))*/
    #define T_LAB 8 /* LABEL */

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

typedef enum {
    REG = 1,
    DIR = 4,
    IND = 2,
    INDEX = 2,
    NONE = 0,
} type_t;

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct warrior_info {
    int nb_name;
    int address;
    char *file;
    unsigned int nb_process;
    header_t *war_header;
    char *command;
    bool alive;
    sfColor war_color;
    bool dead;
} warrior_info_t;

typedef struct head_list_s {
    warrior_info_t *team;
    unsigned int position;
    unsigned int cooldown;
    bool carry;
    int pending_instruction;
    char **registers; //registers[REG_NUMBER][REG_SIZE];
    sfColor **reg_color;
    struct head_list_s *next;
} head_list_t;

    #define PC head->position

typedef struct log_s {
    head_list_t *head;
    char *log;
} log_t;

typedef struct reg_changed {
    head_list_t *head;
    int reg;
} reg_changed_t;

typedef struct arena_s {
    unsigned int live_cycle;
    unsigned int actual_cycle;
    unsigned int total_cycle;
    unsigned int cycle_to_die;
    unsigned char *arena;
    sfColor *colored_arena;
    warrior_info_t *warriors;
    head_list_t *heads;
    int dump;
    log_t *log_to_display;
    reg_changed_t *reg_to_display;
} arena_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int (*inst)(arena_t *, head_list_t *);
} op_t;

/*
** op_tab
*/
extern const op_t op_tab[];

// instructions
int zjmp(arena_t *arena, head_list_t *head);
int xor_i(arena_t *arena, head_list_t *head);
int sub(arena_t *arena, head_list_t *head);
int sti(arena_t *arena, head_list_t *head);
int case_st(arena_t *arena, head_list_t *head);
int or_i(arena_t *arena, head_list_t *head);
int lldi(arena_t *arena, head_list_t *head);
int lld(arena_t *arena, head_list_t *head);
int live(arena_t *arena, head_list_t *head);
int lfork(arena_t *arena, head_list_t *head);
int ldi(arena_t *arena, head_list_t *head);
int case_ld(arena_t *arena, head_list_t *head);
int fork_i(arena_t *arena, head_list_t *head);
void copy_head(head_list_t **reading_heads, head_list_t *head, int position);
int and_i(arena_t *arena, head_list_t *head);
int aff(arena_t *arena, head_list_t *head);
int add(arena_t *arena, head_list_t *head);
int post_inst(head_list_t *head, type_t *coding_byte,
    bool carry);

void update_log(arena_t *arena, head_list_t *head, char *log);
void update_reg(arena_t *arena, head_list_t *head, int reg);

//heads functions
void add_head(head_list_t **reading_heads, warrior_info_t *team,
    unsigned int position, int cooldown);
void free_head_list(head_list_t *curr);
int move_head(arena_t *arena);

type_t *read_coding_byte(int nb, bool is_index);

char *find_warrior_by_number(warrior_info_t *warriors, uint32_t war_number);

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before being declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

#endif
