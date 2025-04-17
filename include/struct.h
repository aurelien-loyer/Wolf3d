/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
    #include "include.h"

extern int world[24][24];

typedef struct sprite_s {
    sfSprite *button;
    sfTexture *text;
} sprite_t;

typedef struct start_s {
    sfSprite *button;
    sfSprite *back;
    sfTexture *back_text;
    sfSprite *setting;
    sfSprite *quit;
} start_t;

typedef struct beacon_s {
    int start;
    int settings_initialized;
    int pause_initialized;
    int player_initialized;
} beacon_t;

typedef struct menu_s {
    sfSprite *panel;
    sfSprite *back_button;
    sfSprite *volume_off;
    sfSprite *volume_on;
    sfBool volume_bool;
    float volume;
} menu_t;

typedef struct ray_cast_s {
    float pov;
    float dir[2];
    float dist[2];
    float side_dist[2];
    int step[2];
    int map[2];
    int draw[2];
    int hit_wall;
    int side_dir;
    int wall_dist;
    int line_y;
} ray_t, ray_cast_t;

typedef struct player_s {
    float pos[2];
    float dir[2];
    float pov[2];
    float speed;
    float rotation;
} player_t;

typedef struct area_s {
    sfVertexArray *array;
    sfVertex point[4];
} area_t;

typedef struct wolf_s {
    sfRenderWindow *window;
    start_t start;
    sfEvent event;
    menu_t set;
    menu_t pause;
    beacon_t bc;
    sfMusic *music;
    player_t player;
    ray_cast_t ray;
    area_t ceil;
    area_t wall;
    area_t floor;
} wolf_t;

#endif
