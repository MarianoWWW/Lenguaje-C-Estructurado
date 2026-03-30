#include "main.h"

int CargaDatos(char Matriz [][COL], float *pt_vec_precio)
{
    char vec_codigo[COL];
    int cant = 0, repetido;
    float precio;

    printf ("\n\nPrimero hay que cargar los codigos (3 digitos) y el precio de cada producto (FIN para terminar).");
    do
    {
        Codigo(vec_codigo);
        repetido = Existe(Matriz, vec_codigo, cant);
        if ((strcmpi(vec_codigo, "FIN") != 0))
        {
        if (repetido == -1)
        {
            do
            {
                printf ("\n\nIngrese el precio del producto %s : ", vec_codigo);
                fflush(stdin);
                scanf("%f", &precio);
                if (precio <= 0)
                    printf("\n\nNo puede tener ese precio, intente nuevamente.");
            }while (precio <= 0);
            strcpy(Matriz[cant], vec_codigo);
            *(pt_vec_precio+cant) = precio;
            cant++;
        }
        else
            printf ("\n\nCodigo ya ingresado, intente nuevamente.");
        }
    }while ((strcmpi(vec_codigo, "FIN") != 0) && cant < TAM);

    return cant;
}
