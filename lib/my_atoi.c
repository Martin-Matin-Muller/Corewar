/*
** EPITECH PROJECT, 2024
** my strlen
** File description:
** give the lenght of a string
*/

int my_atoi(char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ')
        str++;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;
    if (*str < '0' || *str > '9')
        return -4242;
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    result *= sign;
    return result;
}
