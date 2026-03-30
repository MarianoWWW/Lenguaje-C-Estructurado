#include "main.h"

int main()
{
    float Matriz [TAM][12] = {{0}};
    int contador, vec_cod_prod[TAM]= {0};
    int *pt_vec_cod_prod;

    pt_vec_cod_prod = vec_cod_prod;

    contador = Ventas(pt_vec_cod_prod, Matriz);


    system("cls");
    if(contador)
    {
        Mostrar(pt_vec_cod_prod, Matriz, contador);
    }
    else
        printf("\n\nNo se cargaron datos.");

    printf("\n\n");
    system("pause");

    return 0;
}

int Ventas (int *pt_vec_cod_prod, float Matriz[][12])
{
 int cod, mes, repetido, cant, contador = 0;
 float precio;
 char net;

 printf ("\n\nVamos a hacer el detalle anual de las ventas.\n");

do
{
    printf ("Ingrese el codigo del producto de 5 digitos (cero para terminar) : ");
    cod = Valida(10000,99999,0);
    if (contador == 30)
        cod = 0;
    if (cod)
    {
        printf ("\nIngrese el mes : ");
        mes = Valida(1,12,12);
        mes--;
        repetido = Existe(pt_vec_cod_prod, cod);
        do
        {
            printf ("\nIngrese la cantidad vendida : ");
            fflush(stdin);
            scanf("%d", &cant);
            if (cant < 1 )
                printf ("\nLa cantidad debe ser mayor a 0.");
        }while (cant < 1 );
        do
        {
            printf ("\nIngrese el precio unitario : ");
            fflush(stdin);
            scanf("%f", &precio);
            if (precio <= 0 )
                printf ("\nLa cantidad debe ser mayor a 0.");
        }while (precio <= 0 );
        if (repetido != -1 && Matriz [repetido][mes] != 0 )
        {
             printf ("\n\nSe ingreso un dato duplicado, desea reemplazar el dato anterior (S/N) : ");
             do
             {
                 fflush(stdin);
                 scanf("%c", &net);
                 net = toupper(net);
                 if (net != 'S' && net != 'N')
                    printf ("\nError. Elija entre ( S / N ) o sea Si / No :");
             }while (net != 'S' && net != 'N');

             if (net =='S')
                Matriz[repetido][mes] = precio * (float)cant;

        }
        else
        {
            if (repetido != -1)
            {
                Matriz[repetido][mes] = precio * (float)cant;
            }
            else
            {
                *(pt_vec_cod_prod+contador) = cod;
                Matriz[contador][mes] = precio * (float)cant;
                contador++;
            }

        }


    }
}while (cod != 0);



 return contador;
}

int Valida (int a, int b, int c)
{
    int cod;
    do
    {
        fflush(stdin);
        scanf("%d", &cod);
        if ((cod < a|| cod > b) && cod != c)
            printf ("\nError en el dato ingresado, intente nuevamente : ");
    }while ((cod < a || cod > b) && cod != c);

    return cod;
}
int Existe (int *pt_vec_cod_prod, int cod)
{
    for (int i = 0 ; i < TAM ; i++)
    {
        if (*(pt_vec_cod_prod + i) == cod)
        return i;
    }
    return -1;
}

void Mostrar(int *pt_vec_cod_prod,float Matriz[TAM][12], int contador)
{
     system("cls");
     printf ("\nResumen del importe recaudado en cada mes de las ventas de cada producto");
     printf ("\n\t\t\t\t\tMes");
     printf ("\nProducto\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");
     for (int i = 0 ; i < contador ; i++)
     {
         printf("\n%d\t", *(pt_vec_cod_prod+i));
         for (int j = 0 ; j < 12 ; j++)
         {
             printf ("\t%.2f", Matriz[i][j]);
         }
     }
}


