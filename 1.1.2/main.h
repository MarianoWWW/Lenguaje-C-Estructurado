#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int IngresarDatos (int *pt_vec_dni, int *pt_vec_nota);
bool BuscarDuplicados (int *pt_vec_dni, int dni, int cant);
void Mostrar (int *pt_vec_dni, int *pt_vec_nota, int cantidad);


#endif // MAIN_H_INCLUDED
