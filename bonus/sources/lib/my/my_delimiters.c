/*
** EPITECH PROJECT, 2022
** my_delimiters.c
** File description:
** board of delimiters for str to word array
*/
#include <stdlib.h>
#include "my.h"

char **my_delimiters(char *str)
{
    char **delimiters = malloc(sizeof(char *) * (my_strlen(str) + 1));
    delimiters[0] = malloc(sizeof(char) * 2);
    delimiters[0][0] = str[0];
    delimiters[0][1] = '\0';
    int y = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            delimiters[y] = malloc(sizeof(char) * 2);
            delimiters[y][0] = str[i + 2];
            delimiters[y][1] = '\0';
            y++;
        }
    }
    delimiters[y] = NULL;
    return delimiters;
}
