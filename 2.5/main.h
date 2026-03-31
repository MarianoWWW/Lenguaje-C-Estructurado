/*

De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)
Se solicita realizar los siguientes procesos:


a.  Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
anteriormente y llamarla PERSONA.
b.  Mostrar los datos de la Estructura de Datos del punto a.
c.  Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
utilizarla en una nueva Estructurad de Datos llamada PERSONA2.
d. Mostrar los datos de la Estructura de Datos del punto c.
e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
al programa principal (main).
f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
ser hasta 36 materias) y llamarla PERSONA3.
g. Crear una FUNCION que realice el punto f.
h. Mostrar los datos de la Lista creada en el punto f.
i. Crear una FUNCION que realice el punto h.

*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero_legajo;
    char apellido[16];
    char nombre[16];
    float altura;
    char sexo;
    int dia_nacimiento;
    int mes_nacimiento;
    int anio_nacimiento;
} PERSONA;

typedef struct
{
    char apellido[16];
    char nombre[16];

} PERSONA_NyA;

typedef struct
{
    int dia_nacimiento;
    int mes_nacimiento;
    int anio_nacimiento;
} PERSONA_DATOS_NACIMIENTO;


typedef struct
{
    PERSONA_NyA nom_ape;
    PERSONA_DATOS_NACIMIENTO nacimiento;
} PERSONA2;

typedef struct
{
    PERSONA_NyA nom_ape;
    PERSONA_DATOS_NACIMIENTO nacimiento;
    int materias_aprobadas[36];
} PERSONA3;

#include "puntoB.h"
#include "puntoD.h"
#include "puntoE.h"
#include "puntoG.h"
#include "puntoH_e_I.h"

#endif // MAIN_H_INCLUDED
