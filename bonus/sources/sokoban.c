/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** sokoban
*/

#include "sokoban.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_stats(char const *filepath)
{
    struct stat sb;

    if (stat(filepath, &sb) == -1) {
        write(1, "error\n", 6);
        exit (0);
    }
    return sb.st_size;
}

char *read_map(char const *filepath, int fd)
{
    int size = get_stats(filepath) + 1;
    char *buffer = malloc(sizeof(char) * (size + 1));

    read(fd, buffer, size);
    buffer[size - 1] = '\0';
    return buffer;
}

int sokoban(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return 84;
    char *file = read_map(path, fd);
    close(fd);
    soko_t soko;

    if (check_invalid_map(file, &soko) == 1)
        return 84;
    soko.map = str_to_word_array(file, "\n");
    soko.targets_map = str_to_word_array(file, "\n");
    game(&soko);
    return (soko.return_value);
}

int main(int ac, char **av)
{

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 1) {
        usage();
        return 0;
    }
    return (sokoban(av[1]));
}
