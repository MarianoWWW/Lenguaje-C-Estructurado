#include "main.h"

int Modificar(t_producto *producto, int cant)

{
    int i, cod, flag = 0;
    float nuevo_precio;
    do
    {
        printf("\n\nIngrese el codigo del producto a modificar (cero para salir) : ");
        scanf("%d", &cod);
        if (cod >= 0)
        {
            if (cod != 0)
            {
                for (i = 0 ; i < cant ; i++)
            {
                if (cod == (producto+i)->codigo)
                {
                    do
                    {
                         printf("\n\nIngrese el nuevo precio $: ");
                         scanf("%f", &nuevo_precio);
                         if (nuevo_precio <= 0)
                            printf("\n\nError, no puede ser un precio negativo o cero, intente nuevamente.");
                    }while (nuevo_precio <= 0);

                    (producto+i)->precio = nuevo_precio;
                    flag = 1;
                    break;
                }
            }
            if (i == cant)
                printf("\n\nError, el codigo elegido no existe en la Base de Datos, intente nuevamente.");
            }
        }
        else
            printf("\n\nError, el codigo no puede ser negativo. Intente nuevamente.");
    }while (cod != 0);
    return flag;
}
