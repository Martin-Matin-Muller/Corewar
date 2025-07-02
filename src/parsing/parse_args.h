/*
** EPITECH PROJECT, 2025
** the .h of arena
** File description:
** arena.h
*/

#ifndef PARSE_ARGS_H
    #define PARSE_ARGS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <alloca.h>
    #include <string.h>
    #include "../../include/my.h"

//is_int.c
//check if it's an int
int is_int(char *str);

//is_a_dot_cor.c
//check if it's a .cor
int is_a_dot_cor(char *file);

//free_warrior_info.c
//free the warrior_info struct and the dump string
void free_warrior_info(warrior_info_t *warrior);

//is_enough_warrior.c
//check if there is at least 2 warriors
int is_enough_warrior(warrior_info_t *warrior);

//fill_file.c
//fill with file name in the info struct
int fill_file(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb);

//fill_dump.c
//fill with dump value in the info struct
int fill_dump(char **av, int *dump, int *arg_pos);

//fill_adresse.c
//fill with adresse value in the info struct
int fill_adresse(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb);

//fill_nb_name.c
//fill with nb of the processus(like a name or id) in the info struct
int fill_nb_name(warrior_info_t *warrior, char **av, int *arg_pos,
    int *war_nb);

//fill_warrior_info.c
//fill all value in the info struct
int fill_warrior_info(warrior_info_t *warrior, char **av, int *arg_pos);

//fill_warrior_cmd.c
//fill the cahr *command of the warrior
int fill_warrior_cmd(warrior_info_t *warrior, FILE *file, int i);

//set_nb_name.c
//set nb_name if there's not, and change value in case of same value
void set_nb_name(warrior_info_t *warriors);

//check_file.c
//check if the file is valid
int check_file(warrior_info_t *warrior);

//check_argument.c
//check if the argument is valid
int check_argument(warrior_info_t *warrior, char **av, int *dump);


#endif
