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

/// MENU HANDLING
int pause_menu(wolf_t *wolf);
void start_menu(wolf_t *wolf);
int settings_menu(wolf_t *wolf);
void update_ui_positions(wolf_t *wolf);

// destroy
void destroy_settings_menu(wolf_t *wolf);
void destroy_pause_menu(wolf_t *wolf);

// initialisation
void init_start(start_t *start);
void init_settings(menu_t *set);
int init_settings_menu(wolf_t *wolf);
void init_pause(menu_t *set);
int init_pause_menu(wolf_t *wolf);

/// SPRITE
sfSprite *create_sprite(char *text_path, int position[2],
    int origin[2], float scale[2]);
int is_sprite_clicked(sfSprite *sprite, int x, int y);

/// INTERACTION
void event_handling(wolf_t *wolf);
int is_mouse_on_button(wolf_t *wolf, sfVector2i mouse_pos, sfSprite *sprite);
int verif_mouse(wolf_t *wolf);

/// RAY CASTING
void ray_casting(wolf_t *wolf);
void move_handling(player_t *player);
void do_dda(ray_t *ray);
void draw_line(wolf_t *wolf, int x);

#endif
