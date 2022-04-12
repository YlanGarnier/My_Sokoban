/*
** EPITECH PROJECT, 2022
** map.c
** File description:
** map
*/

#include "sokoban.h"
#include <ncurses.h>
#include "my.h"

void which_color(char c)
{
    switch (c) {
    case 'P':
        attron (COLOR_PAIR (2));
        break;
    case 'X':
        attron (COLOR_PAIR (3));
        break;
    case 'O':
        attron (COLOR_PAIR (4));
        break;
    case '#':
        attron (COLOR_PAIR (5));
        break;
    default:
        attron (COLOR_PAIR (1));
        break;
    }
}

void display_caracter(soko_t *soko)
{
    for (int i = 0, y = 0; soko->map[y] != NULL; i++) {
        which_color(soko->map[y][i]);
        mvprintw(LINES/2 + y -soko->nblines,
        COLS/2 -soko->nbcols + i, "%c", soko->map[y][i]);
        attroff(COLOR_PAIR (2));
        if (soko->map[y][i] == '\0') {
            y++;
            i = -1;
        }
    }
}

void display_map(soko_t *soko)
{
    int x = 0;
    int y = 0;

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    getmaxyx(stdscr, y, x);
    if (y < soko->nblines || x < soko->nbcols) {
        mvprintw((y/2), (x/2) - my_strlen("Window too small\n"),
        "%s\n","Window too small\n");
    } else
        display_caracter(soko);
    return;
}
