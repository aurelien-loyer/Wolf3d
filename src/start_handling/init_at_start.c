/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** init_at_start
*/
#include "include.h"

void init_start(start_t *start)
{
    float scale[2] = {0};

    start->button = create_sprite("assets/start/button.png", (int[2]){WIDTH
        / 2, HEIGHT / 2}, (int[2]){600 / 2, 221 / 2}, (float[2]){1, 1});
    start->setting = create_sprite("assets/start/set.png", (int[2])
        {WIDTH - 5 * 0.2, 5 * 0.2}, (int[2]){525, 0}, (float[2]){0.2, 0.2});
    start->quit = create_sprite("assets/start/quit.png",
        (int[2]){WIDTH / 2, HEIGHT / 2 + HEIGHT / 4},
        (int[2]){600 / 2, 217 / 2}, (float[2]){0.5, 0.5});
    start->back = sfSprite_create();
    if (!start->back)
        return;
    start->back_text = sfTexture_createFromFile("assets/start/back.png", NULL);
    sfSprite_setTexture(start->back, start->back_text, sfTrue);
    scale[0] = (float)WIDTH / sfTexture_getSize(start->back_text).x;
    scale[1] = (float)HEIGHT / sfTexture_getSize(start->back_text).y;
    sfSprite_setScale(start->back, (sfVector2f){scale[0], scale[1]});
}

int init_window(wolf_t *wolf)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    float ratio = 16.0f / 9.0f;
    unsigned int height = mode.height;
    unsigned int width = height * ratio;
    sfVideoMode win_mode = {width, height, mode.bitsPerPixel};

    wolf->window = sfRenderWindow_create(win_mode, "Wolf3D", 2 | 4, NULL);
    if (!wolf->window)
        return fprintf(stderr, "wolf3d: failed to create window."), 84;
    sfRenderWindow_setFramerateLimit(wolf->window, 64);
    return 0;
}

int init_struct_at_start(wolf_t *wolf)
{
    init_start(&wolf->start);
    wolf->music = sfMusic_createFromFile("assets/song.mp3");
    sfMusic_setLoop(wolf->music, sfTrue);
    return init_window(wolf);
}
