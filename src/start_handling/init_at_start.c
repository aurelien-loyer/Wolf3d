/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** init_at_start
*/
#include "include.h"

static void init_lifebar(life_bar_t *lifebar)
{
    lifebar->full = create_sprite("assets/in_game/life_bar/full.png",
        (int[2]){WIDTH / 8, HEIGHT / 10 * 9}, (int[2]){874 / 2, 178 / 2},
            (float[2]){0.3, 0.3});
}

static void init_back(start_t *start, float scale[2])
{
    start->back = sfSprite_create();
    if (!start->back)
        return;
    start->back_text = sfTexture_createFromFile("assets/start/back.png", NULL);
    sfSprite_setTexture(start->back, start->back_text, sfTrue);
    scale[0] = (float)WIDTH / sfTexture_getSize(start->back_text).x;
    scale[1] = (float)HEIGHT / sfTexture_getSize(start->back_text).y;
    sfSprite_setScale(start->back, (sfVector2f){scale[0], scale[1]});
}

static void init_game_sprite(wolf_t *wolf)
{
    wolf->sprite.gun = create_sprite("assets/in_game/gun.png", (int[2])
        {WIDTH / 2 + WIDTH / 6, HEIGHT}, (int[2]){726 / 2, 477}, (float[2])
            {0.9, 0.9});
    wolf->weapon.text = sfTexture_createFromFile("assets/in_game/gun.png",
        NULL);
    wolf->sprite.crosshair = create_sprite("assets/in_game/viseur.png",
        (int[2]){WIDTH / 2, HEIGHT / 2}, (int[2]){160, 120}, (float[2])
            {0.4, 0.4});
    wolf->weapon.muzzle_flash_sprite = create_sprite
        ("assets/in_game/flash_muzzle.png", (int[2]){0, 0}, (int[2])
            {-42.5, 17.5}, (float[2]){1, 1});
    sfSprite_setRotation(wolf->weapon.muzzle_flash_sprite, 33);
}

void init_start(start_t *start, wolf_t *wolf)
{
    float scale[2] = {0};

    start->button = create_sprite("assets/start/button.png", (int[2]){WIDTH
        / 2, HEIGHT / 2}, (int[2]){600 / 2, 221 / 2}, (float[2]){1, 1});
    start->setting = create_sprite("assets/start/set.png", (int[2])
        {WIDTH - 5 * 0.2, 5 * 0.2}, (int[2]){525, 0}, (float[2]){0.2, 0.2});
    start->quit = create_sprite("assets/start/quit.png",
        (int[2]){WIDTH / 2, HEIGHT / 2 + HEIGHT / 4},
        (int[2]){600 / 2, 217 / 2}, (float[2]){0.5, 0.5});
    wolf->cursor.sprite = create_sprite("assets/cursor.png", (int[2])
        {0, 0}, (int[2]){0, 0}, (float[2]){0.05, 0.05});
    init_back(start, scale);
    init_lifebar(&wolf->lifebar);
    init_game_sprite(wolf);
}

int init_window(wolf_t *wolf)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    float ratio = 16.0f / 9.0f;
    unsigned int height = mode.height;
    unsigned int width = height * ratio;
    sfVideoMode win_mode = {width, height, mode.bitsPerPixel};

    wolf->window = sfRenderWindow_create(win_mode, "Wolf3D", 8, NULL);
    if (!wolf->window)
        return fprintf(stderr, "wolf3d: failed to create window."), 84;
    sfRenderWindow_setFramerateLimit(wolf->window, 64);
    return 0;
}

void init_res(wolf_t *wolf)
{
    wolf->res.music = sfMusic_createFromFile("assets/music/song.mp3");
    sfMusic_setLoop(wolf->res.music, sfTrue);
    wolf->res.in_game = sfMusic_createFromFile("assets/music/in_party.mp3");
    sfMusic_setLoop(wolf->res.in_game, sfTrue);
    sfMusic_setVolume(wolf->res.in_game, 20);
    wolf->res.shot = sfMusic_createFromFile("assets/music/uzi.mp3");
    sfMusic_setLoop(wolf->res.shot, sfFalse);
    sfMusic_setVolume(wolf->res.shot, 100);
}

static void set_area(wolf_t *wolf)
{
    wolf->area[0].text = sfTexture_createFromFile
        ("assets/in_game/wall.png", NULL);
    wolf->area[0].states = (sfRenderStates){
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = wolf->area[0].text,
        .shader = NULL
    };
    wolf->area[0].text_size[0] = 1024;
    wolf->area[0].text_size[1] = 1024;
}

void init_particle_system(wolf_t *wolf)
{
    wolf->particle_system.active_count = 0;
    wolf->particle_system.vertex_array = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(wolf->particle_system.vertex_array,
        sfQuads);
    for (int i = 0; i < MAX_PARTICLES; i++) {
        wolf->particle_system.particles[i].active = sfFalse;
    }
    wolf->particle_system.render_states.blendMode = sfBlendAlpha;
    wolf->particle_system.render_states.transform = sfTransform_Identity;
    wolf->particle_system.render_states.texture = NULL;
    wolf->particle_system.render_states.shader = NULL;
}

int init_struct_at_start(wolf_t *wolf)
{
    init_start(&wolf->start, wolf);
    init_res(wolf);
    set_area(wolf);
    init_particle_system(wolf);
    wolf->weapon.clock = sfClock_create();
    return init_window(wolf);
}
