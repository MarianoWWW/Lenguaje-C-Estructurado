#include "main.h"

void Mostrar(t_productos *vec_productos, int cant)

{
    system("cls");

    printf("\n\n\tDESCRIPCION\t\tCANTIDAD UNIDADES\tIMPORTE TOTAL");
    printf("\n\t\t\t\t\tVENDIDAS\t   VENDIDO");

    for (int i = 0 ; i < cant ; i++)
    {
        if (strcmp((vec_productos+i)->codi, "\0") != 0)
        {
            printf("\n%-30s\t\t%d\t\t  $%.2f", (vec_productos+i)->descripcion,
                   (vec_productos+i)->cant_unidades_vendidas,
                   (vec_productos+i)->importe_total_vendido);
        }
    }
}
