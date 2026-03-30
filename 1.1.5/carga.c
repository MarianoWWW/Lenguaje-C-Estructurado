#include "main.h"

void CargaLibros (int *pt_vec_cod_libro, int *pt_contador, int *pt_cod, int *pt_repetido)
{
    printf("\n\nComencemos con la carga de los codigos de los libros disponibles (los codigos son de 4 digitos y cero para terminar).");

    do
    {
        Valida(pt_cod, 1000, 9999, 0);
        Existe(pt_vec_cod_libro, pt_cod, pt_repetido, pt_contador);
        if (*pt_repetido == -1 && *pt_cod != 0)
        {
            *(pt_vec_cod_libro + (*pt_contador)) = *pt_cod;
            *pt_contador = (*pt_contador) + 1;
        }
        else
        {
            printf("\nError, ese codigo de libro y fue cargado. Intente nuevamente.");
        }

    }while ((*pt_cod != 0) && *pt_contador < 100);
}
