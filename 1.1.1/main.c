/*
1.1.1 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa mediante
la función IngresaCódigos.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
 La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include "main.h"

int main()
{
    int codigo, salida = 1000, contador_ingreso = 0, vec_prod[10], vec_cantidad[10] = {0};
    int *pt_codigo, *pt_salida, *pt_contador_ingreso, *pt_vec_prod, *pt_vec_cantidad;

    pt_codigo = & codigo;
    pt_salida = & salida;
    pt_contador_ingreso = & contador_ingreso;
    pt_vec_prod = vec_prod;
    pt_vec_cantidad = vec_cantidad;

    IngresaCodigos (pt_vec_prod, pt_contador_ingreso, pt_codigo, pt_salida);

    CargaProductos (pt_vec_prod, pt_vec_cantidad, pt_codigo, pt_contador_ingreso, pt_salida);

    Mostrar (pt_vec_prod, pt_vec_cantidad);

    printf ("\n\n");
    system ("pause");


    return 0;
}

void IngresaCodigos (int *vec, int *pt_contador_ingreso, int *pt_codigo, int *pt_salida)
{

    printf("\n\n\n");
    for (int a=0 ; a < 10 ; a++)
    {
        printf ("\n Ingrese el codigo del producto %d : ", *(pt_contador_ingreso)+1);
        Rango (pt_codigo, pt_salida);
        while (BuscarIgual(vec, pt_contador_ingreso, pt_codigo) != -1)
        {
            printf("\n\n\nEse codigo ya existe, intente nuevamente. ");
            Rango (pt_codigo, pt_salida);
        }
        *(vec+a) = *pt_codigo;
        *pt_contador_ingreso = *pt_contador_ingreso +1;
    }
}

void CargaProductos (int *pt_vec_prod, int *pt_vec_cantidad, int *pt_codigo, int *pt_contador_ingreso, int *pt_salida)
{
    int pos, cantidad;
    int *pt_cantidad;

    pt_cantidad = & cantidad;
    *pt_salida = 0;
    system("cls");
    printf("Ahora vayamos con la carga de pedidos.");
    while (*pt_codigo)
    {
        printf("\n\n\nIngrese el codigo del producto para el pedido (cero para salir) : ");
        Rango (pt_codigo, pt_salida);
        if (*pt_codigo)
        {
            if ((pos = BuscarIgual(pt_vec_prod, pt_contador_ingreso, pt_codigo)) != -1)
            {
                printf("\nIngrese la cantidad que necesita del producto %d : ", *pt_codigo);
                do
                {
                    fflush(stdin);
                    scanf ("%d", pt_cantidad);
                    if (*(pt_cantidad) < 0 )
                    {
                        printf ("Error, es una cantidad negativa, intente nuevamente : ");
                    }
                }while (*pt_cantidad < 0 );
            *(pt_vec_cantidad + pos) = (*(pt_vec_cantidad + pos)) + *pt_cantidad;
            }
            else
                {
                printf("\nError, el producto no existe, intente nuevamente.");
                }
        }
    }

}

void Rango (int *pt_codigo, int *pt_salida)
{
        do {
        fflush(stdin);
        scanf ("%d", pt_codigo);
        if ((*pt_codigo < 1000 || *pt_codigo > 9999) && *pt_codigo != *pt_salida)
            printf ("Error, en el codigo, intente nuevamente : ");
        }while ((*pt_codigo < 1000 || *pt_codigo > 9999) && *pt_codigo != *pt_salida);
}

int BuscarIgual (const int *vec,const int *pt_contador_ingreso,const int *pt_codigo)
{
    for (int a = 0 ; a < (*pt_contador_ingreso) ; a++)
    {
        if ( *(vec + a) == *(pt_codigo) )
        {
            return a;
        }
    }
    return -1;
}


void Mostrar (const int *vec,const int *vec_cant)
{
        int a, max, min;
        int *pt_max, *pt_min;

        pt_max = & max;
        pt_min = & min;

        system ("cls");

        printf ("Listado de codigo y cantidad de unidades solicitadas de cada producto : ");
        for (a = 0 ; a < 10 ; a++)
        {
            printf ("\n%d\t\t\t%d", *(vec + a), *(vec_cant + a) );
        }

        *pt_max = *(vec_cant);
        *pt_min = *(vec_cant);
        for (a = 1 ; a < 10 ; a++)
        {
            if (*(vec_cant + a) > *pt_max)
                *pt_max = *(vec_cant + a);
            if (*(vec_cant + a) < *pt_min)
                *pt_min = *(vec_cant + a);

        }
        printf ("\n\n\nMayor cantidad solicitada es de %d, de el / los : ", *pt_max);
        for (a = 0 ; a < 10 ; a++)
        {
            if (*(vec_cant + a) == *pt_max)
            printf (" %d\t", *(vec + a) );
        }
        printf ("\n\nMenor cantidad solicitada es de %d, de el / los : ", *pt_min);
        for (a = 0 ; a < 10 ; a++)
        {
            if (*(vec_cant + a) == *pt_min)
            printf (" %d\t", *(vec + a) );
        }
}
