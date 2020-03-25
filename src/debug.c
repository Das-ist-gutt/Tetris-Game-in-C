/*
** EPITECH PROJECT, 2019
** DEBUG
** File description:
** Debug mode
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "tetris.h"

int debug(config_t *config)
{
    display_conf(config);
    debug_tetr();
    my_putstr("Press any key to start Tetris\n");
    getch();
    return (0);
}

void display_conf(config_t *config)
{
    void (*disp[8])(config_t *);

    disp[0] = &disp_left;
    disp[1] = &disp_right;
    disp[2] = &disp_turn;
    disp[3] = &disp_drop;
    disp[4] = &disp_quit;
    disp[5] = &disp_pause;
    disp[6] = &disp_int;
    my_putstr("*** DEBUG MODE ***\n");
    for (int i = 0; i < 7; i++)
        disp[i](config);
}

void disp_left(config_t *config)
{
    if (config->key_left == KEY_LEFT)
        my_printf("Key Left :  (left)\n");
    if (config->key_left == 32)
        my_printf("Key Left :  (space)\n");
    if (config->key_left == KEY_RIGHT)
        my_printf("Key Left :  (right)\n");
    if (config->key_left == KEY_UP)
        my_printf("Key Left :  (up)\n");
    if (config->key_left == KEY_DOWN)
        my_printf("Key Left :  (down)\n");
    if ((config->key_left >= 65 && config->key_left <= 90) ||
    (config->key_left >= 97 && config->key_left <= 122))
        my_printf("Key Left :  %c\n", config->key_left);
}

void disp_right(config_t *config)
{
    if (config->key_right == KEY_LEFT)
        my_printf("Key Right :  (left)\n");
    if (config->key_right == 32)
        my_printf("Key Right :  (space)\n");
    if (config->key_right == KEY_RIGHT)
        my_printf("Key Right :  (right)\n");
    if (config->key_right == KEY_UP)
        my_printf("Key Right :  (up)\n");
    if (config->key_right == KEY_DOWN)
        my_printf("Key Right :  (down)\n");
    if ((config->key_right >= 65 && config->key_right <= 90) ||
    (config->key_right >= 97 && config->key_right <= 122))
        my_printf("Key Right :  %c\n", config->key_right);
}

void disp_turn(config_t *config)
{
    if (config->key_turn == KEY_LEFT)
        my_printf("Key Turn :  (left)\n");
    if (config->key_turn == 32)
        my_printf("Key Turn :  (space)\n");
    if (config->key_turn == KEY_RIGHT)
        my_printf("Key Turn :  (right)\n");
    if (config->key_turn == KEY_UP)
        my_printf("Key Turn :  (up)\n");
    if (config->key_turn == KEY_DOWN)
        my_printf("Key Turn :  (down)\n");
    if ((config->key_turn >= 65 && config->key_turn <= 90) ||
    (config->key_turn >= 97 && config->key_turn <= 122))
        my_printf("Key Turn :  %c\n", config->key_turn);
}