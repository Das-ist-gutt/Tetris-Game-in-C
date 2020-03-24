/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** config
*/

#include "tetris.h"

config_t *load_config(arg_t **arg)
{
    config_t *config = malloc(sizeof(config_t));

    config->debug = 0;
    config->hide = 0;
    config->key_left = KEY_LEFT;
    config->key_right = KEY_RIGHT;
    config->key_turn = KEY_UP;
    config->key_drop = KEY_DOWN;
    config->key_pause = 32;
    config->key_quit = 81;
    config->level = 1;
    config->size_x = 16;
    config->size_y = 24;
    if (arg == NULL)
        return (config);
    for (int i = 0; arg[i] != NULL; i++) {
        if (change_config(arg[i], config) == 1)
            return (NULL);
    }
    return (config);
}

int change_config(arg_t *arg, config_t *config)
{
    SWITCH_W
    CASE_O compare(arg->option, "-l") || compare(arg->option, "--key-left") CASE_C
        config->key_left = arg->content[0][0];
    CASE_O compare(arg->option, "-r") || compare(arg->option, "--key-right") CASE_C
        config->key_right = arg->content[0][0];
    CASE_O compare(arg->option, "-t") || compare(arg->option, "--key-turn") CASE_C
        config->key_turn = arg->content[0][0];
    CASE_O compare(arg->option, "-d") || compare(arg->option, "--key-drop") CASE_C
        config->key_drop = arg->content[0][0];
    CASE_O compare(arg->option, "-L") || compare(arg->option, "--level") CASE_C
        config->level = my_atoi(arg->content[0]);
    CASE_O compare(arg->option, "-p") || compare(arg->option, "--key-pause") CASE_C
        config->key_pause = my_atoi(arg->content[0]);
    CASE_O compare(arg->option, "-w") || compare(arg->option, "--without-next") CASE_C
        config->hide = compare(arg->content[0], "true");
    CASE_O compare(arg->option, "-D") || compare(arg->option, "--debug") CASE_C
        config->debug = 1;
    CASE_O compare(arg->option, "--map-size") CASE_C
        config_size(arg, config);
    return (DEFAULT_W 1);
}

void config_size(arg_t *arg, config_t *config)
{
    char *buffer_1 = NULL;
    char *buffer_2 = NULL;

    buffer_1 = cut_tail(arg->content[0], '{');
    buffer_1 = keep_until(buffer_1, ',');
    buffer_2 = cut_tail(arg->content[0], ',');
    buffer_2 = keep_until(buffer_2, '}');
    config->size_x = my_atoi(buffer_1);
    config->size_y = my_atoi(buffer_2);
}