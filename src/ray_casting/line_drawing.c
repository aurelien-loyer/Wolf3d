/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** line_drawing
*/
#include "include.h"

int set_ceiling(wolf_t *wolf, int x)
{
    wolf->ceil.array = sfVertexArray_create();
    if (!wolf->ceil.array)
        return 84;
    sfVertexArray_setPrimitiveType(wolf->ceil.array, sfQuads);
    wolf->ceil.point[0].position = (sfVector2f){x, 0};
    wolf->ceil.point[0].color = sfColor_fromRGB(135, 206, 235);
    wolf->ceil.point[1].position = (sfVector2f){x + 1, 0};
    wolf->ceil.point[1].color = sfColor_fromRGB(135, 206, 235);
    wolf->ceil.point[2].position = (sfVector2f){x + 1, wolf->ray.draw[0]};
    wolf->ceil.point[2].color = sfColor_fromRGB(135, 206, 235);
    wolf->ceil.point[3].position = (sfVector2f){x, wolf->ray.draw[0]};
    wolf->ceil.point[3].color = sfColor_fromRGB(135, 206, 235);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(wolf->ceil.array, wolf->ceil.point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, wolf->ceil.array, NULL);
    sfVertexArray_destroy(wolf->ceil.array);
    return 0;
}

int set_wall(area_t *wall, ray_t *ray, int x, sfRenderWindow *window)
{
    wall->array = sfVertexArray_create();
    if (!wall->array)
        return 84;
    sfVertexArray_setPrimitiveType(wall->array, sfQuads);
    sfColor wall_color = ray->side_dir == 1 
        ? sfColor_fromRGB(180, 0, 0) : sfColor_fromRGB(255, 0, 0);
    wall->point[0].position = (sfVector2f){x, ray->draw[0]};
    wall->point[0].color = wall_color;
    wall->point[1].position = (sfVector2f){x + 1, ray->draw[0]};
    wall->point[1].color = wall_color;
    wall->point[2].position = (sfVector2f){x + 1, ray->draw[1]};
    wall->point[2].color = wall_color;
    wall->point[3].position = (sfVector2f){x, ray->draw[1]};
    wall->point[3].color = wall_color;
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(wall->array, wall->point[i]);
    sfRenderWindow_drawVertexArray(window, wall->array, NULL);
    sfVertexArray_destroy(wall->array);
    return 0;
}

int set_floor(wolf_t *wolf, sfVector2u win_size, int x, area_t *floor)
{
    floor->array = sfVertexArray_create();
    if (!floor->array)
        return 84;
    sfVertexArray_setPrimitiveType(floor->array, sfQuads);
    floor->point[0].position = (sfVector2f){x, wolf->ray.draw[1]};
    floor->point[0].color = sfColor_fromRGB(100, 100, 100);
    floor->point[1].position = (sfVector2f){x + 1, wolf->ray.draw[1]};
    floor->point[1].color = sfColor_fromRGB(100, 100, 100);
    floor->point[2].position = (sfVector2f){x + 1, win_size.y};
    floor->point[2].color = sfColor_fromRGB(100, 100, 100);
    floor->point[3].position = (sfVector2f){x, win_size.y};
    floor->point[3].color = sfColor_fromRGB(100, 100, 100);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(floor->array, floor->point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, floor->array, NULL);
    sfVertexArray_destroy(floor->array);
    return 0;
}

void draw_line(wolf_t *wolf, int x)
{
    sfVector2u win_size = sfRenderWindow_getSize(wolf->window);

    if (set_ceiling(wolf, x) != 0)
        return;
    if (set_wall(&wolf->wall, &wolf->ray, x, wolf->window) != 0)
        return;
    if (set_floor(wolf, win_size, x, &wolf->floor) != 0)
        return;
}
