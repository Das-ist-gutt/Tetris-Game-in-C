/*
** EPITECH PROJECT, 2019
** LOAD_TETR
** File description:
** Load tetriminos
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tetris.h"

void load_tetr(tetri_t **tetrim)
{
    struct dirent *der = NULL;
    DIR *dir = NULL;

    dir = opendir("tetriminos/");
    while ((der = readdir(dir)) != NULL)
        if (der->d_name[0] != '.')
            get_tetr(my_strcat("tetriminos/", der->d_name), tetrim);
    closedir(dir);
    free(der);
}

int get_tetr(char *f_name, tetri_t **tetrim)
{
    int fd = 0;
    size_t size = 20;
    char *buffer = malloc(sizeof(char) * 16);
    char **str = NULL;
    int len = 0;
    int save = 0;

    fd = open(f_name, O_RDONLY);
    read(fd, buffer, size);
    divide_array(buffer, str, ' '); // Création double tableau
    if (check_tetr(str, len, save) == 1)
        return (0);
    get_state(str, f_name, tetrim);
    close(fd);
    free(buffer);
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    return (0);
}

int get_state(char **str, char *name, tetri_t **tetrim)
{
    int i = 0;

    for (; name[i] != '/'; i++);
    i++;
    for (; name[i] != '.'; i++);
    add_tetr(tetrim, str, name);
    return (0);
}

int check_tetr(char **str, int len, int save)
{
    int k = 0;
    int x = my_atoi(str[0]);
    int y = 0;
    int col = 0;

    if (check_tetr_error(str, 0) == 1 || str[0][1] != '\0')
        return (1);
    y = my_atoi(str[1]);
    col = my_atoi(str[2]);
    for (k = 2; str[k] != NULL; k++) {
        len = my_strlen(str[k]);
        if (save < len)
            save = len;
    }
    if (save != x || k - 3 != y || col > 7) {
        if (check_tetr_error(str, 1) == 1)
            return (1);
    }
    return (0);
}

int check_tetr_error(char **str, int mark)
{
    if (mark == 0) {
        for (int i = 0; i <= 2; i++)
            for (int j = 0; str[i][j] != '\0'; j++)
                if (str[i][j] < 49 || str[i][j] > 57)
                    return (1);
    }
    else
        return (1);
    return (0);
}