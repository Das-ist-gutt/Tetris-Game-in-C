/*
** EPITECH PROJECT, 2019
** DEBUG_SEC
** File description:
** Debug second file
*/

#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

void disp_drop(config_t *config)
{
    if (config->key_drop == KEY_LEFT)
        my_printf("key Drop :  (left)\n");
    if (config->key_drop == 32)
        my_printf("key Drop :  (space)\n");
    if (config->key_drop == KEY_RIGHT)
        my_printf("key Drop :  (right)\n");
    if (config->key_drop == KEY_UP)
        my_printf("key Drop :  (up)\n");
    if (config->key_drop == KEY_DOWN)
        my_printf("key Drop :  (down)\n");
    if ((config->key_drop >= 65 && config->key_drop <= 90) ||
    (config->key_drop >= 97 && config->key_drop <= 122))
        my_printf("key Drop :  %c\n", config->key_drop);
}

void disp_quit(config_t *config)
{
    if (config->key_quit == KEY_LEFT)
        my_printf("key Quit :  (left)\n");
    if (config->key_quit == 32)
        my_printf("key Quit :  (space)\n");
    if (config->key_quit == KEY_RIGHT)
        my_printf("key Quit :  (right)\n");
    if (config->key_quit == KEY_UP)
        my_printf("key Quit :  (up)\n");
    if (config->key_quit == KEY_DOWN)
        my_printf("key Quit :  (down)\n");
    if ((config->key_quit >= 65 && config->key_quit <= 90) ||
    (config->key_quit >= 97 && config->key_quit <= 122))
        my_printf("key Quit :  %c\n", config->key_quit);
}

void disp_pause(config_t *config)
{
    if (config->key_pause == KEY_LEFT)
        my_printf("key Pause :  (left)\n");
    if (config->key_pause == 32)
        my_printf("key Pause :  (space)\n");
    if (config->key_pause == KEY_RIGHT)
        my_printf("key Pause :  (right)\n");
    if (config->key_pause == KEY_UP)
        my_printf("key Pause :  (up)\n");
    if (config->key_pause == KEY_DOWN)
        my_printf("key Pause :  (down)\n");
    if ((config->key_pause >= 65 && config->key_pause <= 90) ||
    (config->key_pause >= 97 && config->key_pause <= 122))
        my_printf("key Pause :  %c\n", config->key_pause);
}

void disp_int(config_t *config)
{
    if (config->hide == 1)
        my_printf("Next :  Yes\n");
    else
        my_printf("Next :  No\n");
    my_printf("Level :  %i\n", config->level);
    my_printf("Size :  %i*%i\n", config->size_x, config->size_y);
}

void print_error(char *name)
{
    int i = 0;

    my_printf("Tetriminos :  Name ");
    for (; name[i - 1] != '/'; i++);
    for (; name[i] != '.'; i++)
        my_putchar(name[i]);
    my_printf(" :  Error\n");
}