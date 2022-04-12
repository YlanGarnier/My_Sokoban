/*
** EPITECH PROJECT, 2022
** usage.c
** File description:
** usage
*/

#include "my.h"

void usage(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, containing '#'");
    my_putstr(" for walls,\n\t\t'P' for the player, 'X' for boxes and 'O'");
    my_putstr(" for storage locations.\n");
}
