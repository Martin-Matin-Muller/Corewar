/*
** EPITECH PROJECT, 2024
** my strncpy
** File description:
** copy a source str until n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
