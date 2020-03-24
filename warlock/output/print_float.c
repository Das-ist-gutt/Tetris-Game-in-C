/*
** EPITECH PROJECT, 2019
** print_float.c
** File description:
** float
*/

#include "warlock.h"

static int my_print_float_2(char *reversed, int digit)
{
    int i;

    for (i = 0; reversed[i] != '\0' && i < digit; i++)
        my_putchar(reversed[i]);
    my_putchar('.');
    if (reversed[i] == '\0')
        my_putstr("00");
    for (i = digit; reversed[i] != '\0'; i++)
        my_putchar(reversed[i]);
    return (0);
}

/*
\fn int my_print_float(float percent)
\brief print a float number.
\param percent : (float) the float number to print
on standard output.
\return 0.
*/

int my_print_float(float percent)
{
    int digit = 1;
    int noComma = 0;
    int d = 0;
    char str[30];
    char *reversed;
    char tempory;

    noComma = (float)percent * (float)100;
    digit = count_digit(&percent);
    while (noComma >= 10) {
        tempory = (noComma % 10);
        noComma = (noComma - tempory) / 10;
        str[d] = tempory + 48;
        d++;
    }
    str[d] = (noComma % 10) + 48;
    str[d + 1] = '\0';
    reversed = my_revstr(str);
    my_print_float_2(reversed, digit);
    return (0);
}
