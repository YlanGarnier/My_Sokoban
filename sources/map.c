/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** map
*/

#include "sokoban.h"
#include <ncurses.h>
#include "my.h"

void display_map(soko_t *soko)
{
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, y, x);
    if (y < soko->nblines || x < soko->nbcols) {
        mvprintw((y/2), (x/2) - my_strlen("Window too small\n"),
        "%s\n","Window too small\n");
    } else
        for (int i = 0; soko->map[i] != NULL; i++)
            mvprintw(LINES/2 + i -soko->nblines,
            COLS/2 -soko->nbcols, "%s", soko->map[i]);
    return;
}
