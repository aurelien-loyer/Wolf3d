/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** load_map.c
*/

#include "include.h"


int is_autorized_character(char c)
{
    for (int i = 0; CHARACTER_MAP[i] != 0; i++)
        if (c == CHARACTER_MAP[i])
            return 1;
    dprintf(2, "\033[0;31mInvalid map file format.\033[0m\n");
    return 0;
}

static int check_format(char *line)
{
    int size = 0;

    for (int i = 0; line[i] != 0; i++){
        size++;
        if (!is_autorized_character(line[i]))
            return 0;
    }
    return size;
}

static int is_character_spawn(int *map, int len)
{
    for (int i = 0; i < len; i++)
        if (map[i] == CHARACTER_POSPLAYER)
            return 1;
    return 0;
}

static int check_spawn_position(int **map)
{
    int len = len_map(map);
    int spawn = 0;

    if (len == 0)
        return 84;
    for (int i = 0; map[i]; i++)
        spawn += is_character_spawn(map[i], len);
    if (spawn > 1)
        dprintf(2, "\033[0;31mOnly one player spawn is allowed.\033[0m\n");
    if (spawn == 0)
        dprintf(2, "\033[0;31mPlayer spawn position is not set.\033[0m\n");
    return spawn != 1 ? 84 : 0;
}

int load_map(wolf_t *wolf_struct, char **av)
{
    FILE *stream = fopen(av[1], "r");
    char *line = NULL;
    size_t n = 0;
    int byte_read = 0;

    if (!stream)
        return perror(av[1]), 84;
    do {
        byte_read = getline(&line, &n, stream);
        if (line == NULL)
            break;
        line[byte_read - 1] = 0;
        if (add_to_map(wolf_struct, line, check_format(line)) == 84)
            return my_free(line), 84;
    } while (byte_read > 0);
    my_free(line);
    return check_spawn_position(wolf_struct->world);
}
