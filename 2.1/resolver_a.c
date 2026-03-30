#include "main.h"

void Resolver(t_productos *vec_productos,char Matriz_codigo[][COL],int *vec_cantidad_pedida,int cant)

{
    for (int i = 0 ; i < cant ; i++)
    {
        if (strcmp((vec_productos+i)->codi, Matriz_codigo[i]) == 0)
        {
            (vec_productos+i)->cant_unidades_vendidas = *(vec_cantidad_pedida+i);
            (vec_productos+i)->importe_total_vendido = ((vec_productos+i)->precio) * (*(vec_cantidad_pedida+i));
        }
    }
    Mostrar(vec_productos, cant);
}
