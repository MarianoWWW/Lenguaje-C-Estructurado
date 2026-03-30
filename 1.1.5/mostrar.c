#include "main.h"

void Mostrar (int *pt_vec_cod_libro, int *pt_contador, int Matriz[][COL])
{
    int suma = 0, i, j, max, vec_contador[COL] = {0};
    int *pt_vec_contador;

    pt_vec_contador = vec_contador;
    system("cls");
    if (*pt_contador != 0)
    {
    printf("Libro/Sucursal\t10\t20\t30\t40\t50\t60\t70");
    for (i = 0 ; i < (*pt_contador) ; i++)
    {
        printf ("\n%d\t", *(pt_vec_cod_libro+i));
        for (j = 0 ; j < COL ; j++)
        {
            printf ("\t%d", Matriz[i][j]);
        }
    }
        for (j = 0 ; j < COL ; j++)
            {
            for (i = 0 ; i < (*pt_contador) ; i++)
                {
                   *(pt_vec_contador + j) = *(pt_vec_contador + j) + Matriz[i][j];
                }
            }
        max = *(pt_vec_contador);
        for (i = 1 ; i < COL ; i++)
            {
                if (*(pt_vec_contador + i ) > max)
                        max = *(pt_vec_contador + i );
            }
         printf("\n\nSucursal o sucursales que vendieron mayor cantidad (%d) de libros : ", max);
         for (i = 0 ; i < COL ; i++)
            {
                if (*(pt_vec_contador + i ) == max)
                        printf(" %d ", (i + 1) * AJUSTE);
            }
         printf("\nLibros que no fueron vendidos en ninguna sucursal : ");
         for (i = 0 ; i < (*pt_contador) ; i++)
                {
                    for (j = 0 ; j < COL ; j++)
                    {
                        suma = suma + Matriz[i][j];
                    }
                if (suma == 0)
                {
                    printf(" %d ", *(pt_vec_cod_libro + i));
                }
                else
                {
                    suma = 0;
                }
                }

    }
    else
    {
        printf ("\n\nNO SE INGRESARON DATOS");
    }
}
