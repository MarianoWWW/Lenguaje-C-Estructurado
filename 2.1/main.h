/*

Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a.
Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION         CANTIDAD UNIDADES        IMPORTE TOTAL
                           VENDIDAS                VENDIDO
  XXXXXXX                  XXXX                $XXXXX,XX

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define COL 7

typedef struct
{
    char codi[COL];
    float precio;
    char descripcion[32];
    int cant_unidades_vendidas;
    float importe_total_vendido;
}t_productos;

#include "ingresa.h"
#include "codigo.h"
#include "enter.h"
#include "repetido.h"
#include "ventas.h"
#include "mostrar.h"
#include "resolver_a.h"

#endif // MAIN_H_INCLUDED
