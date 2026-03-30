#include "main.h"


void INFORME(t_medicamento *medicamento)

{
    system("cls");
    printf("\n\nTabla con los medicamentos en stock menor a 10 unidades.");
    printf("\n\nCodigo\tStock");

    for (int i = 0 ; i < TAM ; i++)
    {
        if ((medicamento+i)->stock < 10)
        {
            printf("\n%d\t%d", (medicamento+i)->codigo, (medicamento+i)->stock);
        }
    }
    printf("\n\n");
    system("pause");
}
