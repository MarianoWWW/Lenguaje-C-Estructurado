#include "main.h"

int Limite (int a, int b)

{
    int dato;

    do
    {
        fflush(stdin);
        scanf("%d", &dato);
        if (dato < a || dato > b)
            printf("\n\nError en el dato ingresado, intente nuevamente : ");
    }while (dato < a || dato > b);

    return dato;
}
