#include "main.h"

int Existe(char Matriz[][COL], char vec_codigo[COL], int cant)
{
    int i = 0, repetido = -1;
    while (i < cant && repetido == -1)
    {
        if (strcmpi(Matriz[i], vec_codigo) == 0)
            repetido =i;
        else
            i++;
    }
    return repetido;
}
