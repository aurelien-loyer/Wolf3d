/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** flash_light_handling
*/
#include "include.h"

float calculate_brightness(int x, sfVector2u win_size, float radius)
{
    float center_x = (float)win_size.x / 2.0f;
    float distance = fabs((float)x - center_x);
    float max_distance = radius;
    float brightness = 0;

    if (distance > max_distance)
        return 0.1f;
    brightness = 1.0f - (distance / max_distance) * 0.9f;
    return brightness;
}

sfColor adjust_color_brightness(sfColor original, float brightness)
{
    sfColor color = sfWhite;

    color.r = (sfUint8)(original.r * brightness);
    color.g = (sfUint8)(original.g * brightness);
    color.b = (sfUint8)(original.b * brightness);
    color.a = original.a;
    return color;
}

static int set_ceiling_with_flashlight(wolf_t *wolf, int x)
{
    wolf->area[2].array = sfVertexArray_create();
    if (!wolf->area[2].array)
        return 84;
    sfVertexArray_setPrimitiveType(wolf->area[2].array, sfQuads);
    wolf->area[2].color = adjust_color_brightness(
        sfColor_fromRGB(135, 206, 235), wolf->brightness);
    wolf->area[2].point[0].position = (sfVector2f){x, 0};
    wolf->area[2].point[0].color = wolf->area[2].color;
    wolf->area[2].point[1].position = (sfVector2f){x + 1, 0};
    wolf->area[2].point[1].color = wolf->area[2].color;
    wolf->area[2].point[2].position = (sfVector2f){x + 1, wolf->ray.draw[0]};
    wolf->area[2].point[2].color = wolf->area[2].color;
    wolf->area[2].point[3].position = (sfVector2f){x, wolf->ray.draw[0]};
    wolf->area[2].point[3].color = wolf->area[2].color;
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(wolf->area[2].array, wolf->area[2].point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, wolf->area[2].array, NULL);
    sfVertexArray_destroy(wolf->area[2].array);
    return 0;
}

static int set_floor_with_flashlight(wolf_t *wolf, sfVector2u win_size, int x,
    area_t *floor)
{
    floor->array = sfVertexArray_create();
    if (!floor->array)
        return 84;
    sfVertexArray_setPrimitiveType(floor->array, sfQuads);
    floor->color = adjust_color_brightness(
        sfColor_fromRGB(100, 100, 100), wolf->brightness);
    floor->point[0].position = (sfVector2f){x, wolf->ray.draw[1]};
    floor->point[0].color = floor->color;
    floor->point[1].position = (sfVector2f){x + 1, wolf->ray.draw[1]};
    floor->point[1].color = floor->color;
    floor->point[2].position = (sfVector2f){x + 1, win_size.y};
    floor->point[2].color = floor->color;
    floor->point[3].position = (sfVector2f){x, win_size.y};
    floor->point[3].color = floor->color;
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(floor->array, floor->point[i]);
    sfRenderWindow_drawVertexArray(wolf->window, floor->array, NULL);
    sfVertexArray_destroy(floor->array);
    return 0;
}

static int set_wall_with_flashlight(area_t *wall, ray_t *ray, int x,
    wolf_t *wolf)
{
    wall->color = adjust_color_brightness(sfWhite, wolf->brightness);
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
        wall->point[i].color = wall->color;
        sfVertexArray_append(wall->array, wall->point[i]);
    }
    sfRenderWindow_drawVertexArray(wolf->window, wall->array, &wall->states);
    return sfVertexArray_destroy(wall->array), 0;
}

void draw_line_with_flashlight(wolf_t *wolf, int x)
{
    sfVector2u win_size = sfRenderWindow_getSize(wolf->window);
    float radius = (float)win_size.x / 4.0f;

    wolf->brightness = calculate_brightness(x, win_size, radius);
    if (set_ceiling_with_flashlight(wolf, x) != 0)
        return;
    if (set_wall_with_flashlight(&wolf->area[0],
        &wolf->ray, x, wolf) != 0)
            return;
    if (set_floor_with_flashlight(wolf, win_size, x,
        &wolf->area[1]) != 0)
            return;
}

void draw_line_verif(wolf_t *wolf, int x, int flashlight_enabled)
{
    if (flashlight_enabled) {
        draw_line_with_flashlight(wolf, x);
    } else {
        draw_line(wolf, x);
    }
}
