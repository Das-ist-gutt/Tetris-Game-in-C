/*
** EPITECH PROJECT, 2019
** DEBUG_TETR
** File description:
** Debug tetriminos
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include "tetris.h"

void debug_tetr(void)
{
    struct dirent *der = NULL;
    DIR *dir = NULL;
    int tetr_nb = 0;

    dir = opendir("tetriminos/");
    while ((der = readdir(dir)) != NULL)
        if (der->d_name[0] != '.')
            tetr_nb++;
    closedir(dir);
    my_printf("Tetriminos :  %i\n", tetr_nb);
    dir = opendir("tetriminos/");
    while ((der = readdir(dir)) != NULL)
        if (der->d_name[0] != '.')
            get_file(my_strcat("tetriminos/", der->d_name));
    closedir(dir);
    free(der);
}

int get_file(char *f_name)
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
    if (error_tetr(str, f_name, len, save) == 1)
        return (0);
    print_state(buffer, str, f_name);
    close(fd);
    free(buffer);
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
    return (0);
}

int print_state(char *buffer, char **str, char *name)
{
    int j = 0;
    int i = 0;

    my_putstr("Tetriminos :  Name ");
    for (; name[i] != '/'; i++);
    i++;
    for (; name[i] != '.'; i++)
        my_putchar(name[i]);
    my_printf(" :  Size %i*%i :  Color %i :",
    my_atoi(str[0]), my_atoi(str[1]), my_atoi(str[2]));
    for (; buffer[j] != '\n'; j++);
    for (; buffer[j] != '\0'; j++)
        my_putchar(buffer[j]);
    my_putchar('\n');
    return (0);
}

int error_tetr(char **str, char *name, int len, int save)
{
    int k = 0;
    int x = my_atoi(str[0]);
    int y = 0;
    int col = 0;

    if (check_error(name, str, 0) == 1 || str[0][1] != '\0')
        return (1);
    y = my_atoi(str[1]);
    col = my_atoi(str[2]);
    for (k = 2; str[k] != NULL; k++) {
        len = my_strlen(str[k]);
        if (save < len)
            save = len;
    }
    if (save != x || k - 3 != y || col > 7) {
        if (check_error(name, str, 1) == 1)
            return (1);
    }
    return (0);
}

int check_error(char *name, char **str, int mark)
{
    if (mark == 0) {
        for (int i = 0; i <= 2; i++)
            for (int j = 0; str[i][j] != '\0'; j++)
                if (str[i][j] < 49 || str[i][j] > 57) {
                    print_error(name);
                    return (1);
                }
    }
    else {
        print_error(name);
        return (1);
    }
    return (0);
}