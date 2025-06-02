/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** fill_map.c
*/

#include "include.h"

int len_map(int **map)
{
    int len = 0;

    if (!map)
        return 0;
    for (len = 0; map[len]; len++);
    return len;
}

int add_to_map(wolf_t *wolf, char *line, int size)
{
    int len = len_map(wolf->world);

    if (size == 0)
        return 84;
    wolf->world = realloc(wolf->world, sizeof(int *) * (len + 2));
    if (!wolf->world)
        return 84;
    wolf->world[len] = malloc(sizeof(int) * size);
    if (!wolf->world[len])
        return 84;
    wolf->world[len + 1] = NULL;
    for (int i = 0; i < size; i++)
        wolf->world[len][i] = line[i] - 48;
    return 0;
}
