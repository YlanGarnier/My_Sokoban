/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** sokoban game
*/

#include <ncurses.h>
#include <unistd.h>
#include "sokoban.h"

int check_win(soko_t *soko)
{
    int nb = soko->targets;

    for (int x = 0, y = 0; soko->map[y] != NULL; x++) {
        if (soko->map[y][x] == 'X' && soko->targets_map[y][x] == 'O')
            nb--;
        if (soko->map[y][x] == '\0') {
            y++;
            x = -1;
        }
    }
    if (nb == 0) {
        soko->return_value = 0;
        return 1;
    }
    return 0;
}

void set_game(soko_t *soko)
{
    for (int i = 0, y = 0; soko->map[y] != NULL; i++) {
        if (soko->map[y][i] == '\0') {
            y++;
            soko->nblines = y;
            soko->nbcols = i;
            i = -1;
        }
    }
    return;
}

void initialize_game(void)
{
    initscr();
    curs_set(0);
    noecho();
    return;
}

void game(soko_t *soko)
{
    initialize_game();
    set_game(soko);

    while (check_win(soko) != 1 && check_lose(soko) != 1) {
        display_map(soko);
        soko->key = getch();
        check_reset(soko);
        get_player_position(soko);
        check_controls(soko);
        clear();
    }
    clear();
    display_map(soko);
    refresh();
    endwin();
    return;
}
