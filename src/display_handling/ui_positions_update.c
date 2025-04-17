/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** ui_positions_update
*/
#include "include.h"

void update_ui_positions(wolf_t *wolf)
{
    sfVector2u window_size = sfRenderWindow_getSize(wolf->window);
    float scale_x = 0;
    float scale_y = 0;

    sfSprite_setPosition(wolf->start.button, (sfVector2f)
        {window_size.x / 2, window_size.y / 2});
    sfSprite_setPosition(wolf->start.setting, (sfVector2f)
        {window_size.x - 5 * 0.2, 5 * 0.2});
    sfSprite_setPosition(wolf->start.quit, (sfVector2f)
        {window_size.x / 2, window_size.y / 2 + window_size.y / 4});
    scale_x = (float)window_size.x /
        sfTexture_getSize(wolf->start.back_text).x;
    scale_y = (float)window_size.y /
        sfTexture_getSize(wolf->start.back_text).y;
    sfSprite_setScale(wolf->start.back, (sfVector2f){scale_x, scale_y});
    sfSprite_setScale(wolf->start.button, (sfVector2f){scale_x, scale_y});
    sfSprite_setScale(wolf->start.quit,
        (sfVector2f){scale_x * 0.5, scale_y * 0.5});
    sfSprite_setScale(wolf->start.setting,
        (sfVector2f){scale_x * 0.2, scale_y * 0.2});
}
