/*

Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama, identificados por su número
de patente, cargado en la memoria principal en un vector de 30 posiciones. Al comenzar el
procesamiento de los alquileres, se ingresa la fecha y la cotización del dólar de ese día. A continuación,
se ingresan los siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
a. El porcentaje de autos alquilados durante el día.
b. Realizar el informe con el formato siguiente:
ALQUILER DE AUTOS DEL DÍA: DD-MM-AAAA
COTIZACION DEL DÓLAR: $ XX,XX
NRO. DE AUTO DIAS DE ALQUILER PRECIO DEL ALQUILER
EN PESOS
FECHA DE DEVOLUCION
DEL AUTO
Guía Práctica – V1.0 5 / 5
XXXXX XX XXXX,XX XX/XX/XXXX
XXXXX XX XXXX,XX XX/XX/XXXX
TOTAL RECAUDADO X ALQUILER (EN PESOS)
$ XXXXX,
TOTAL RECAUDADO X ALQUILER (EN DÓLARES)
$ XXXXX,XX

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 30
#define COL 7

#include "memoria.h"
#include "alquiler.h"
#include "mostrar.h"


#endif // MAIN_H_INCLUDED
