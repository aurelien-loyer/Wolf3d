/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** dda_algo
*/
#include "include.h"

void do_dda(ray_t *ray, int **world)
{
    ray->hit_wall = 0;
    while (ray->hit_wall == 0) {
        if (ray->side_dist[0] < ray->side_dist[1]) {
            ray->side_dist[0] += ray->dist[0];
            ray->map[0] += ray->step[0];
            ray->side_dir = 0;
        } else {
            ray->side_dist[1] += ray->dist[1];
            ray->map[1] += ray->step[1];
            ray->side_dir = 1;
        }
        if (ray->map[0] < 0 || ray->map[0] >= 24
            || ray->map[1] < 0 || ray->map[1] >= 24) {
            ray->hit_wall = 1;
            break;
        }
        if (world[ray->map[0]][ray->map[1]] > 0)
            ray->hit_wall = 1;
    }
}
