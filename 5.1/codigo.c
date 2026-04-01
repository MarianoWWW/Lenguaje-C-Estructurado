#include "main.h"

int Codigo(int mini)
{
    int cod;
    do
        {
            printf("\n\nIngrese el codigo del producto que desea modificar (cero para salir) : ");
            fflush(stdin);
            scanf("%d", &cod);
            if (cod < mini)
                 printf("\n\nError en el codigo ingresado, no puede ser negativo, intente nuevamente.");
        }while (cod < mini);
        return cod;
}

float Precio()
{
    float prec;
    do
        {
        printf("\n\nIngrese el nuevo precio : ");
        fflush(stdin);
        scanf("%f", &prec);
        if (prec <= 0)
            printf("\n\nError en el precio, no puede ser negativo o cero. Intente nuevamente.");
        }while (prec <= 0);
    return prec;
}
