/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** event
*/
#include "include.h"

void key_pressed_handling(wolf_t *wolf)
{
    if (wolf->event.key.code == sfKeyEscape) {
        pause_menu(wolf);
    }
}

void event_handling(wolf_t *wolf)
{
    while (sfRenderWindow_pollEvent(wolf->window, &wolf->event)) {
        if (wolf->event.type == sfEvtClosed)
            sfRenderWindow_close(wolf->window);
        if (wolf->event.type == sfEvtKeyPressed)
            key_pressed_handling(wolf);
    }
}
