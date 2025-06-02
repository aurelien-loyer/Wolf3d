/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** ray_casting
*/
#include "include.h"

static int get_index_spawn(int *map, int len)
{
    for (int i = 0; i < len; i++)
        if (map[i] == CHARACTER_POSPLAYER)
            return i;
    return -1;
}

static void set_pos_player(int **map, float *x, float *y)
{
    int index_y = -1;
    int len = len_map(map);

    for (int index_x = 0; map[index_x]; index_x++){
        index_y = get_index_spawn(map[index_x], len);
        if (index_y == -1)
            continue;
        (*x) = index_x;
        (*y) = index_y;
        map[index_x][index_y] = 0;
    }
}

static void init_player(player_t *player, int **map)
{
    set_pos_player(map, &player->pos[0], &player->pos[1]);
    player->dir[0] = 1.0;
    player->dir[1] = 0.0;
    player->pov[0] = 0.0;
    player->pov[1] = 0.66;
    player->speed = 0.03;
    player->rotation = 0.05;
    player->vertical_offset = 0.0;
}

static void wall_verif(ray_t *ray, player_t *player)
{
    if (ray->side_dir == 0) {
        if (fabs(ray->dir[0]) < 1e-10)
            ray->wall_dist = 1e30;
        else
            ray->wall_dist = fabs((ray->map[0] - player->pos[0]
                + (1 - ray->step[0]) / 2) / ray->dir[0]);
    } else {
        if (fabs(ray->dir[1]) < 1e-10)
            ray->wall_dist = 1e30;
        else
            ray->wall_dist = fabs((ray->map[1] - player->pos[1]
                + (1 - ray->step[1]) / 2) / ray->dir[1]);
    }
}

void wall_handling(ray_t *ray, int height, player_t *player)
{
    int vertical_offset = 0;

    wall_verif(ray, player);
    if (ray->wall_dist < 0.01)
        ray->wall_dist = 0.01;
    ray->line_y = (int)(height / ray->wall_dist);
    vertical_offset = (int)player->vertical_offset;
    ray->draw[0] = -ray->line_y / 2 + height / 2 + vertical_offset;
    ray->draw[1] = ray->line_y / 2 + height / 2 + vertical_offset;
}

void ray_handling(ray_t *ray, player_t *player, unsigned int x,
    unsigned int win_x)
{
    ray->pov = 2 * x / (float)win_x - 1;
    ray->dir[0] = player->dir[0] + player->pov[0] * ray->pov;
    ray->dir[1] = player->dir[1] + player->pov[1] * ray->pov;
    ray->map[0] = (int)player->pos[0];
    ray->map[1] = (int)player->pos[1];
    ray->dist[0] = fabs(ray->dir[0]) < 1e-10 ? 1e30 : fabs(1 / ray->dir[0]);
    ray->dist[1] = fabs(ray->dir[1]) < 1e-10 ? 1e30 : fabs(1 / ray->dir[1]);
    for (int i = 0; i < 2; i++) {
        if (ray->dir[i] < 0) {
            ray->step[i] = -1;
            ray->side_dist[i] = (player->pos[i] - ray->map[i]) * ray->dist[i];
        } else {
            ray->step[i] = 1;
            ray->side_dist[i] = (ray->map[i] + 1.0
                - player->pos[i]) * ray->dist[i];
        }
    }
}

void ray_casting(wolf_t *wolf)
{
    sfVector2u win_size = sfRenderWindow_getSize(wolf->window);

    if (wolf->bc.player_initialized == 0) {
        init_player(&wolf->player, wolf->world);
        wolf->bc.player_initialized = 1;
    }
    move_handling(&wolf->player, wolf->world);
    handle_mouse_movement(wolf);
    for (unsigned int x = 0; x < win_size.x; x++) {
        ray_handling(&wolf->ray, &wolf->player, x, win_size.x);
        do_dda(&wolf->ray, wolf->world);
        wall_handling(&wolf->ray, win_size.y, &wolf->player);
        draw_line_verif(wolf, x, wolf->bc.light);
    }
}
