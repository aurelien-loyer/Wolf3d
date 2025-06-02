/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** line_drawing
*/
#include "include.h"

int set_ceiling(wolf_t *wolf, int x)
{
    wolf->area[2].array = sfVertexArray_create();
    if (!wolf->area[2].array)
        return 84;
    sfVertexArray_setPrimitiveType(wolf->area[2].array, sfQuads);
    wolf->area[2].point[0].position = (sfVector2f){x, 0};
    wolf->area[2].point[0].color = sfColor_fromRGBA(135, 206, 235, 20);
    wolf->area[2].point[1].position = (sfVector2f){x + 1, 0};
    wolf->area[2].point[1].color = sfColor_fromRGBA(135, 206, 235, 20);
    wolf->area[2].point[2].position = (sfVector2f){x + 1, wolf->ray.draw[0]};
    wolf->area[2].point[2].color = sfColor_fromRGBA(135, 206, 235, 20);
    wolf->area[2].point[3].position = (sfVector2f){x, wolf->ray.draw[0]};
    wolf->area[2].point[3].color = sfColor_fromRGBA(135, 206, 235, 20);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(wolf->area[2].array, wolf->area[2].point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, wolf->area[2].array, NULL);
    sfVertexArray_destroy(wolf->area[2].array);
    return 0;
}

int set_floor(wolf_t *wolf, sfVector2u win_size, int x, area_t *floor)
{
    floor->array = sfVertexArray_create();
    if (!floor->array)
        return 84;
    sfVertexArray_setPrimitiveType(floor->array, sfQuads);
    floor->point[0].position = (sfVector2f){x, wolf->ray.draw[1]};
    floor->point[0].color = sfColor_fromRGBA(100, 100, 100, 20);
    floor->point[1].position = (sfVector2f){x + 1, wolf->ray.draw[1]};
    floor->point[1].color = sfColor_fromRGBA(100, 100, 100, 20);
    floor->point[2].position = (sfVector2f){x + 1, win_size.y};
    floor->point[2].color = sfColor_fromRGBA(100, 100, 100, 20);
    floor->point[3].position = (sfVector2f){x, win_size.y};
    floor->point[3].color = sfColor_fromRGBA(100, 100, 100, 20);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(floor->array, floor->point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, floor->array, NULL);
    sfVertexArray_destroy(floor->array);
    return 0;
}

int set_wall(area_t *wall, ray_t *ray, int x, wolf_t *wolf)
{
    wall->array = sfVertexArray_create();
    if (!wall->array)
        return 84;
    sfVertexArray_setPrimitiveType(wall->array, sfQuads);
    wall->point[0].position = (sfVector2f){x, ray->draw[0]};
    wall->point[0].texCoords = (sfVector2f){0, 0};
    wall->point[1].position = (sfVector2f){x + 1, ray->draw[0]};
    wall->point[1].texCoords = (sfVector2f){wall->text_size[0], 0};
    wall->point[2].position = (sfVector2f){x + 1, ray->draw[1]};
    wall->point[2].texCoords = (sfVector2f){wall->text_size[0],
        wall->text_size[1]};
    wall->point[3].position = (sfVector2f){x, ray->draw[1]};
    wall->point[3].texCoords = (sfVector2f){0, wall->text_size[1]};
    for (int i = 0; i < 4; i++) {
        wall->point[i].color = sfColor_fromRGBA(255, 255, 255, 20);
        sfVertexArray_append(wall->array, wall->point[i]);
    }
    sfRenderWindow_drawVertexArray(wolf->window, wall->array, &wall->states);
    return sfVertexArray_destroy(wall->array), 0;
}

void draw_line(wolf_t *wolf, int x)
{
    sfVector2u win_size = sfRenderWindow_getSize(wolf->window);

    if (set_ceiling(wolf, x) != 0)
        return;
    if (set_wall(&wolf->area[0], &wolf->ray, x, wolf) != 0)
        return;
    if (set_floor(wolf, win_size, x, &wolf->area[1]) != 0)
        return;
}
