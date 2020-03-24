/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <ncurses.h>
#include "warlock.h"

typedef struct vector_t {
    int x;
    int y;
} vector_t;

typedef struct config_t {
    int level;
    int debug;
    int size_x;
    int size_y;
    int hide;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
} config_t;

typedef struct displayer_t {
    char **array;
    vector_t size;
    vector_t position;
} displayer_t;

typedef struct game_t {
    displayer_t display;
    displayer_t name;
    displayer_t next;
    displayer_t info;
} game_t;

//config.c

config_t *load_config(arg_t **arg);
int change_config(arg_t *arg, config_t *config);
void config_size(arg_t *arg, config_t *config);

// main.c

game_t *load_game_struct(config_t *config);
int start_game(game_t *game, config_t *config);

// loop.c

int game_loop(void);

// display.c

void display_element(char **element, int x, int y);

// set_displayer.c

displayer_t load_display_array(config_t *config);
displayer_t load_info_array(void);
displayer_t load_name_array(void);
displayer_t load_next_array(void);

#endif /* !TETRIS_H_ */
