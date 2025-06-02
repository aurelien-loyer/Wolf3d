/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** function
*/

#ifndef INCLUDED_FUNCTION_H
    #define INCLUDED_FUNCTION_H

/// GLOBAL
int init_struct_at_start(wolf_t *wolf_struct);
void free_array(void **ptr);
void my_free(void *ptr);
void center_mouse(sfRenderWindow *window);

/// MENU HANDLING
int pause_menu(wolf_t *wolf);
void start_menu(wolf_t *wolf);
int settings_menu(wolf_t *wolf);
void update_ui_positions(wolf_t *wolf);

// DESTROY
int destroy_all(wolf_t *wolf);
void destroy_settings_menu(wolf_t *wolf);
void destroy_pause_menu(wolf_t *wolf);

// INITIALISATION
void init_start(start_t *start, wolf_t *wolf);
void init_settings(menu_t *set);
int init_settings_menu(wolf_t *wolf);
void init_pause(menu_t *set);
int init_pause_menu(wolf_t *wolf);
void init_muzzle_flash(wolf_t *wolf);

/// SPRITE
sfSprite *create_sprite(char *text_path, int position[2],
    int origin[2], float scale[2]);
int is_sprite_clicked(sfSprite *sprite, int x, int y);
void set_cursor(wolf_t *wolf);
void draw_sprite_in_game(wolf_t *wolf);
void draw_bullet_impacts(sfRenderWindow *window, wolf_t *wolf);
void render_muzzle_flash(wolf_t *wolf);

/// INTERACTION
void simulate_bullet_impact(wolf_t *wolf, int **world);
void event_handling(wolf_t *wolf);
int is_mouse_on_button(wolf_t *wolf, sfVector2i mouse_pos, sfSprite *sprite);
int verif_mouse(wolf_t *wolf);
void update_button_animation(wolf_t *wolf, sfSprite *sprite,
    button_animation_t *anim);
void init_button_animation(button_animation_t *anim, float scale,
    float min, float max);
void handle_mouse_movement(wolf_t *wolf);
void handle_vertical_movement_keys(wolf_t *wolf);
void update_muzzle_flash(wolf_t *wolf, float delta_time);
void handle_full_screen(wolf_t *wolf);
void change_resolution(wolf_t *wolf);

/// RAY CASTING
void ray_casting(wolf_t *wolf);
void move_handling(player_t *player, int **map);
void do_dda(ray_t *ray, int **map);
void draw_line(wolf_t *wolf, int x);
void draw_line_verif(wolf_t *wolf, int x, int flashlight_enabled);
sfColor adjust_color_brightness(sfColor original, float brightness);
float calculate_brightness(int x, sfVector2u win_size, float radius);

// PARTICULE
void init_particle(particle_t *particle, sfVector2f pos,
    sfVector2f vel, float life);
void update_particle_system(wolf_t *wolf, float delta_time);
void render_particle_system(wolf_t *wolf);
void emit_muzzle_flash_particles(wolf_t *wolf);
void init_particle_system(wolf_t *wolf);

/// LOAD MAP
int load_map(wolf_t *wolf_struct, char **av);
int add_to_map(wolf_t *wolf_struct, char *line, int size);
int len_map(int **map);

#endif
