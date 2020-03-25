/*
** EPITECH PROJECT, 2019
** ADD_TETR
** File description:
** Add tetriminos in list
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tetris.h"

void add_tetr(tetri_t **tetr, char **str, char *name)
{
    tetri_t *new = NULL;
    new = malloc(sizeof(tetri_t));
    new->name = NULL;
    new->color = 0;
    new->shape = NULL;
    new->size_x = 0;
    new->size_y = 0;
    new->next = NULL;

    init_tetr(new, str, name);
    new->next = *tetr;
    *tetr = new;
}

void init_tetr(tetri_t *new, char **str, char *name)
{
    int i = 0;
    int j = 0;

    alloc_tetr(new, str, name);
    for (; name[i] != '/'; i++);
    i++;
    for (; name[i] != '.'; i++) {
        new->name[j] = name[i];
        j++;
    }
    new->size_x = my_atoi(str[0]);
    new->size_y = my_atoi(str[1]);
    new->color = my_atoi(str[2]);
    for (int k = 3; str[k] != NULL; k++)
        new->shape[k - 3] = str[k];
}

void alloc_tetr(tetri_t *new, char **str, char *name)
{
    int k = 0;

    new->name = malloc(sizeof(char) * my_strlen(name));
    for (k = 3; str[k] != NULL; k++);
    new->shape = malloc(sizeof(char *) * (k - 3));
    for (int i = 3; str[i] != NULL; i++)
        new->shape[i - 3] = malloc(sizeof(char) * my_strlen(str[i]));
}