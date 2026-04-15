#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define PATH "empleados.dat"

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

typedef struct
{
    int legajo;
    char apellido[16];
    char nombre[31];
    t_fecha fecha;
    int categoria;
}t_empleados;

int bisiesto(int *anio);
int cant_dias_mes(int *m, int *a);
int fecha_valida(t_fecha *fecha_actual);

#endif // FUNCIONES_H_INCLUDED
