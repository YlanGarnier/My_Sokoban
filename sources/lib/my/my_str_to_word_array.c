/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** put words into an array
*/
#include "my.h"
#include <stdlib.h>
#include "my_str_to_word_array.h"

void put_last_word(loop_t *tools, char **temp, int *y, int *l)
{
    temp[0][*l + 1] = '\0';
    tools->words[*y] = malloc(sizeof(char) * *l + 2);
    my_strcpy(tools->words[*y], temp[0]);
    *y += 1;
    free(temp[0]);
    tools->words[*y] = NULL;
}

void put_word(loop_t *tools, char **temp, int *y, int *l)
{
    temp[0][*l] = '\0';
    tools->words[*y] = malloc(sizeof(char) * *l + 1);
    my_strcpy(tools->words[*y], temp[0]);
    *y += 1;
    *l = -1;
    free(temp[0]);
}

int is_not_a_delimiter(char c, char **delimiter)
{
    for (int i = 0; delimiter[i] != NULL; i++)
        if (c == delimiter[i][0])
            return 1;
    return 0;
}

void loop(char *str, char *temp, loop_t *tools, int y)
{
    for (int i = 0, l = 0, a = 0; str[i] != '\0'; i++, l++) {
        if ((is_alpha(str[i]) == 0)
        && (is_not_a_delimiter(str[i], tools->delimiters) == 0)) {
            temp[l] = str[i];
            a = 1;
        }
        if ((is_alpha(str[i]) == 1
        || is_not_a_delimiter(str[i], tools->delimiters) == 1) && a == 1) {
            put_word(tools, &temp, &y, &l);
            temp = malloc(sizeof(char) * my_strlen(str));
            a = 0;
        } else if ((is_alpha(str[i]) == 1
        || is_not_a_delimiter(str[i], tools->delimiters) == 1) && a == 0)
            l = -1;
        if (str[i + 1] == '\0' && a == 1) {
            temp[l] = str[i];
            put_last_word(tools, &temp, &y, &l);
        }
    }
}

char **str_to_word_array(char *str, char *str2)
{
    int y = 0;
    loop_t tools;
    tools.words = malloc(sizeof(char *) * my_strlen(str));
    char *temp = malloc(sizeof(char) * my_strlen(str) + 1);
    tools.delimiters = my_delimiters(str2);
    loop(str, temp, &tools, y);
    return tools.words;
}
