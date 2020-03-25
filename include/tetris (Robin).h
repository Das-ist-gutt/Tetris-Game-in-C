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

typedef struct tetri_s tetri_t;

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

struct tetri_s {
    char *name;
    char **shape;
    int color;
    int size_x;
    int size_y;
    tetri_t *next;
};

typedef struct game_t {


} game_t;

//config.c

config_t *load_config(arg_t **arg);
void change_config(arg_t *arg, config_t *config);
void config_size(arg_t *arg, config_t *config);

// main.c

game_t *load_game_struct(void);
int start_game(game_t *game, config_t *config);

// loop.c

int game_loop(void);

// load_tetr.c

void load_tetr(tetri_t **tetrim);
int get_tetr(char *f_name, tetri_t **tetrim);
int get_state(char **str, char *name, tetri_t **tetrim);
int check_tetr(char **str, int len, int save);
int check_tetr_error(char **str, int mark);

// debug.c

int debug(config_t *config);
void display_conf(config_t *config);
void disp_left(config_t *config);
void disp_right(config_t *config);
void disp_turn(config_t *config);

// debug_sec.c

void disp_drop(config_t *config);
void disp_quit(config_t *config);
void disp_pause(config_t *config);
void disp_int(config_t *config);
void print_error(char *name);

// debug_tetr.c

void debug_tetr(void);
int get_file(char *f_name);
int print_state(char *buffer, char **str, char *name);
int error_tetr(char **str, char *name, int len, int save);
int check_error(char *name, char **str, int mark);

// add_tetr.c

void add_tetr(tetri_t **tetr, char **str, char *name);
void init_tetr(tetri_t *new, char **str, char *name);
void alloc_tetr(tetri_t *new, char **str, char *name);

// my_strcat.c (lib Robin)

char *my_strcat(char *dest, char *src);

#endif /* !TETRIS_H_ */
