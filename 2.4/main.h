/*

 Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa con la
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a.
Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c.
Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada
cliente, informando:
CODIGO DE CLIENTE         NOMBRE Y APELLIDO             TOTAL FACTURADO
        X                 XXXXX    XXXXXXX               $ XXXXXXXXX.XX


*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define MINIMO 999
#define MAXIMO 9999

typedef struct
{
    int codigo;
    char NyA[51];
}t_cliente;

typedef struct
{
    int cod;
    double importe;
    int num_vendedor;
}t_venta;

#include "carga.h"
#include "entrar.h"
#include "limite.h"
#include "duplicado.h"
#include "ventas.h"
#include "informe.h"

#endif // MAIN_H_INCLUDED
