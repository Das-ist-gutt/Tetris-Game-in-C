/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include "tetris.h"

void display_all_element(game_t *game)
{
    display_element(game->name.array, game->name.position.x, game->name.position.y);
    display_element(game->info.array, game->info.position.x, game->info.position.y);
    display_element(game->display.array, game->display.position.x, game->display.position.y);
    display_element(game->next.array, game->next.position.x, game->next.position.y);
}

void display_element(char **element, int x, int y)
{
    for (int p = 0; element[p] != NULL; p++) {
        mvprintw(y + p, x, "%s", element[p]);
    }
}