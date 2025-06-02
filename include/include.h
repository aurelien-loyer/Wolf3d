/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** include
*/

#ifndef INCLUDED_INCLUDE_H
    #define INCLUDED_INCLUDE_H
    #include <stdio.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include <stdbool.h>
    #include <string.h>

    // define
    #define HEIGHT 1080
    #define WIDTH 1920
    #define CHARACTER_MAP "012"
    #define CHARACTER_POSPLAYER 2
    #define TILE_SIZE 64
    #define PI 3.14159265358979323846
    #define FOV 1.0472 // 60° en radians
    #define MAX_IMPACT 50
    #define IMPACT_SIZE 10.0f
    #define ORIGINAL_IMPACT_SIZE 32.0f
    #define MAP_WIDTH 5
    #define MAP_HEIGHT 5
    #define MAX_PARTICLES 50
    #define MUZZLE_PARTICLES 8

    // my include
    #include "struct.h"
    #include "function.h"

#endif
