/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** setting_menu
*/
#include "include.h"

static void set_scale(wolf_t *wolf, float scale[2])
{
    sfSprite_setScale(wolf->start.back, (sfVector2f){scale[0], scale[1]});
    sfSprite_setScale(wolf->set.panel,
        (sfVector2f){scale[0] * 1.2, scale[1] * 1.2});
    sfSprite_setScale(wolf->set.volume_on, (sfVector2f)
        {scale[0] * 0.6, scale[1] * 0.6});
    sfSprite_setScale(wolf->set.volume_off,
        (sfVector2f){scale[0] * 0.6, scale[1] * 0.6});
    sfSprite_setScale(wolf->set.back_button, (sfVector2f)
        {scale[0] * 0.5, scale[1] * 0.5});
}

static void update_settings_positions(wolf_t *wolf)
{
    sfVector2u win_size = sfRenderWindow_getSize(wolf->window);
    float scale[2] = {0};

    scale[0] = (float)win_size.x /
        sfTexture_getSize(wolf->start.back_text).x;
    scale[1] = (float)win_size.y /
        sfTexture_getSize(wolf->start.back_text).y;
    set_scale(wolf, scale);
    sfSprite_setPosition(wolf->set.panel, (sfVector2f){win_size.x / 2,
        win_size.y / 8});
    sfSprite_setPosition(wolf->set.volume_on,
        (sfVector2f){win_size.x / 2, win_size.y / 2});
    sfSprite_setPosition(wolf->set.volume_off,
        (sfVector2f){win_size.x / 2, win_size.y / 2});
}

static int handle_settings_buttons(wolf_t *wolf)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wolf->window);

    if (is_mouse_on_button(wolf, mouse_pos, wolf->set.back_button))
        return update_ui_positions(wolf), 1;
    if (is_mouse_on_button(wolf, mouse_pos, wolf->set.volume_on)) {
        wolf->set.volume_bool = wolf->set.volume_bool == sfTrue
            ? sfFalse : sfTrue;
        if (wolf->set.volume_bool == sfTrue)
            sfMusic_play(wolf->music);
        if (wolf->set.volume_bool == sfFalse)
            sfMusic_pause(wolf->music);
    }
    return 0;
}

static int settings_menu_event(wolf_t *wolf, sfEvent event)
{
    sfFloatRect visibleArea = {0};
    sfView *view = {0};

    while (sfRenderWindow_pollEvent(wolf->window, &event)) {
        if (event.type == sfEvtMouseButtonPressed
            && handle_settings_buttons(wolf))
                return 2;
        if (event.type == sfEvtClosed)
            return sfRenderWindow_close(wolf->window), 1;
        if (event.type == sfEvtResized) {
            visibleArea = (sfFloatRect)
                {0, 0, event.size.width, event.size.height};
            view = sfView_createFromRect(visibleArea);
            sfRenderWindow_setView(wolf->window, view);
            sfView_destroy(view);
            update_settings_positions(wolf);
        }
    }
    return 0;
}

void display_settings_menu(wolf_t *wolf)
{
    sfRenderWindow_drawSprite(wolf->window, wolf->start.back, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->set.panel, NULL);
    if (wolf->set.volume_bool == sfTrue)
        sfRenderWindow_drawSprite(wolf->window, wolf->set.volume_on, NULL);
    else
        sfRenderWindow_drawSprite(wolf->window, wolf->set.volume_off, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->set.back_button, NULL);
}

int settings_menu(wolf_t *wolf)
{
    int exit_settings = 0;

    if (!wolf->bc.settings_initialized) {
        init_settings_menu(wolf);
        wolf->bc.settings_initialized = 1;
    }
    while (!exit_settings && sfRenderWindow_isOpen(wolf->window)) {
        exit_settings = settings_menu_event(wolf, wolf->event);
        sfRenderWindow_clear(wolf->window, sfBlack);
        display_settings_menu(wolf);
        sfRenderWindow_display(wolf->window);
    }
    return exit_settings == 1 ? 1 : 0;
}

int verif_mouse(wolf_t *wolf)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wolf->window);

    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.button))
        return 1;
    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.quit))
        return sfRenderWindow_close(wolf->window), 1;
    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.setting)) {
        settings_menu(wolf);
        return 2;
    }
    return 0;
}

int init_settings_menu(wolf_t *wolf)
{
    sfVector2u win_s = sfRenderWindow_getSize(wolf->window);

    wolf->set.panel = create_sprite("assets/setting/panel.png", (int[2])
    {win_s.x / 2, win_s.y / 8}, (int[2]){300, 300}, (float[2]){1.2, 1.2});
    wolf->set.back_button = create_sprite("assets/setting/back.png", (int[2])
        {0, 0}, (int[2]){0, 0}, (float[2]){0.5, 0.5});
    wolf->set.volume_off = create_sprite("assets/setting/no_sound.png",
        (int[2]){win_s.x / 2, win_s.y / 2}, (int[2])
        {371 / 2, 371 / 2}, (float[2]){0.6, 0.6});
    wolf->set.volume_on = create_sprite("assets/setting/sound.png",
        (int[2]){win_s.x / 2, win_s.y / 2}, (int[2])
        {371 / 2, 371 / 2}, (float[2]){0.6, 0.6});
    wolf->set.volume = 0.5f;
    wolf->set.volume_bool = sfTrue;
    update_settings_positions(wolf);
    return 0;
}

void destroy_settings_menu(wolf_t *wolf)
{
    sfSprite_destroy(wolf->set.panel);
    sfSprite_destroy(wolf->set.back_button);
    sfSprite_destroy(wolf->set.volume_on);
    sfSprite_destroy(wolf->set.volume_off);
}
