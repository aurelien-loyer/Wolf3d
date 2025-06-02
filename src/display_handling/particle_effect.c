/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** particle_effect
*/
#include "include.h"

void init_particle(particle_t *particle, sfVector2f pos,
    sfVector2f vel, float life)
{
    particle->position = pos;
    particle->velocity = vel;
    particle->life = life;
    particle->max_life = life;
    particle->active = sfTrue;
    particle->color = (sfColor){200, 200, 200, 100};
    particle->size = 2.0f + ((float)(rand() % 10) / 2.0f);
    particle->acceleration = (sfVector2f){0, -15.0f};
}

static particle_t *get_free_particle(particle_system_t *system)
{
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (!system->particles[i].active)
            return &system->particles[i];
    }
    return NULL;
}

static void update_particle(particle_t *particle, float delta_time)
{
    float life_ratio = 0;

    if (!particle->active)
        return;
    particle->velocity.x += particle->acceleration.x * delta_time;
    particle->velocity.y += particle->acceleration.y * delta_time;
    particle->position.x += particle->velocity.x * delta_time;
    particle->position.y += particle->velocity.y * delta_time;
    particle->life -= delta_time;
    if (particle->life <= 0) {
        particle->active = sfFalse;
        return;
    }
    life_ratio = particle->life / particle->max_life;
    particle->color.a = (sfUint8)(255 * life_ratio);
    particle->size += delta_time * 10.0f;
}

static void loop_for_particles_sys(wolf_t *wolf, float delta_time, int i)
{
    if (wolf->particle_system.particles[i].active) {
        update_particle(&wolf->particle_system.particles[i], delta_time);
        if (wolf->particle_system.particles[i].active)
            wolf->particle_system.active_count++;
    }
}

void update_particle_system(wolf_t *wolf, float delta_time)
{
    wolf->particle_system.active_count = 0;
    for (int i = 0; i < MAX_PARTICLES; i++) {
        loop_for_particles_sys(wolf, delta_time, i);
    }
}

static int loop_render_particle_sys(wolf_t *wolf, int i)
{
    sfVertex vertices[4] = {0};
    particle_t *p = &wolf->particle_system.particles[i];
    float half_size = p->size / 2.0f;

    if (!p->active)
        return 2;
    vertices[0].position = (sfVector2f){p->position.x
        - half_size, p->position.y - half_size};
    vertices[1].position = (sfVector2f){p->position.x
        + half_size, p->position.y - half_size};
    vertices[2].position = (sfVector2f){p->position.x
        + half_size, p->position.y + half_size};
    vertices[3].position = (sfVector2f){p->position.x
        - half_size, p->position.y + half_size};
    for (int j = 0; j < 4; j++) {
        vertices[j].color = p->color;
        vertices[j].texCoords = (sfVector2f){0, 0};
        sfVertexArray_append(wolf->particle_system.vertex_array, vertices[j]);
    }
    return 0;
}

void render_particle_system(wolf_t *wolf)
{
    if (wolf->particle_system.active_count == 0)
        return;
    sfVertexArray_clear(wolf->particle_system.vertex_array);
    for (int i = 0; i < MAX_PARTICLES; i++) {
        if (loop_render_particle_sys(wolf, i) == 2)
            continue;
    }
    sfRenderWindow_drawVertexArray(wolf->window,
        wolf->particle_system.vertex_array,
            &wolf->particle_system.render_states);
}

void emit_muzzle_flash_particles(wolf_t *wolf)
{
    sfVector2u window_size = sfRenderWindow_getSize(wolf->window);
    sfVector2f gun_pos = {window_size.x * 0.605f, window_size.y * 0.67f};
    particle_t *particle = NULL;
    sfVector2f velocity = {0};
    float life = 0;

    for (int i = 0; i < 8; i++) {
        particle = get_free_particle(&wolf->particle_system);
        if (!particle)
            break;
        velocity = (sfVector2f){
            ((float)(rand() % 60) - 30.0f) * 8,
            -((float)(rand() % 40) + 20.0f) * 8
        };
        life = 0.3f + ((float)(rand() % 20) / 100.0f);
        init_particle(particle, gun_pos, velocity, life);
    }
}
