/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** create_sprite
*/
#include "include.h"

sfSprite *create_sprite(char *text_path, int position[2],
    int origin[2], float scale[2])
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(text_path, NULL);

    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){position[0], position[1]});
    sfSprite_setOrigin(sprite, (sfVector2f){origin[0], origin[1]});
    sfSprite_setScale(sprite, (sfVector2f){scale[0], scale[1]});
    return sprite;
}
