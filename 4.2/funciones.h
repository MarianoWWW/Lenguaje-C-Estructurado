/*

4.2 Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a.
Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c.
Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e.
Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
con stock menor al punto de pedido.

*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRO "productos.dat"

typedef struct
{
    char sucursal[16];
    int codigo_producto;
    int cantidad;
}t_ventas;

typedef struct
{
    int cod_prod;
    char descripcion[21];
    float precio;
    int stock;
    int punto_de_pedido;
    int cantidad_para_pedido;
}t_productos;

typedef struct
{
    int cod_producto;
    int cant;
}t_pedidos;

int Carga(t_productos *productos);
void Procesar_ventas(t_productos *productos,int cant);

#endif // FUNCIONES_H_INCLUDED
