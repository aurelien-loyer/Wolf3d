/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** move_handling
*/
#include "include.h"

void left_right_moves(player_t *player, int **world)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (world[(int)(player->pos[0] + (-player->dir[1] *
            player->speed))][(int)(player->pos[1])] == 0)
            player->pos[0] += -player->dir[1] * player->speed;
        if (world[(int)(player->pos[0])][(int)
            (player->pos[1] + player->dir[0] * player->speed)] == 0)
            player->pos[1] += player->dir[0] * player->speed;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (world[(int)(player->pos[0] + player->dir[1] *
            player->speed)][(int)(player->pos[1])] == 0)
            player->pos[0] += player->dir[1] * player->speed;
        if (world[(int)(player->pos[0])][(int)(player->pos[1]
            + (-player->dir[0] * player->speed))] == 0)
            player->pos[1] += -player->dir[0] * player->speed;
    }
}

void move_handling(player_t *player, int **world)
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
    left_right_moves(player, world);
}
