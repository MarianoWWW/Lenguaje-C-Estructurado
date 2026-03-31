/*

 Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a.
b.
c.
Declarar un tipo de dato que contenga la información del alumno.
Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
Leer los datos del archivo, mediante la Función LECTURA.

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 82
#define MINI 0
#define MAXI 10

typedef struct
{
    int nota1;
    int nota2;
}t_notas;


typedef struct
{
    int dni;
    char nom_ape[TAM];
    t_notas notas;
    float nota_promedio;
}t_alumno;

#include "limite.h"
#include "lectura.h"

#endif // MAIN_H_INCLUDED
