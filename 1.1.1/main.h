#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void IngresaCodigos (int *vec, int *pt_contador_ingreso, int *pt_codigo, int *pt_salida);
void Mostrar (const int *vec,const int *vec_cantidad);
void CargaProductos (int *pt_vec_prod, int *pt_vec_cantidad, int *pt_codigo, int *pt_contador_ingreso, int *pt_salida);
void Rango (int *pt_codigo, int *pt_salida);
int BuscarIgual (const int *vec,const int *pt_contador_ingreso,const int *pt_codigo);

#endif // MAIN_H_INCLUDED
