/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** mouse_handling
*/
#include "include.h"

static void rotate_player(player_t *player, float angle)
{
    float old_dir_x = player->dir[0];
    float old_plane_x = player->pov[0];

    player->dir[0] = player->dir[0] * cos(angle) - player->dir[1] * sin(angle);
    player->dir[1] = old_dir_x * sin(angle) + player->dir[1] * cos(angle);
    player->pov[0] = player->pov[0] * cos(angle) - player->pov[1] * sin(angle);
    player->pov[1] = old_plane_x * sin(angle) + player->pov[1] * cos(angle);
}

void calculate_move(wolf_t *wolf, sfVector2i mouse_pos, sfVector2u window_size
    , sfVector2i last_pos)
{
    int delta_x = mouse_pos.x - last_pos.x;
    int delta_y = mouse_pos.y - last_pos.y;
    float sensitivity_x = 0.0005;
    float sensitivity_y = 0.001;
    static float vertical_angle = 0.0f;

    if (delta_x != 0) {
        rotate_player(&wolf->player, delta_x * sensitivity_x);
    }
    if (delta_y != 0) {
        vertical_angle -= delta_y * sensitivity_y;
        if (vertical_angle > 1.0f)
            vertical_angle = 1.0f;
        if (vertical_angle < -1.0f)
            vertical_angle = -1.0f;
        wolf->player.vertical_offset = vertical_angle * (window_size.y / 3);
    }
}

void handle_mouse_movement(wolf_t *wolf)
{
    sfVector2i mouse_pos = {0};
    sfVector2i center = {0};
    sfVector2u window_size = sfRenderWindow_getSize(wolf->window);
    static sfVector2i last_pos = {0, 0};
    static int first_frame = 1;

    mouse_pos = sfMouse_getPositionRenderWindow(wolf->window);
    if (first_frame) {
        last_pos = mouse_pos;
        first_frame = 0;
        return;
    }
    calculate_move(wolf, mouse_pos, window_size, last_pos);
    center = (sfVector2i){window_size.x / 2, window_size.y / 2};
    sfMouse_setPositionRenderWindow(center, wolf->window);
    last_pos = center;
}
