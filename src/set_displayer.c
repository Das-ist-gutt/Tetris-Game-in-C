/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_displayer
*/

#include "tetris.h"

char *custom_fill(char first, char center, int repeat, char end)
{
    char *buffer = clean_alloc(repeat + 3);

    buffer[0] = first;
    for (int i = 1; i < repeat + 1; i++)
        buffer[i] = center;
    buffer[repeat + 1] = end;
    buffer[repeat + 2] = '\0';
    return (buffer);
}

displayer_t load_display_array(config_t *config)
{
    displayer_t displayer;

    displayer.array = malloc(sizeof(char *) * config->size_y + 1);

    displayer.array[0] = custom_fill('/', '=', config->size_x, '\\');
    for (int i = 1; i < config->size_y - 1; i++)
        displayer.array[i] = custom_fill('|', ' ', config->size_x, '|');
    displayer.array[config->size_y - 1] = custom_fill('\\', '=', config->size_x, '/');
    displayer.array[config->size_y] = NULL;
    displayer.size.y = config->size_y;
    displayer.size.x = config->size_x;
    return (displayer);
}

displayer_t load_info_array(void)
{
    displayer_t displayer;

    displayer.array = malloc(sizeof(char *) * 6);

    displayer.array[0] = fill("#################");
    displayer.array[1] = fill("#   SCORE : %%% #");
    displayer.array[2] = fill("#   LEVEL : %%% #");
    displayer.array[3] = fill("#################");
    displayer.array[4] = NULL;
    displayer.size.y = 6;
    displayer.size.x = 17;
    return (displayer);
}

displayer_t load_name_array(void)
{
    displayer_t displayer;

    displayer.array = malloc(sizeof(char *) * 6);

    displayer.array[0] = fill("*** *** *** *** * ***");
    displayer.array[1] = fill(" *  *    *  * * * *  ");
    displayer.array[2] = fill(" *  ***  *  **  * ***");
    displayer.array[3] = fill(" *  *    *  * * *   *");
    displayer.array[4] = fill(" *  ***  *  * * * ***");
    displayer.array[5] = NULL;
    displayer.size.y = 6;
    displayer.size.x = 22;
    return (displayer);
}

displayer_t load_next_array(void)
{
    displayer_t displayer;

    displayer.array = malloc(sizeof(char *) * 7);

    displayer.array[0] = fill("######-Next-######");
    displayer.array[1] = fill("#                #");
    displayer.array[2] = fill("#                #");
    displayer.array[3] = fill("#                #");
    displayer.array[4] = fill("#                #");
    displayer.array[5] = fill("##################");
    displayer.array[6] = NULL;
    displayer.size.x = 7;
    displayer.size.y = 19;
    return (displayer);
}