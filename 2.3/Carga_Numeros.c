#include "main.h"

int Carga_Numeros (int minimo, int maximo)

{
    int num;
    do
    {
        fflush(stdin);
        scanf("%d", &num);
        if (num < minimo || num > maximo)
            printf("\n\nError en el dato ingresado, intente nuevamente : ");
    }while(num < minimo || num > maximo);

    return num;
}
