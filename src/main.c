/*
** EPITECH PROJECT, 2019
** kawai
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"

int show_help(void)
{
    my_putstr("Usage: ./tetris [options]\n");
    my_putstr("Options:\n");
    my_putstr("\t--help\tDisplay this help\n");
    my_putstr("\t-L --level={num}\tStart Tetris at level num (def: 1)\n");
    my_putstr("\t-l --key-left={K}\tMove the tetrimino LEFT using the K key (def: left arrow)\n");
    my_putstr("\t-r --key-right={K}\tMove the tetrimino RIGHT using the K key (def: right arrow)\n");
    my_putstr("\t-t --key-turn={K}\tTURN the tetrimino clockwise 90d using the K key (def: top");
    my_putstr(" arrow)\n");
    my_putstr("\t-d --key-drop={K}\tDROP the tetrimino using the K key (def: down arrow)\n");
    my_putstr("\t-q --key-quit={K}\tQUIT the game using the K key (def: ‘q’ key)\n");
    my_putstr("\t-p --key-pause={K}\tPAUSE/RESTART the game using the K key (def: space bar)\n");
    my_putstr("\t--map-size={row,col}\tSet the numbers of rows and columns of the map (def: 20,10)\n");
    my_putstr("\t-w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr("\t-D --debug\tDebug mode (def: false)\n");
    return (0);
}

int main (int ac, char **argc)
{
    arg_t **arg = NULL;
    config_t *config = NULL;
    game_t *game = NULL;

    if (ac > 1 && compare(argc[1], "--help"))
        show_help();
    else if (ac > 1)
        arg = argument_parser(ac, argc);
    config = load_config(arg);
    if (config == NULL)
        return (84);
    game = load_game_struct(config);
        if (game == NULL)
            return (84);
    start_game(game, config);
    return (0);
}

game_t *load_game_struct(config_t *config)
{
    game_t *game = malloc(sizeof(game_t));

    game->name = load_name_array();
    game->name.position.x = 2;
    game->name.position.y = 0;
    game->info = load_info_array();
    game->info.position.x = 4;
    game->info.position.y = game->name.size.y + 2;
    game->display = load_display_array(config);
    game->display.position.x = game->info.size.x + 8;
    game->display.position.y = 0;
    game->next = load_next_array();
    game->next.position.x = game->display.position.x + game->display.size.x + 6;
    game->next.position.y = 1;
    return (game);
}

int start_game(game_t *game, config_t *config)
{
    getch();
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (1) {
        display_all_element(game);
        refresh();
        usleep(100000);
        clear();
    }
    endwin();
    return (0);
}
