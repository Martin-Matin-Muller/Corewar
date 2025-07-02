/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int comp = 0;

    for (; s1[comp] != '\0' || s2[comp] != '\0'; comp++) {
        if (s1[comp] != s2[comp])
            return (s1[comp] - s2[comp]);
    }
    return (s1[comp] - s2[comp]);
}
