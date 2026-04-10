#ifndef FUNCIONES__H_INCLUDED
#define FUNCIONES__H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num_canal;
    char programa[36];
    float rating;
}t_rating;

typedef struct
{
    int numero_canal;
    float promedio;
}t_promedio;

void Mostrar( FILE *arch1);

#endif // FUNCIONES__H_INCLUDED
