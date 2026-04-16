#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define PATH "productos.dat"
#define TAM 100

typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}t_producto;

#include "carga.h"
#include "modificar.h"
#endif // MAIN_H_INCLUDED
