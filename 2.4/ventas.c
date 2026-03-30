#include "main.h"

int VENTAS(t_cliente *cliente, t_venta *venta, int contador)

{
    int i = 0, flag = -1, cli, dup, num_vende, cant = 0;
    double impo;

    system("cls");
    printf("\n\nAhora vamos a ingresar las ventas realizadas.");
    do
    {
        do
            {
                printf("\n\nIngrese el numero de cliente (4 digitos, clientes no correlativos, o 999 para terminar) : ");

                cli = Limite(MINIMO, MAXIMO);
                dup = Duplicado(cliente, cli, contador);
                if (dup == -1)
                {
                    printf("\n\nNumero de cliente inexistente en la base de datos, intente nuevamente.");
                }
            }while (dup == -1 && cli != 999);


             if (cli != 999)
             {
                 do
                 {
                     printf("\n\nIngrese el importe $: ");
                     fflush(stdin);
                     scanf("%lf", &impo);
                     if (impo <= 0)
                         printf("\n\nError, el importe no puede ser negativo o cero, intente nuevamente.");
                 }while (impo <= 0);

                 printf("\n\nIngrese el numero del vendedor (1 a 10) : ");
                 num_vende = Limite(1, 10);

                 while (i < cant && flag == -1)
                 {
                     if (((venta+i)->cod == cli) && ((venta+i)->num_vendedor == num_vende))
                     {
                         (venta+i)->importe = ((venta+i)->importe) + impo;
                         flag = 1;
                     }
                     else
                     {
                         i++;
                     }
                 }
                 if (flag == -1)
                 {
                    (venta+cant)->cod = cli;
                    (venta+cant)->importe = impo;
                    (venta+cant)->num_vendedor = num_vende;
                    cant++;
                 }
                 else
                 {
                     flag = -1;
                 }
                 i = 0;
             }

    }while (cli != 999);

    return cant;
}
