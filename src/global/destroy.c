/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** destroy
*/
#include "include.h"

void destroy_sprite(wolf_t *wolf)
{
    sfSprite_destroy(wolf->start.button);
    sfSprite_destroy(wolf->start.back);
    sfSprite_destroy(wolf->start.setting);
    sfSprite_destroy(wolf->start.quit);
    destroy_settings_menu(wolf);
    sfSprite_destroy(wolf->sprite.crosshair);
    sfSprite_destroy(wolf->sprite.gun);
    sfSprite_destroy(wolf->cursor.sprite);
    sfSprite_destroy(wolf->weapon.muzzle_flash_sprite);
    sfSprite_destroy(wolf->lifebar.full);
}

void destroy_texture(wolf_t *wolf)
{
    sfTexture_destroy(wolf->start.back_text);
    sfTexture_destroy(wolf->weapon.text);
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(wolf->area[i].text);
    }
}

void destroy_particle_system(wolf_t *wolf)
{
    if (wolf->particle_system.vertex_array)
        sfVertexArray_destroy(wolf->particle_system.vertex_array);
}

int destroy_all(wolf_t *wolf)
{
    destroy_sprite(wolf);
    destroy_texture(wolf);
    sfRenderWindow_destroy(wolf->window);
    sfMusic_destroy(wolf->res.shot);
    sfMusic_destroy(wolf->res.music);
    sfMusic_destroy(wolf->res.in_game);
    free_array((void *)wolf->world);
    destroy_particle_system(wolf);
    return 0;
}
