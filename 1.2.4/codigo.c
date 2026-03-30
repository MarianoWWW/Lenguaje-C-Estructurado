#include "main.h"

void Codigo(char vec_codigo[COL])
{
    do
    {
        printf("\n\nIngrese el codigo del producto, 3 caracteres debe tener : ");
        fflush(stdin);
        fgets(vec_codigo, COL, stdin);
        Enter(vec_codigo);
        if (strlen(vec_codigo) < 3 ||strlen(vec_codigo) > 3)
            printf ("\nError en el codigo ingresado, intente nuevamente.");
    }while (strlen(vec_codigo) < 3 ||strlen(vec_codigo) > 3);
}
