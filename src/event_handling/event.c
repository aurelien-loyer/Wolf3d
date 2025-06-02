/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** event
*/
#include "include.h"

void change_resolution(wolf_t *wolf)
{
    sfVideoMode mode = {0};
    static int current_resolution = 0;

    mode.bitsPerPixel = 64;
    if (current_resolution == 0) {
        mode.width = 800;
        mode.height = 600;
        current_resolution = 1;
    } else {
        mode.width = 1920;
        mode.height = 1080;
        current_resolution = 0;
    }
    sfRenderWindow_destroy(wolf->window);
    wolf->window = sfRenderWindow_create(mode, "Wolf3D", 2 | 4, NULL);
    if (!wolf->window)
        return;
    sfRenderWindow_setMouseCursorVisible(wolf->window, sfFalse);
    sfRenderWindow_setFramerateLimit(wolf->window, 64);
    wolf->bc.is_fullscreen = 0;
}

void key_pressed_handling(wolf_t *wolf)
{
    if (wolf->event.key.code == sfKeyEscape)
        pause_menu(wolf);
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        wolf->player.speed = 0.09;
    else
        wolf->player.speed = 0.03;
    if (sfKeyboard_isKeyPressed(sfKeyF))
        wolf->bc.light = wolf->bc.light == 0 ? 1 : 0;
    if (wolf->event.key.code == sfKeyF11)
        handle_full_screen(wolf);
    if (wolf->event.key.code == sfKeyR)
        change_resolution(wolf);
}

static void shot_verif(wolf_t *wolf)
{
    sfSoundStatus stat = sfMusic_getStatus(wolf->res.shot);

    if (sfMouse_isButtonPressed(sfMouseLeft) && wolf->bc.start == 1) {
        if (stat == sfStopped)
            sfMusic_play(wolf->res.shot);
        emit_muzzle_flash_particles(wolf);
    } else {
        sfMusic_stop(wolf->res.shot);
        wolf->weapon.muzzle_flash_visible = false;
        wolf->weapon.muzzle_flash_timer = 0;
    }
}

static void check_key_type(wolf_t *wolf)
{
    if (wolf->event.type == sfEvtClosed)
        sfRenderWindow_close(wolf->window);
    if (wolf->event.type == sfEvtKeyPressed)
        key_pressed_handling(wolf);
}

void event_handling(wolf_t *wolf)
{
    sfFloatRect visibleArea = {0};

    while (sfRenderWindow_pollEvent(wolf->window, &wolf->event)) {
        check_key_type(wolf);
        wolf->cursor.pos = sfMouse_getPositionRenderWindow(wolf->window);
        sfSprite_setPosition(wolf->cursor.sprite, (sfVector2f)
            {wolf->cursor.pos.x, wolf->cursor.pos.y});
        if (wolf->event.type == sfEvtResized) {
            visibleArea = (sfFloatRect)
            {0, 0, wolf->event.size.width, wolf->event.size.height};
            wolf->view = sfView_createFromRect(visibleArea);
            sfRenderWindow_setView(wolf->window, wolf->view);
            sfView_destroy(wolf->view);
            update_ui_positions(wolf);
        }
    }
    shot_verif(wolf);
}
