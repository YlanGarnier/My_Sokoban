/*
** EPITECH PROJECT, 2022
** error_handling.c
** File description:
** check errors
*/

#include <unistd.h>
#include "sokoban.h"

int invalid_map(char const *file, soko_t *soko)
{
    int player = 0;
    soko->boxes = 0;
    soko->targets = 0;

    if (file[0] == '\0')
        return 1;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == 'X')
            soko->boxes++;
        if (file[i] == 'O')
            soko->targets++;
        if (file[i] == 'P')
            player++;
    }
    if (player != 1)
        return 1;
    return 0;
}

int accepted_caracters(char c)
{
    if (c != ' ' && c != '\n' && c != '#' && c != 'X' && c != 'O' && c != 'P')
        return 1;
    return 0;
}

int check_invalid_map(char const *file, soko_t *soko)
{
    for (int i = 0; file[i] != '\0'; i++)
        if (accepted_caracters(file[i]) == 1) {
            write(2, "error: invalid map\n", 19);
            return 1;
        }
    if (invalid_map(file, soko) == 1)
        return 1;
    if (soko->targets > soko->boxes)
        return 1;
    return 0;
}
