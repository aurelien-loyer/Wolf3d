/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** struct
*/

#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H
    #include "include.h"

typedef struct button_animation_s {
    float scale_dif[2];
    float scale;
    float scale_dir;
    sfClock *clock;
    sfBool is_hovering;
} button_animation_t;

typedef struct start_s {
    sfSprite *button;
    sfSprite *back;
    sfTexture *back_text;
    sfSprite *setting;
    sfSprite *quit;
    button_animation_t animation;
    button_animation_t quit_anim;
} start_t;

typedef struct beacon_s {
    int start;
    int settings_initialized;
    int pause_initialized;
    int player_initialized;
    int light;
    int is_fullscreen;
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
    float wall_dist;
    int line_y;
} ray_t, ray_cast_t;

typedef struct player_s {
    float pos[2];
    float dir[2];
    float pov[2];
    float speed;
    float rotation;
    float vertical_offset;
} player_t;

typedef struct area_s {
    sfVertexArray *array;
    sfVertex point[4];
    sfColor color;
    sfRenderStates states;
    sfTexture *text;
    float text_size[2];
} area_t;

typedef struct res_s {
    sfMusic *music;
    sfMusic *in_game;
    sfMusic *shot;
} res_t;

typedef struct game_sprite_s {
    sfSprite *gun;
    sfSprite *crosshair;
} game_sprite_t;

typedef struct cursor_s {
    sfSprite *sprite;
    sfVector2i pos;
} cursor_t;

typedef struct life_bar_s {
    sfSprite *full;
} life_bar_t;

typedef struct weapon_s {
    sfSprite *muzzle_flash_sprite;
    sfTexture *text;
    bool muzzle_flash_visible;
    int muzzle_flash_timer;
    float muzzle_flash_duration;
    float last_time;
    sfClock *clock;
} weapon_t;

typedef struct particle_s {
    sfVector2f position;
    sfVector2f velocity;
    sfVector2f acceleration;
    sfColor color;
    float life;
    float max_life;
    float size;
    sfBool active;
} particle_t;

typedef struct particle_system_s {
    particle_t particles[MAX_PARTICLES];
    int active_count;
    sfVertexArray *vertex_array;
    sfRenderStates render_states;
} particle_system_t;

// wall => 0 ; floor => 1 ; ceil => 2

typedef struct wolf_s {
    float camera_height;
    game_sprite_t sprite;
    sfRenderWindow *window;
    start_t start;
    sfEvent event;
    menu_t set;
    menu_t pause;
    beacon_t bc;
    res_t res;
    player_t player;
    ray_cast_t ray;
    area_t area[3];
    cursor_t cursor;
    life_bar_t lifebar;
    int **world;
    sfView *view;
    weapon_t weapon;
    particle_system_t particle_system;
    float delta;
    float brightness;
} wolf_t;

#endif
