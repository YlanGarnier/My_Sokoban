/*
** EPITECH PROJECT, 2022
** player.c
** File description:
** player
*/
#include "sokoban.h"
#include <stdlib.h>

int can_player_move(char c)
{
    if (c == ' ' || c == 'O')
        return 1;
    return 0;
}

void get_player_position(soko_t *soko)
{
    for (int x = 0, y = 0; soko->map[y] != NULL; x++) {
        if (soko->map[y][x] == 'P') {
            soko->coords.x = x;
            soko->coords.y = y;
            return;
        }
        else if (soko->map[y][x] == '\0') {
            y++;
            x = -1;
        }
    }
}
