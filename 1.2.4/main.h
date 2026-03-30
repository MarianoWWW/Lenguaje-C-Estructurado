/*

Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad
exacta de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y
la carga de los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del
día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas terminando con
una cantidad igual a 0. Se solicita:
c. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
d. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de
producto

*/


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define COL 5

#include "carga.h"
#include "codigo.h"
#include "existe.h"
#include "ventas.h"
#include "enter.h"
#include "mostrar.h"

#endif // MAIN_H_INCLUDED
