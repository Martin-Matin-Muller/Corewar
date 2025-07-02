/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** task07
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int k = 0;

    while (k < n && s1[k] != '\0' && s2[k] != '\0') {
        if (s1[k] != s2[k]) {
            return s1[k] - s2[k];
        }
        k++;
    }
    if (k < n && (s1[k] != '\0' || s2[k] != '\0')) {
        return s1[k] - s2[k];
    }
    return 0;
}
