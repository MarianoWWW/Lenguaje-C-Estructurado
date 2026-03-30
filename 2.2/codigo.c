#include "main.h"

int Code (int a, int b)

{
    int cod;
    do
        {
        fflush(stdin);
        scanf("%d", &cod);
        if (cod < a || cod > b)
            printf("\n\nError en el codigo ingresado, debe tener 3 cifras, intente nuevamente : ");
        }while (cod <a|| cod > b);
    return cod;
}
