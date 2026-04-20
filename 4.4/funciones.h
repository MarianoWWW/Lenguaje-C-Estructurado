/*

4.4 La empresa de colectivos línea 166 desea saber cuánto debe cobrar en un mes determinado según los viajes
realizados y registrados en el sistema mediante la tarjeta SUBE para ello dispone de un archivo de viajes
los viajes del mes que está ordenado por número de Interno (colectivo) que contiene la siguiente
información:
• Número de Interno (entero)
• Número tarjeta SUBE (entero)
• Código de Tarifa (texto de 10 caracteres máximo)
• Día (entero)
• Hora (entero)
Se dispone de un segundo archivo llamado tarifas.dat que contiene información de las tarifas por cada mes con
la siguiente estructura:
• Mes (entero)
• Código de Tarifa (texto de 10 caracteres máximo)
• Precio (float)
Se sabe que como máximo se manejan 8 tarifas distintas en cada mes.
Se solicita:
a.
b.
c.
d.
e.
Ingresar por teclado el mes a procesar y recuperar las tarifas correspondientes
Mostrar el importe total a cobrar por la empresa
Generar un archivo que contenga la cantidad de viajes y la recaudación de cada interno en el mes.
Informar el interno que realizó menos cantidad de viajes
Por cada interno mostrar cuantos viajes se realizaron por cada tipo de tarifa ordenado por cantidad de
viajes en forma descendente.
Funciones obligatorias:
• CargaTarifas: que levanta a un vector en memoria las tarifas del mes ingresado por teclado.
• OrdenarViajes: para ordenar los viajes según lo pedido en el punto e.
• MostrarViajes: para mostrar en forma de listado los viajes ordenados del punto e.

*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num_interno;
    int num_sube;
    char codigo_tarifa[10];
    int dia;
    int hora;
}t_viajes;

typedef struct
{
    int mes;
    char cod_tarifa[10];
    float precio;
}t_tarifas;

typedef struct
{
    int num_interno;
    int cantidad_viajes;
    float recaudacion;
}t_cantidad_mes;


int CargaTarifas(t_tarifas *tarifas);
void OrdenarViajes(FILE *arch, int cant);
void MostrarViajes(FILE *arch, FILE *arch1);
#endif // FUNCIONES_H_INCLUDED
