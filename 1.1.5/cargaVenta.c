#include "main.h"

void CargaVentas (int *pt_vec_cod_libro, int *pt_contador, int *pt_cod, int *pt_repetido, int Matriz[][COL])

{
    int cant, i, igual, sucursal, vec_sucursales[COL] = {10, 20, 30, 40, 50, 60, 70};
    int *pt_vec_sucursales;

    pt_vec_sucursales = vec_sucursales;

    system("cls");
    printf("\n\nAhora hay que ingresar las ventas realizadas.");

    do
    {
        Valida(pt_cod, 1000, 9999, 0);
        Existe(pt_vec_cod_libro, pt_cod, pt_repetido, pt_contador);
        if (*pt_repetido != -1 && *pt_cod != 0)
        {
             igual = -1;
             i = 0;
             printf("\nIngrese el codigo de la sucursal (10, 20, 30, 40, 50, 60, 70) : ");
             do
             {
                 fflush(stdin);
                 scanf("%d", &sucursal);
                 while (i < COL && igual == -1)
                 {
                     if (*(pt_vec_sucursales + i) == sucursal)
                     {
                         igual = i;
                         printf("\nIngrese la cantidad vendida : ");
                         do
                         {
                            fflush(stdin);
                            scanf("%d", &cant);
                            if (cant <=0)
                                printf("\nError en la cantidad ingresada. Intente nuevamente : ");
                         }while (cant <=0);
                         Matriz [*pt_repetido][i] = Matriz [*pt_repetido][i] + cant;
                     }
                     else
                        i++;
                 }
                 if (igual == -1 && i == COL)
                 {
                    printf("\nEsa sucursal no existe, intente nuevamente.");
                    i = 0;
                 }
             }while (igual == -1);

        }
        else
        {
            printf("\nError, ese codigo de libro no existe. Intente nuevamente.");
        }


    }while (*pt_cod != 0);
}
