/*

3.7 Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
El mes tiene 30 días y se sabe que como máximo cada aerolínea realiza 5 vuelos diarios. Luego se dispone de un
segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes para la aerolínea
con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizar los viajes. Al finalizar, grabar la información en un nuevo
archivo llamado Aero1.dat. Agregar la opción para exportar el archivo Aero1 a formato csv.

*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char codigo[10];
    int dia;
    int numero_vuelo;
    float costo_pasaje;
    int pasajeros;
}t_vuelos;

typedef struct
{
    int dni;
    int num_vuelo;
}t_pasajeros;

void Agregar_pasajeros(t_vuelos *vuelo,FILE * arch1, int cantidad);
void Guardar(t_vuelos *vuelo, int cantidad);
FILE* abrir_archivos(char *nombre, char *modo);
t_vuelos* crear_vuelos(int cap);

#endif // FUNCIONES_H_INCLUDED
