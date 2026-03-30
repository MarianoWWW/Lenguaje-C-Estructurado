#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 30

int Ventas (int *vec_cod_prod, float Matriz[][12]);
int Valida (int a, int b, int c);
int Existe (int *pt_vec_cod_prod, int cod);
void Mostrar(int *pt_vec_cod_prod,float Matriz[TAM][12], int contador);

#endif // MAIN_H_INCLUDED
