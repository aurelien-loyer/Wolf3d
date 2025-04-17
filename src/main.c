/*
** EPITECH PROJECT, 2025
** bs_my_world
** File description:
** main
*/
#include "include.h"

void loop_exec(wolf_t *wolf)
{
    start_menu(wolf);
    ray_casting(wolf);
}

void destroy_all(wolf_t *wolf)
{
    sfRenderWindow_destroy(wolf->window);
    sfSprite_destroy(wolf->start.back);
    sfSprite_destroy(wolf->start.button);
    sfSprite_destroy(wolf->start.quit);
    sfSprite_destroy(wolf->start.setting);
}

int main(void)
{
    wolf_t wolf_struct = {0};

    if (init_struct_at_start(&wolf_struct) != 0)
        return 84;
    while (sfRenderWindow_isOpen(wolf_struct.window)) {
        event_handling(&wolf_struct);
        sfRenderWindow_clear(wolf_struct.window, sfBlack);
        loop_exec(&wolf_struct);
        sfRenderWindow_display(wolf_struct.window);
    }
    destroy_all(&wolf_struct);
    return 0;
}
