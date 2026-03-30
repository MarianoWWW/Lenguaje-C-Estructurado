#include "main.h"

int Limite (int a, int b, int c)
{
    int cod;
    do
    {
        printf("\nIngrese el dato : ");
        fflush(stdin);
        scanf("%d", &cod);
        if ((cod < a || cod > b) && cod != c)
            printf ("\nError en el dato ingresado. Intente nuevamente.");
    }while ((cod < a || cod > b) && cod != c);
    return cod;
}
