/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** main
*/
#include "include.h"

void center_mouse(sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2i center = {window_size.x / 2, window_size.y / 2};

    sfMouse_setPositionRenderWindow(center, window);
}

void set_cursor(wolf_t *wolf)
{
    wolf->cursor.pos = sfMouse_getPositionRenderWindow(wolf->window);
    sfSprite_setPosition(wolf->cursor.sprite, (sfVector2f)
        {wolf->cursor.pos.x, wolf->cursor.pos.y});
}

void loop_exec(wolf_t *wolf)
{
    float delta_time = sfTime_asSeconds(sfClock_getElapsedTime
        (wolf->weapon.clock)) - wolf->weapon.last_time;

    start_menu(wolf);
    ray_casting(wolf);
    wolf->weapon.last_time = sfTime_asSeconds
        (sfClock_getElapsedTime(wolf->weapon.clock));
    update_particle_system(wolf, delta_time);
    draw_sprite_in_game(wolf);
}

int main(int ac, char **av)
{
    wolf_t wolf_struct = {0};

    if (ac < 2){
        fprintf(stderr, "\033[1;31mNot enough arguments:\033[0m ");
        return fprintf(stderr, "./wolf3d [mapfile]\n"), 84;
    }
    if (init_struct_at_start(&wolf_struct) != 0)
        return 84;
    if (load_map(&wolf_struct, av) == 84)
        return destroy_all(&wolf_struct), 84;
    init_particle_system(&wolf_struct);
    sfRenderWindow_setMouseCursorVisible(wolf_struct.window, sfFalse);
    center_mouse(wolf_struct.window);
    while (sfRenderWindow_isOpen(wolf_struct.window)) {
        event_handling(&wolf_struct);
        sfRenderWindow_clear(wolf_struct.window, sfBlack);
        loop_exec(&wolf_struct);
        sfRenderWindow_display(wolf_struct.window);
    }
    return destroy_all(&wolf_struct);
}
