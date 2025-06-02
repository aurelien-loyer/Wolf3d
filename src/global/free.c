/*
** EPITECH PROJECT, 2025
** G-ING-210-RUN-2-1-wolf3d-theo.futol
** File description:
** free.c
*/

#include "include.h"

void my_free(void *ptr)
{
    if (!ptr)
        return;
    free(ptr);
    ptr = NULL;
}

void free_array(void **ptr)
{
    if (!ptr)
        return;
    for (int i = 0; ptr[i]; i++)
        my_free(ptr[i]);
    my_free(ptr);
}
