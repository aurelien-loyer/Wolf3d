/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** draw_sprite_in_game
*/
#include "include.h"
#include <math.h>

void draw_sprite_in_game(wolf_t *wolf)
{
    sfRenderWindow_drawSprite(wolf->window, wolf->lifebar.full, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->sprite.gun, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->sprite.crosshair, NULL);
    render_particle_system(wolf);
}
