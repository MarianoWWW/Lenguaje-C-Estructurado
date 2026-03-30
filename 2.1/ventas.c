#include "main.h"

int Ventas(char Matriz_codigo[][COL],int *vec_cantidad_pedida,t_productos *vec_productos, int cant)
{
    int pedido = -1, pos, cantidad = 0;
    char codigo[COL] = {0};

    system("cls");
    printf("\n\nAhora vamos a ingresar las ventas del mes.");
    while (pedido != 0)
    {
        do
        {
            printf("\n\nIngresa el codigo del producto (5 caracteres maximo) : ");
            Cod (codigo, COL);
            pos = Repetido(codigo, vec_productos, cant);
                    if (pos == -1)
                        printf("\n\nEl codigo no existe");
        }while (pos == -1);
        do
        {
            printf("\n\nIngrese la cantidad pedida del articulo %s (cero para salir) : ", codigo);
            fflush(stdin);
            scanf("%d", &pedido);
            if (pedido < 0 )
                printf("\n\nError, no puede ser una cantidad negativa, intente nuevamente.");
        }while (pedido < 0 );

        if (pedido != 0)
        {
            strcpy(Matriz_codigo[pos], codigo);
            *(vec_cantidad_pedida+pos) = pedido;
            cantidad++;
        }



    }








    return cantidad;
}
