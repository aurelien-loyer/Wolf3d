/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** animation
*/
#include "include.h"

void init_button_animation(button_animation_t *animation, float scale,
    float min, float max)
{
    animation->scale = scale;
    animation->scale_dir = scale;
    animation->is_hovering = sfFalse;
    animation->clock = sfClock_create();
    animation->scale_dif[0] = min;
    animation->scale_dif[1] = max;
}

void verif_size(button_animation_t *anim)
{
    if (anim->scale > anim->scale_dif[0]) {
        anim->scale -= 0.01f;
        if (anim->scale < anim->scale_dif[0])
            anim->scale = anim->scale_dif[0];
    }
}

void do_anim(button_animation_t *anim)
{
    if (anim->is_hovering) {
        anim->scale
            += anim->scale_dir * 0.002f;
        if (anim->scale >= anim->scale_dif[1]) {
            anim->scale = anim->scale_dif[1];
            anim->scale_dir = -anim->scale_dif[0];
        }
        if (anim->scale <= anim->scale_dif[0]) {
            anim->scale = anim->scale_dif[0];
            anim->scale_dir = anim->scale_dif[0];
        }
    } else {
        verif_size(anim);
    }
}

void set_scale(button_animation_t *anim, sfSprite *button, wolf_t *wolf)
{
    sfVector2u window_size = sfRenderWindow_getSize(wolf->window);
    sfVector2f scale = {(anim->scale * window_size.x) / sfTexture_getSize
        (wolf->start.back_text).x, (anim->scale * window_size.y) /
            sfTexture_getSize(wolf->start.back_text).y};

    sfSprite_setScale(button, scale);
}

void update_button_animation(wolf_t *wolf, sfSprite *button,
    button_animation_t *animation)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wolf->window);
    sfTime elapsed_time = sfClock_getElapsedTime(animation->clock);
    float seconds = sfTime_asSeconds(elapsed_time);
    sfBool is_hovering = is_mouse_on_button
        (wolf, mouse_pos, button);

    if (seconds > 10.0f)
        sfClock_restart(animation->clock);
    if (is_hovering != animation->is_hovering) {
        animation->is_hovering = is_hovering;
    }
    do_anim(animation);
    set_scale(animation, button, wolf);
}
