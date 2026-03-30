#include "main.h"

int Ingresa(t_productos *vec_productos)

{
    int pos = -1, contador =0;
    char codigo[COL] = {0}, descrip[32];
    float prec;

    printf ("\n\nComencemos con el ingreso de la carga de productos.");

    while (contador < TAM && (strcmpi(codigo, "FIN") != 0))
    {
        do
        {
            printf("\n\nIngresa el codigo del producto (5 caracteres, o FIN para terminar) : ");
            Cod (codigo, COL);
            if (strcmpi(codigo, "FIN") != 0)
                {
                    pos = Repetido(codigo, vec_productos, contador);
                    if (pos != -1)
                        printf("\n\nEl codigo ya fue ingresado con anterioridad, intenta nuevamente.");
                    else
                        {
                            do
                            {
                                printf("\n\nIngrese el precio del producto %s : ", codigo);
                                fflush(stdin);
                                scanf("%f", &prec);
                                if (prec <= 0)
                                    printf ("\n\nError en el precio ingresado, debe ser mayor a 0, intente nuevamente.");
                            }while (prec <= 0);
                            printf("\n\nIngresa la descripcion del producto %s (max 30 caracteres) : ", codigo);
                            Cod (descrip, 32);

                            strcpy((vec_productos+contador)->codi, codigo);
                            (vec_productos+contador)->precio = prec;
                            strcpy((vec_productos+contador)->descripcion, descrip);

                            contador++;
                        }

                }
        }while (pos != -1 && (strcmpi(codigo, "FIN") != 0));
    }
    return contador;
}
