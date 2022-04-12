/*
** EPITECH PROJECT, 2022
** boxes_and_targets.c
** File description:
** can you move box ? was there a target there ?
*/

#include "sokoban.h"
#include <stdlib.h>

void is_target_there(soko_t *soko)
{
    for (int x = 0, y = 0; soko->map[y] != NULL; x++) {
        if (soko->map[y][x] == ' ' && soko->targets_map[y][x] == 'O')
            soko->map[y][x] = 'O';
        if (soko->map[y][x] == '\0') {
            y++;
            x = -1;
        }
    }
    return;
}

int can_the_box_move(soko_t *soko, char c, int side)
{
    int x = soko->coords.x;
    int y = soko->coords.y;

    if (c != 'X')
        return 0;
    if (side == 0)
        if (soko->map[y][x + 2] == ' ' || soko->map[y][x + 2] == 'O')
            return 1;
    if (side == 1)
        if (soko->map[y][x - 2] == ' ' || soko->map[y][x - 2] == 'O')
            return 1;
    if (side == 2)
        if (soko->map[y - 2][x] == ' ' || soko->map[y - 2][x] == 'O')
            return 1;
    if (side == 3)
        if (soko->map[y + 2][x] == ' ' || soko->map[y + 2][x] == 'O')
            return 1;
    return 0;
}
