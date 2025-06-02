/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** ui_positions_update
*/
#include "include.h"

void set_position(wolf_t *wolf, sfVector2u window_size)
{
    sfSprite_setPosition(wolf->start.button, (sfVector2f)
        {window_size.x / 2, window_size.y / 2});
    sfSprite_setPosition(wolf->start.setting, (sfVector2f)
        {window_size.x - 5 * 0.2, 5 * 0.2});
    sfSprite_setPosition(wolf->start.quit, (sfVector2f)
        {window_size.x / 2, window_size.y / 2 + window_size.y / 4});
    sfSprite_setPosition(wolf->lifebar.full, (sfVector2f)
        {window_size.x / 8, window_size.y / 10 * 9});
    sfSprite_setPosition(wolf->sprite.gun, (sfVector2f)
        {window_size.x / 2 + window_size.x / 6, window_size.y});
    sfSprite_setPosition(wolf->sprite.crosshair, (sfVector2f)
        {window_size.x / 2, window_size.y / 2});
    sfSprite_setPosition(wolf->weapon.muzzle_flash_sprite, (sfVector2f)
        {window_size.x / 2, window_size.y / 2});
}

void set_scale_ui(wolf_t *wolf, float scale_x, float scale_y)
{
    sfSprite_setScale(wolf->start.back, (sfVector2f){scale_x, scale_y});
    sfSprite_setScale(wolf->start.button, (sfVector2f){scale_x, scale_y});
    sfSprite_setScale(wolf->start.quit,
        (sfVector2f){scale_x * 0.5, scale_y * 0.5});
    sfSprite_setScale(wolf->cursor.sprite, (sfVector2f)
        {scale_x * 0.05, scale_y * 0.05});
    sfSprite_setScale(wolf->start.setting,
        (sfVector2f){scale_x * 0.2, scale_y * 0.2});
    sfSprite_setScale(wolf->lifebar.full,
        (sfVector2f){scale_x * 0.3, scale_y * 0.3});
    sfSprite_setScale(wolf->sprite.gun,
        (sfVector2f){scale_x * 0.9, scale_y * 0.9});
    sfSprite_setScale(wolf->sprite.crosshair,
        (sfVector2f){scale_x * 0.25, scale_y * 0.25});
    sfSprite_setScale(wolf->weapon.muzzle_flash_sprite,
        (sfVector2f){scale_x * 1, scale_y * 1});
}

void update_ui_positions(wolf_t *wolf)
{
    sfVector2u window_size = sfRenderWindow_getSize(wolf->window);
    float scale_x = 0;
    float scale_y = 0;

    set_position(wolf, window_size);
    scale_x = (float)window_size.x /
        sfTexture_getSize(wolf->start.back_text).x;
    scale_y = (float)window_size.y /
        sfTexture_getSize(wolf->start.back_text).y;
    set_scale_ui(wolf, scale_x, scale_y);
}
