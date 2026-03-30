/*

Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a.
Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c.
Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e.
Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME. ++999999999999999999999-63+++++++

*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define TAM 5
#define MIN 100
#define MAX 999


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    double precio;
    int stock;
}t_medicamento;

#include "busqueda_medi.h"
#include "informe.h"
#include "ingreso.h"
#include "repetido.h"
#include "codigo.h"



#endif // MAIN_H_INCLUDED
