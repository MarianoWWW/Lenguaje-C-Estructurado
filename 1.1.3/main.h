#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM 15
#define EMP 5
#define FACTOR_CORRECCION 1001

void IngresaCodigos(int *pt_vec_cod_prod);
int Limites(int a, int b, int c);
int Existe(const int *pt_vec_cod_prod,const int cod,const int cant);
int Ventas(int *pt_vec_cod_prod, int *pt_vec_cant_prod, int *pt_vec_empleados);
void Mostrar (int *pt_vec_cod_prod, int *pt_vec_cant_prod, int *pt_vec_empleados);




#endif // MAIN_H_INCLUDED
