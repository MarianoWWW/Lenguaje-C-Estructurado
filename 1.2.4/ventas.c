#include "main.h"

void Ventas(char Matriz[][COL], int *pt_vec_cant_unidades_vendidas, int cant)

{
    char vec_codigo[COL];
    int repetido, unidad = 1;

    system("cls");
    printf("\n\nAhora vamos a ingresar las ventas del dia.");

    do
    {
        Codigo(vec_codigo);
        repetido = Existe(Matriz, vec_codigo, cant);

        if (repetido != -1)
        {
            do
            {
                printf ("\n\nIngrese la cantidad de unidades vendidas de %s (0 para salir) : ", vec_codigo);
                fflush(stdin);
                scanf("%d", &unidad);
                if (unidad < 0)
                    printf("\n\nNo puede ser una cantidad negativa, intente nuevamente.");
            }while (unidad < 0);
            if (unidad != 0)
            *(pt_vec_cant_unidades_vendidas+repetido) = *(pt_vec_cant_unidades_vendidas+repetido) + unidad;
        }
        else
            printf ("\n\nEse codigo no existe en la Base de Datos, intente nuevamente.");
    }while (unidad != 0);
}
