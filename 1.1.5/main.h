/*

La librería Libreto S.A. desea analizar las ventas realizadas por cada una de sus sucursales.
Existen 7 sucursales codificadas con los números 10, 20, 30, 40, 50, 60 y 70.
No se sabe la cantidad de libros que vende la empresa pero sí se sabe que no son más de 100. Se debe
realizar una carga inicial solicitando al usuario que ingrese por teclado los códigos de libros disponibles (los códigos
son de 4 dígitos).
Luego se ingresan por teclado las ventas realizadas, ingresando por cada venta los siguientes datos:
• Código de sucursal (entero 10, 20, 30, 40, 50, 60 o 70)
• Código de libro (entero de 4 cifras)
• Cantidad Vendida (entero mayor a 0)
Puede ingresarse más de una venta por libro/sucursal. Si un libro no se vendió en la sucursal no se informa.
La carga de datos finaliza al ingresar un código de libro igual a 0.
1. Cargar los libros disponibles en la empresa mediante la función CargaLibros, esta función debe asegurar
que se ingresen código de 4 cifras y no debe permitir ingresar códigos repetidos.
2. Mostrar el detalle de cantidad de libros vendidas en cada sucursal con el siguiente formato:
Libro/Sucursal 10 20 30 40 50 60 70
xxxx xx xx xx xx xx xx xx
xxxx xx xx xx xx xx xx xx
xxxx xx xx xx xx xx xx xx
…
xxxx xx xx xx xx xx xx xx
3. Mostrar la o las sucursales que vendieron mayor cantidad de libros
4. Mostrar aquellos libros que NO fueron vendidos en ninguna sucursal

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define COL 7
#define AJUSTE 10

#include "carga.h"
#include "valida.h"
#include "existe.h"
#include "mostrar.h"
#include "cargaVenta.h"

#endif // MAIN_H_INCLUDED
