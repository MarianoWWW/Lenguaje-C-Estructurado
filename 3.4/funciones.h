#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[50];
}t_productos;

void Mostrar(char path[]);
void Porcentaje();

#endif // FUNCIONES_H_INCLUDED
