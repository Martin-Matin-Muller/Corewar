/*
** EPITECH PROJECT, 2025
** Robot factory
** File description:
** my.h
*/


#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include "op.h"

void my_putchar(char c);
void my_swap(int *a, int *b);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char *str, int nb_words);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
int my_atoi(char *str);
int binary_to_decimal(int n);
int my_put_nbr(long nb);
int my_putstr(char const *str);
void my_memmove(void *dest, void *src, size_t n);
int mini_printf(const char *format, ...);

#endif //MY_H
