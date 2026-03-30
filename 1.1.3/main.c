/*

1.1.3 Se ingresan los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las
ventas realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta
de un mismo vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas de cada producto.
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).

*/



#include "main.h"

int main()
{
    int contador, vec_cod_prod[TAM],vec_cant_prod[TAM] ={0}, vec_empleados[EMP] = {0};
    int * pt_vec_cod_prod, *pt_vec_cant_prod, *pt_vec_empleados;

    pt_vec_cod_prod = vec_cod_prod;
    pt_vec_cant_prod = vec_cant_prod;
    pt_vec_empleados = vec_empleados;

    IngresaCodigos(pt_vec_cod_prod);

    contador = Ventas(pt_vec_cod_prod, pt_vec_cant_prod, pt_vec_empleados);

    if (contador)
        Mostrar (pt_vec_cod_prod, pt_vec_cant_prod, pt_vec_empleados);
    else
        printf ("\n\n\nNo hubieron ventas.");

    printf ("\n\n");
    system("pause");
    return 0;
}

void IngresaCodigos(int *pt_vec_cod_prod)
{
    int repetido, cod, cant = 0;

    printf ("\n\n\nPrimero vamos a ingresar los 15 codigos de productos (tres cifras) : ");
    for (int i = 0 ; i < TAM ; i++)
    {
    do
    {
        cod = Limites(100, 999, 999);
        repetido = Existe(pt_vec_cod_prod, cod, cant);
        if (repetido != -1)
            {
            printf ("\nError, el codigo esta repetido. Intente nuevamente.");
            }
    }while (repetido != -1);

    *(pt_vec_cod_prod + cant) = cod;
    cant++;
    }
}
int Limites(int a, int b, int c)
{
    int cod;
    do
    {
        printf ("\n\nIngrese el codigo : ");
        fflush(stdin);
        scanf("%d", & cod);
        if ((cod < a || cod > b) && cod != c)
            printf ("\nError, el codigo. Intente nuevamente.");
    }while ((cod < a || cod > b) && cod != c);


    return cod;
}

int Existe(const int *pt_vec_cod_prod, const int cod, const int cant)
{
    for (int i = 0 ; i < cant ; i++)
    {
        if (*(pt_vec_cod_prod + i) == cod)
            return i;
    }
    return -1;
}

int Ventas(int *pt_vec_cod_prod, int *pt_vec_cant_prod, int *pt_vec_empleados)
{
    int cod_vendedor, repetido, cod_producto, cant, contador = 0;
    system("cls");
    printf ("Ahora vamos con las ventas del dia.\n\n");
    do
    {
        printf ("\nDel vendedor. (Cero para terminar)");
        cod_vendedor = Limites(1001, 1005, 0);
        if (cod_vendedor)
        {
            printf ("\nDel producto.");
            do
            {
                cod_producto = Limites(100, 999, 999);
                repetido = Existe(pt_vec_cod_prod, cod_producto, 15);
                if (repetido == -1)
                    printf ("\nError, el codigo no existe. Intente nuevamente.");
            } while (repetido == -1);

            do
            {
                printf ("\nIngrese la cantidad del producto %d : ", cod_producto);
                fflush(stdin);
                scanf("%d", &cant);
                if (cant < 0)
                    printf ("\nError, no puedo haber una cantidad negativa en un pedido. Intente nuevamente.");
            } while (cant < 0);

            *(pt_vec_cant_prod + repetido) = *(pt_vec_cant_prod + repetido) + cant;
            *(pt_vec_empleados + cod_vendedor - FACTOR_CORRECCION) = *(pt_vec_empleados + cod_vendedor - FACTOR_CORRECCION) + 1;
            contador++;
        }
    } while (cod_vendedor != 0);

    return contador;
}


void Mostrar (int *pt_vec_cod_prod, int *pt_vec_cant_prod, int *pt_vec_empleados)
{
    int i, j, aux_cod, aux_cant, min;
    system("cls");
    printf ("\n\n\n\t\t\t\tCANT UNIDADES\t\tCODIGO");

    for (i = 0 ; i < TAM-1 ; i++)
    {
        for (j = 0 ; j < TAM-1-i ; j++)
        {
            if (*(pt_vec_cant_prod+j) < *(pt_vec_cant_prod+j+1))
            {
                aux_cod = *(pt_vec_cod_prod+j);
                aux_cant = *(pt_vec_cant_prod+j);
                *(pt_vec_cod_prod+j) = *(pt_vec_cod_prod+j+1);
                *(pt_vec_cant_prod+j) = *(pt_vec_cant_prod+j+1);
                *(pt_vec_cod_prod+j+1) = aux_cod;
                *(pt_vec_cant_prod+j+1) = aux_cant;
            }
        }
    }
    for (i = 0 ; i < TAM ; i++)
    {
        printf ("\n\t\t\t\t\t%d\t\t  %d", *(pt_vec_cant_prod+i), *(pt_vec_cod_prod+i));
    }

    printf ("\n\nEl o los vendedores que realizaron la menor cantidad de ventas : ");

    min = *(pt_vec_empleados);
    for (i = 1 ; i < EMP ; i++)
    {
        if (*(pt_vec_empleados+i) < min)
            min = *(pt_vec_empleados+i);
    }
    for (i = 0 ; i < EMP ; i++)
    {
        if (*(pt_vec_empleados+i) == min)
        printf ("%d, ", i+FACTOR_CORRECCION);
    }
    printf (" con %d ventas." , min);
}

