/*

5.3 Tomar el archivo de empleados del punto 5.2 y ordenarlo en forma ascendente por legajo y mostrarlo en
forma de listado.

*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

typedef struct
{
    int legajo;
    char apellido[15];
    char nombre[30];
    t_fecha fecha;
    int categoria;
}t_empleados;

#endif // FUNCIONES_H_INCLUDED
