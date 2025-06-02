/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** fullscreen_handling
*/
#include "include.h"

void handle_full_screen(wolf_t *wolf)
{
    sfVideoMode full_mode = sfVideoMode_getDesktopMode();
    float ratio = 16.0f / 9.0f;
    unsigned int height = full_mode.height;
    unsigned int width = height * ratio;
    sfVideoMode win_mode = {width, height, full_mode.bitsPerPixel};

    if (wolf->bc.is_fullscreen) {
        sfRenderWindow_destroy(wolf->window);
        wolf->window = sfRenderWindow_create(win_mode, "Wolf3D",
            sfResize | sfClose, NULL);
        wolf->bc.is_fullscreen = 0;
    } else {
        sfRenderWindow_destroy(wolf->window);
        wolf->window = sfRenderWindow_create(full_mode, "Wolf3D",
            sfFullscreen, NULL);
        wolf->bc.is_fullscreen = 1;
    }
    sfRenderWindow_setFramerateLimit(wolf->window, 64);
    sfRenderWindow_setMouseCursorVisible(wolf->window, sfFalse);
}
