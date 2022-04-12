/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** sokoban tools
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_
    #include <time.h>

typedef struct coords_s {
    int x;// abscissa
    int y;// ordinate
} coords_t;

typedef struct soko_s {
    char **map;// 2d map which we will play on;
    char **targets_map;// second map to keep a trace of where the targets are
    int return_value;
    int key;// stock which key is pressed
    int targets;// number of targets
    int boxes;// number of boxes
    int nblines;// number of lines
    int nbcols;// number of colones
    int lose;// lose condition
    coords_t coords;// player coords
} soko_t;

// game.c
void game(soko_t *soko);
// map.c
void display_map(soko_t *soko);
// player.c
void get_player_position(soko_t *soko);
int can_player_move(char c);
// controls.c
void check_controls(soko_t *soko);
// boxes_and_targets
int can_the_box_move(soko_t *soko, char c, int side);
void is_target_there(soko_t *soko);
// reset.c
void check_reset(soko_t *soko);
// win.c
int check_lose(soko_t *soko);
// usage.c
void usage(void);
// error_handling.c
int check_invalid_map(char const *file, soko_t *soko);

#endif /* !SOKOBAN_H_ */
