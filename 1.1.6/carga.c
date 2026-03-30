#include "main.h"

int CargaEmpresas(int *pt_vec_cod_empresa, char *pt_vec_tipo_servicio)
{
    int contador = 0, cod, repetido;
    char serv;
    printf("\nComencemos cargando los codigos de las Empresas (4 digitos) y su tipo. Cero para salir.");
    do
    {
        cod = Limite (1000, 5000, 0);
        if (cod != 0)
        {
            repetido = Existe(pt_vec_cod_empresa, cod, contador);
            if (repetido == -1)
            {
                do
                {
                     printf("\nIngrese que tipo de servicio es (L, A o G) : ");
                     fflush(stdin);
                     scanf("%c", &serv);
                     serv = toupper(serv);
                     if (serv !='L' && serv !='A' && serv !='G')
                         printf("\nError en el dato de servicio ingresado, intente nuevamente.");
                }while (serv !='L' && serv !='A' && serv !='G');
                *(pt_vec_cod_empresa+contador) = cod;
                *(pt_vec_tipo_servicio+contador) = serv;
                contador ++;
            }
            else
            {
                 printf("\nEse codigo de empresa ya existe, intente nuevamente.");
            }
        }
    }while (cod !=0);
return contador;
}
