/*

El gobierno de la nación desea controlar el volumen de facturación de la matriz energética nacional, que
está compuesto por las empresas que brindan servicios de Luz, Agua y Gas. Existen a lo sumo 10 empresas y
por cada una se debe ingresar:
• Código de la empresa (número entero entre 1000 y 5000)
• Tipo de servicio (caracter L, A o G (correspondiente a Luz, Agua y Gas respectivamente))
La carga finaliza con un código de empresa igual a 0.
Luego se ingresa el detalle de la facturación con los siguientes datos:
• Código de empresa
• Mes
• Importe facturado
No todas empresas facturaron todos los meses y puede existir más de una factura por empresa/mes.
La carga de facturación finaliza con un mes igual a -1.
1. Mostrar la matriz energética con el siguiente formato respetando los títulos
Empresa\Mes 1 2 3 ... 12
xxxx xxx.xx xxx.xx xxx.xx ... xxx.xx
xxxx xxx.xx xxx.xx xxx.xx ... xxx.xx
xxxx xxx.xx xxx.xx xxx.xx xxx.xx ...
...
Guía Práctica – V1.0 4 / 5
2. Indicar el/los trimestres de mayor facturación, indicando el número de trimestre y el monto
3. Mostrar en forma ordenada de mayor a menor el importe total facturado por tipo de servicio. Mostrando un
listado con Tipo de empresa y total facturado.
4. Mostrar el código y tipo de servicio de aquellas empresas que no hayan facturado en 2 o más meses

*/
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 10
#define COL 12

#include "carga.h"
#include "limite.h"
#include "existe.h"
#include "mostrar.h"
#include "facturacion.h"

#endif // MAIN_H_INCLUDED
