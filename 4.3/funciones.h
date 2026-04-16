#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "LLAMADAS.dat"

typedef struct
{
    char sector[16];
    int duracion;
    int tipo_de_llamada;
}t_llamada;

typedef struct
{
    float caso_1;
    float caso_2;
    float caso_3;
}t_costos;

typedef struct
{
    char total_sector[16];
    float total_gastado;
}t_gastos;

typedef struct
{
    int duracion_seg;
    int tipo_llamada;
    float costo;
}t_llama_valorizado;

void Logica();
void Mostrar (FILE *arch2);
void Escribir(char sector[16], t_llama_valorizado *val);

#endif // FUNCIONES_H_INCLUDED
