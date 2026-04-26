#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM 60

typedef struct
{
    int dni;
    char ayn[21];
    int pagado;
}t_inscriptos;

typedef struct
{
    int dni_interesado;
    char ayn_interesado[21];
    int telefono;
}t_interesados;

FILE * Archivos(char *path, char *modo);
int Carga_inscriptos(FILE *arch, t_inscriptos *inscriptos);
int Ingreso_dni(t_inscriptos *inscriptos, int cant, FILE * arch1);
int Buscar(t_inscriptos *inscriptos, int cant, int pedir_dni);
int Elegir();
void nom_ape(char *nombre);

#endif // FUNCIONES_H_INCLUDED
