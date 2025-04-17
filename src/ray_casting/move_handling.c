/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** move_handling
*/
#include "include.h"

void left_moves(player_t *player)
{
    double old_dir = 0.0;
    double old_pov = 0.0;

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        old_dir = player->dir[0];
        player->dir[0] = player->dir[0] * cos(-player->rotation)
            - player->dir[1] * sin(-player->rotation);
        player->dir[1] = old_dir * sin(-player->rotation)
            + player->dir[1] * cos(-player->rotation);
        old_pov = player->pov[0];
        player->pov[0] = player->pov[0] * cos(-player->rotation)
            - player->pov[1] * sin(-player->rotation);
        player->pov[1] = old_pov * sin(-player->rotation) + player->pov[1]
            * cos(-player->rotation);
    }
}

void left_right_moves(player_t *player)
{
    double old_dir = 0.0;
    double old_pov = 0.0;

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        old_dir = player->dir[0];
        player->dir[0] = player->dir[0] * cos(player->rotation)
            - player->dir[1] * sin(player->rotation);
        player->dir[1] = old_dir * sin(player->rotation) + player->dir[1]
            * cos(player->rotation);
        old_pov = player->pov[0];
        player->pov[0] = player->pov[0] * cos(player->rotation)
            - player->pov[1] * sin(player->rotation);
        player->pov[1] = old_pov * sin(player->rotation) + player->pov[1]
            * cos(player->rotation);
    }
    left_moves(player);
}

void move_handling(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (world[(int)(player->pos[0] + player->dir[0] *
            player->speed)][(int)(player->pos[1])] == 0)
                player->pos[0] += player->dir[0] * player->speed;
        if (world[(int)(player->pos[0])][(int)(player->pos[1] +
            player->dir[1] * player->speed)] == 0)
                player->pos[1] += player->dir[1] * player->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (world[(int)(player->pos[0] - player->dir[0] * player->speed)]
            [(int)(player->pos[1])] == 0)
                player->pos[0] -= player->dir[0] * player->speed;
        if (world[(int)(player->pos[0])]
            [(int)(player->pos[1] - player->dir[1] * player->speed)] == 0)
                player->pos[1] -= player->dir[1] * player->speed;
    }
    left_right_moves(player);
}
