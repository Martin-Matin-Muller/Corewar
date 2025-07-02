/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** printf but mini
*/
#include <stdarg.h>
#include "../../include/my.h"

int count_nb(int *ptr, int nb)
{
    while (nb != 0) {
        nb = nb / 10;
        *ptr = *ptr + 1;
    }
    return 0;
}

int sec_find_type(const char *format, int i, va_list list, int *ptr)
{
    if (format[i + 1] == 'c') {
        my_putchar(va_arg(list, int));
        *ptr = *ptr + 1;
        i++;
        return i;
    }
    if (format[i + 1] == '%') {
        my_putchar('%');
        *ptr = *ptr + 1;
        i++;
        return i;
    } else {
        my_putchar(format[i]);
        return i;
    }
}

int find_type(const char *format, int i, va_list list, int *ptr)
{
    char *save;
    int nb = 0;

    if (format[i + 1] == 'i' || format[i + 1] == 'd') {
        nb = va_arg(list, int);
        my_put_nbr(nb);
        count_nb(ptr, nb);
        i++;
        return i;
    }
    if (format[i + 1] == 's') {
        save = va_arg(list, char *);
        my_putstr(save);
        *ptr = *ptr + my_strlen(save);
        save = "";
        i++;
        return i;
    }
    i = sec_find_type(format, i, list, ptr);
    return i;
}

int if_space(const char *format, int i)
{
    while (format[i + 1] == ' ') {
        i++;
    }
    return i;
}

int mini_printf(const char *format, ...)
{
    int count = 0;
    int *ptr = &count;
    va_list list;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i = if_space(format, i);
            i = find_type(format, i, list, ptr);
            continue;
        }
        my_putchar(format[i]);
        *ptr = *ptr + 1;
    }
    va_end(list);
    return count;
}
