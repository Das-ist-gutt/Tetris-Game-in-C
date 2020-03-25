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
    my_putstr("\t-l --key-left={K}\tMove the tetrimino LEFT ");
    my_putstr("using the K key (def: left arrow)\n");
    my_putstr("\t-r --key-right={K}\tMove the tetrimino RIGHT ");
    my_putstr("using the K key (def: right arrow)\n");
    my_putstr("\t-t --key-turn={K}\tTURN the tetrimino clockwise ");
    my_putstr("90d using the K key (def: top arrow)\n");
    my_putstr("\t-d --key-drop={K}\tDROP the tetrimino ");
    my_putstr("using the K key (def: down arrow)\n\t-q --key-quit={K}");
    my_putstr("\tQUIT the game using the K key (def: ‘q’ key)\n");
    my_putstr("\t-p --key-pause={K}\tPAUSE/RESTART the ");
    my_putstr("game using the K key (def: space bar)\n");
    my_putstr("\t--map-size={row,col}\tSet the ");
    my_putstr("numbers of rows and columns of the map (def: 20,10)\n");
    my_putstr("\t-w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr("\t-D --debug\tDebug mode (def: false)\n");
    return (0);
}

int main (int ac, char **argc)
{
    arg_t **arg = NULL;
    config_t *config = NULL;
    game_t *game = load_game_struct();
    tetri_t *tetrim = malloc(sizeof(tetri_t));
    tetrim->next = NULL;

    if (ac > 1 && compare(argc[1], "--help"))
        show_help();
    else if (ac > 1)
        arg = argument_parser(ac, argc);
    config = load_config(arg);
    load_tetr(&tetrim);
    if (config->debug == 1)
        debug(config);
    start_game(game, config);
    return (0);
}

game_t *load_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    return (game);
}

int start_game(game_t *game, config_t *config)
{
    //initscr();
    //clear();
    //refresh();
    //noecho();
    //keypad(stdscr, TRUE);
    //clear();
    //refresh();
    //endwin();
    return (0);
}
