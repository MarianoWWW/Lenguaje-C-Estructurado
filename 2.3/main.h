/*

Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a.
Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c.
Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e.
Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.

*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 80
#define BAJO 0
#define ALTO 10

typedef struct
{
    int nota1;
    int nota2;
}t_notas;

typedef struct
{
    int dni;
    char vec_Ape_Nom[TAM+1];
    t_notas notas;
    float promedio;
}t_alumno;

#include "ingreso.h"
#include "Carga_Numeros.h"
#include "resultado.h"
#include "informe_promo.h"

#endif // MAIN_H_INCLUDED
