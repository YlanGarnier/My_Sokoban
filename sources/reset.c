/*
** EPITECH PROJECT, 2022
** reset.c
** File description:
** reset the game
*/

#include "sokoban.h"
#include "my.h"
#include <stdlib.h>

void check_reset(soko_t *soko)
{
    if (soko->key == 32)
        for (int i = 0; soko->map[i] != NULL; i++)
            soko->map[i] = my_strcpy(soko->map[i], soko->targets_map[i]);
    return;
}
