/*
** EPITECH PROJECT, 2022
** lose.c
** File description:
** lose conditions
*/

#include "sokoban.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ncurses.h>

int timer(soko_t *soko)
{
    int msec = 0;
    int trigger = 15;
    int timer = 0;
    clock_t difference = clock();
    msec = difference * 1000 / CLOCKS_PER_SEC;
    timer = trigger - (msec/1000);
    mvprintw(LINES/2 -5 -soko->nblines,
        COLS/2 -soko->nbcols, "time left = %d", timer);
    if (timer <= 0)
        return 1;
    return 0;
}

int is_box_lost(soko_t *soko, int y, int x)
{
    char s = soko->map[y][x + 1];
    char z = soko->map[y][x - 1];
    char q = soko->map[y - 1][x];
    char d = soko->map[y + 1][x];

    if ((z == '#' || z == 'X') &&
    ((q == '#' || q == 'X') || (d == '#' || d == 'X')))
        return 1;
    if ((s == '#' || s == 'X') &&
    ((q == '#' || q == 'X') || (d == '#' || d == 'X')))
        return 1;
    if ((q == '#' || q == 'X') &&
    ((z == '#' || z == 'X') || (s == '#' || s == 'X')))
        return 1;
    if ((d == '#' || d == 'X') &&
    ((z == '#' || z == 'X') || (s == '#' || s == 'X')))
        return 1;
    return 0;
}

int check_lose(soko_t *soko)
{
    soko->lose = soko->boxes;
    for (int i = 0, y = 0; soko->map[y] != NULL; i++) {
        if (soko->map[y][i] == 'X' && is_box_lost(soko, y, i) == 1)
            soko->lose--;
        if (soko->map[y][i] == '\0') {
            y++;
            i = -1;
        }
    }
    if (soko->lose == 0) {
        soko->return_value = 1;
        return 1;
    }
    if (timer(soko) == 1)
        return 1;
    return 0;
}
