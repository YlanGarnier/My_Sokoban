/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** my strcat description
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *str1, char const *str2)
{
    int i = 0;

    if (str1[0] != '\0')
        i = my_strlen(str1);
    else
        i = 0;
    for (int y = 0; str2[y] != '\0'; i++, y++)
        str1[i] = str2[y];
    str1[i] = ' ';
    return (str1);
}
