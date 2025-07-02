/*
** EPITECH PROJECT, 2024
** my strlen
** File description:
** give the lenght of a string
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return (length);
}
