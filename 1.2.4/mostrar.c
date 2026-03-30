#include "main.h"

void Mostrar (char Matriz[][COL], float *pt_vec_precio, int *pt_vec_cant_unidades_vendidas, int cantidad)
{
    system("cls");
    char aux_cod [COL];
    int i, min;
    float aux_precio, total = 0;

    for (i = 0 ; i < cantidad ; i++)
    {
        total = total + ((*(pt_vec_precio+i) )*((float)*(pt_vec_cant_unidades_vendidas+i)));
    }
    printf("\n\nRecaudacion total del dia : %.2f", total);

    min = *pt_vec_cant_unidades_vendidas;
    for (i = 1 ; i < cantidad ; i++)
    {
        if (*(pt_vec_cant_unidades_vendidas+i) < min)
            min = *(pt_vec_cant_unidades_vendidas+i);
    }
    printf("\n\nProducto/s con menos ventas : ");
    for (i = 0 ; i < cantidad ; i++)
    {
        if(min == *(pt_vec_cant_unidades_vendidas+i))
            printf ("%s ", Matriz[i]);
    }
    for (i = 0 ; i < cantidad ; i++)
    {
        if (strcmp(Matriz[i], Matriz[i+1]) <0)
        {
            strcpy(aux_cod, Matriz[i]);
            strcpy(Matriz[i], Matriz[i+1]);
            strcpy(Matriz[i+1], aux_cod);
            aux_precio = *(pt_vec_precio+i);
            *(pt_vec_precio+i) = *(pt_vec_precio+i+1);
            *(pt_vec_precio+i+1) = aux_precio;
        }
    }
    printf("\n\n Codigo\tPrecio");
    for (i = 0 ; i < cantidad ; i++)
    {
        printf ("\n%s\t%.2f", Matriz[i], *(pt_vec_precio+i));
    }

}
