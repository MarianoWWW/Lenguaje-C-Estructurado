#include "main.h"

void Valida(int *pt_cod, int a, int b, int c)
{
    do
    {
        printf("\nIngrese el codigo : ");
        fflush(stdin);
        scanf ("%d", pt_cod);
        if ((*pt_cod < a || *pt_cod > b) && *pt_cod != c)
            printf ("\n\nError en el codigo ingresado. Intente nuevamente.");
    }while ((*pt_cod < a || *pt_cod > b) && *pt_cod != c);
}
