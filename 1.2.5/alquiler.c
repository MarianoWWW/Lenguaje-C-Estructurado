#include "main.h"

int Alquiler(char Matriz[][COL], int *vec_cant_dias, float *vec_alquiler_precio_diario)
{
    char patente[COL+1];
    int i = 0, j = 0, cantidad = 0, repetido = -1, dias;
    float precio;

    printf("\n\nAhora vayamos a procesar los alquileres del dia.");

    do
    {
        repetido = -1;
        i = 0;
        j = 0;
        printf("\n\nIngrese la patente del auto (Van del AAA100 al AAA129) (FINDIA para salir) : ");
        fflush(stdin);
        fgets(patente, COL+1, stdin);

        while (patente[j] !='\0')
        {
            if (patente[j] =='\n')
                (patente[j] ='\0');
            else
                j++;
        }


        if (strcmpi(patente, "FINDIA") != 0)
        {
            if (strlen(patente) > 6)
                printf("\n\nError en la patente, hay caracteres de mas, intente nuevamente.");
            else
            {
                while (i < TAM && repetido == -1)
                {
                    if (strcmpi(patente, Matriz[i]) == 0)
                        repetido = i;
                        else
                            i++;
                }
                if (repetido == -1)
                    printf ("\n\nEsa patente no esta en la base de datos, intente nuevamente.");
                else
                {
                    do
                    {
                        printf("\n\nIngrese la cantidad de dias de alquiler : ");
                        fflush(stdin);
                        scanf("%d", &dias);
                        if (dias <= 0)
                            printf ("\n\nError en la cantidad de dias, intente nuevamente.");
                    }while (dias <= 0);

                    do
                    {
                        printf("\n\nIngrese el precio diario de alquiler en dolares : ");
                        fflush(stdin);
                        scanf("%f", &precio);
                        if (precio <= 0)
                            printf ("\n\nError en el precio, intente nuevamente.");
                    }while (precio <= 0);
                    if (*(vec_cant_dias+repetido) == 0)
                        cantidad++;
                    *(vec_cant_dias+repetido) = dias;
                    *(vec_alquiler_precio_diario+repetido) = precio;
                }
            }

        }
    }while (strcmpi(patente, "FINDIA") != 0);

    return cantidad;
}
