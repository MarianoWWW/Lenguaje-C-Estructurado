#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "PRECIOS.DAT"
#define TAM 21

typedef struct
{
    int codigo;
    char descripcion[TAM];
    float precio;
}t_producto;

#include "descripcion.h"
#include "codigo.h"
#include "eli_enter.h"

#endif // MAIN_H_INCLUDED
