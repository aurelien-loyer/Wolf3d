/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** start_menu
*/
#include "include.h"

int is_mouse_on_button(wolf_t *wolf, sfVector2i mouse_pos, sfSprite *sprite)
{
    sfVector2f world_pos = sfRenderWindow_mapPixelToCoords
        (wolf->window, mouse_pos, sfRenderWindow_getView(wolf->window));
    sfFloatRect button_bounds = sfSprite_getGlobalBounds(sprite);

    return (world_pos.x >= button_bounds.left &&
            world_pos.x <= button_bounds.left + button_bounds.width &&
            world_pos.y >= button_bounds.top &&
            world_pos.y <= button_bounds.top + button_bounds.height);
}

static int verif_mouse_start(wolf_t *wolf)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wolf->window);

    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.button)) {
        sfMusic_stop(wolf->res.music);
        sfMusic_play(wolf->res.in_game);
        return 1;
    }
    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.quit))
        return sfRenderWindow_close(wolf->window), 1;
    if (is_mouse_on_button(wolf, mouse_pos, wolf->start.setting))
        return settings_menu(wolf);
    return 0;
}

int get_start_event(wolf_t *wolf, sfEvent tmp_event)
{
    sfFloatRect visibleArea = {0};
    sfView *view = {0};

    if (tmp_event.type == sfEvtMouseButtonPressed) {
        if (verif_mouse_start(wolf) == 1)
            return 1;
    }
    if (tmp_event.type == sfEvtClosed)
        return sfRenderWindow_close(wolf->window), 1;
    if (tmp_event.type == sfEvtResized) {
        visibleArea = (sfFloatRect)
            {0, 0, tmp_event.size.width, tmp_event.size.height};
        view = sfView_createFromRect(visibleArea);
        sfRenderWindow_setView(wolf->window, view);
        sfView_destroy(view);
        update_ui_positions(wolf);
    }
    return 0;
}

int start_menu_event(wolf_t *wolf, sfEvent event)
{
    while (sfRenderWindow_pollEvent(wolf->window, &event)) {
        set_cursor(wolf);
        if (get_start_event(wolf, event) == 1)
            return 1;
        if (sfKeyboard_isKeyPressed(sfKeyF11))
            handle_full_screen(wolf);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            change_resolution(wolf);
    }
    return 0;
}

void disp_menu(wolf_t *wolf)
{
    update_button_animation(wolf, wolf->start.button, &wolf->start.animation);
    update_button_animation(wolf, wolf->start.quit, &wolf->start.quit_anim);
    sfRenderWindow_drawSprite(wolf->window, wolf->start.back, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->start.setting, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->start.button, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->start.quit, NULL);
    sfRenderWindow_drawSprite(wolf->window, wolf->cursor.sprite, NULL);
}

void start_menu(wolf_t *wolf)
{
    int loop_condition = 0;

    if (wolf->bc.start == 1)
        return;
    wolf->bc.start = 1;
    sfMusic_play(wolf->res.music);
    init_button_animation(&wolf->start.animation, 1.0, 1.0, 1.125);
    init_button_animation(&wolf->start.quit_anim, 0.5, 0.5, 0.575);
    while (sfRenderWindow_pollEvent(wolf->window, &wolf->event));
    while (loop_condition == 0) {
        loop_condition = start_menu_event(wolf, wolf->event);
        sfRenderWindow_clear(wolf->window, sfBlack);
        disp_menu(wolf);
        sfRenderWindow_display(wolf->window);
    }
    while (sfRenderWindow_pollEvent(wolf->window, &wolf->event));
    sfClock_destroy(wolf->start.animation.clock);
}
