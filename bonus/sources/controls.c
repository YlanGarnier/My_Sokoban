/*
** EPITECH PROJECT, 2022
** controls.c
** File description:
** game controls
*/

#include "sokoban.h"
#include <ncurses.h>

void move_down(soko_t *soko)
{
    int x = soko->coords.x;
    int y = soko->coords.y;

    if (can_player_move(soko->map[y + 1][x]) == 1) {
        soko->map[y + 1][x] = soko->map[y][x];
        soko->map[y][x] = ' ';
    } else if (can_the_box_move(soko, soko->map[y + 1][x], 3) == 1) {
        soko->map[y + 2][x] = soko->map[y + 1][x];
        soko->map[y + 1][x] = soko->map[y][x];
        soko->map[y][x] = ' ';
    }
    return;
}

void move_up(soko_t *soko)
{
    int x = soko->coords.x;
    int y = soko->coords.y;

    if (can_player_move(soko->map[y - 1][x]) == 1) {
        soko->map[y - 1][x] = soko->map[y][x];
        soko->map[y][x] = ' ';
    } else if (can_the_box_move(soko, soko->map[y - 1][x], 2) == 1) {
        soko->map[y - 2][x] = soko->map[y - 1][x];
        soko->map[y - 1][x] = soko->map[y][x];
        soko->map[y][x] = ' ';
    }
    return;
}

void move_left(soko_t *soko)
{
    int x = soko->coords.x;
    int y = soko->coords.y;

    if (can_player_move(soko->map[y][x - 1]) == 1) {
        soko->map[y][x - 1] = soko->map[y][x];
        soko->map[y][x] = ' ';
    } else if (can_the_box_move(soko, soko->map[y][x - 1], 1) == 1) {
        soko->map[y][x - 2] = soko->map[y][x - 1];
        soko->map[y][x - 1] = soko->map[y][x];
        soko->map[y][x] = ' ';
    }
    return;
}

void move_right(soko_t *soko)
{
    int x = soko->coords.x;
    int y = soko->coords.y;

    if (can_player_move(soko->map[y][x + 1]) == 1) {
        soko->map[y][x + 1] = soko->map[y][x];
        soko->map[y][x] = ' ';
    } else if (can_the_box_move(soko, soko->map[y][x + 1], 0) == 1) {
        soko->map[y][x + 2] = soko->map[y][x + 1];
        soko->map[y][x + 1] = soko->map[y][x];
        soko->map[y][x] = ' ';
    }
    return;
}

void check_controls(soko_t *soko)
{
    if (soko->key == 67) {
        move_right(soko);
        return;
    }
    if (soko->key == 68) {
        move_left(soko);
        return;
    }
    if (soko->key == 65) {
        move_up(soko);
        return;
    }
    if (soko->key == 66) {
        move_down(soko);
        return;
    }
    is_target_there(soko);
    return;
}
