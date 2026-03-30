#include "main.h"

void Facturacion(int *pt_vec_cod_empresa, float Matriz[][COL], int cantidad)
{
    int cod, mes, repetido;
    float importe;
    system("cls");

    printf("\nFacturacion, comenzando por el codigo de la empresa (-1 para terminar).");
    do
    {
        cod = Limite (1000, 5000, -1);
        if (cod != -1)
        {
            repetido = Existe(pt_vec_cod_empresa, cod, cantidad);
            if (repetido != -1)
            {
                printf("\nAhora vamos con el mes.");
                mes = Limite (1, 12, 12);
                do
                {
                    printf("\nIngrese el importe facturado : ");
                    fflush(stdin);
                    scanf("%f", &importe);
                    if (importe <=0)
                        printf("\nError en el importe, intente nuevamente.");
                }while (importe <=0);

             Matriz [repetido][mes-1]  =  Matriz [repetido][mes-1] + importe;
             printf("\nIngrese el codigo de la empresa (-1 para terminar).");
            }
            else
            {
                printf("\n\nError, ese codigo no existe, intente nuevamente.");
            }
        }
    }while (cod != -1);
}
