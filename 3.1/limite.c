#include "main.h"

int Limite (int a, int b, int c)

{
    int dato;

    do
    {
        printf("\n\nIngrese el dato : ");
        fflush(stdin);
        scanf("%d", &dato);
        if ((dato < a || dato > b) && dato != c)
            printf("\nError en el dato ingresado, intente nuevamente.");
    }while ((dato < a || dato > b) && dato != c);

    return dato;
}
