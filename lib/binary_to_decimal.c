/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/
#include "my.h"
#include <string.h>

int binary_to_decimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    int last_digit;

    while (temp) {
        last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}
