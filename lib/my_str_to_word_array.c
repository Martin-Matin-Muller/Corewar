/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** str to word array stumper 1
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

static int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == ',')
        return 1;
    return 0;
}

static void increm(int *i, int *word_len, int *a_index)
{
    *i += *word_len;
    *word_len = 0;
    *a_index += 1;
}

int how_many_words(char *str)
{
    int nb_words = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == ',') {
            i++;
        }
        if (str[i] != '\0')
            nb_words++;
        while (str[i] != ' ' && str[i] != '\t'
            && str[i] != '\0' && str[i] == ',') {
            i++;
        }
        i++;
    }
    return nb_words;
}

static void ignore_space(char *str, int *i, int *j)
{
    while (is_space(str[*i]) == 1)
        *i += 1;
    *j = *i;
}

static void through_word(char *str, int *i, int *j, int *word_len)
{
    while (is_space(str[*j]) == 0 && str[*j] != '\0')
        *j += 1;
    *word_len = *j - *i;
}

void *apply_func(void *value)
{
    char *str = (char *)value;

    if (str[my_strlen(str) - 1] == 'e')
        str[my_strlen(str) - 1] = '\0';
    return str;
}

char **my_str_to_word_array(char *str, int nb_words)
{
    char **result = malloc(sizeof(char *) * (nb_words + 1));
    int word_len = 0;
    int a_index = 0;
    int i = 0;
    int j = 0;

    if (result == NULL)
        return NULL;
    while (str[i] != '\0' && a_index < nb_words) {
        ignore_space(str, &i, &j);
        through_word(str, &i, &j, &word_len);
        result[a_index] = malloc(sizeof(char) * word_len + 1);
        if (result[a_index] == NULL)
            return NULL;
        result[a_index] = my_strncpy(result[a_index], &str[i], word_len);
        increm(&i, &word_len, &a_index);
    }
    result[a_index] = NULL;
    return result;
}
