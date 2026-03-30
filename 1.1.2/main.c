/*

1.1.2 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no pueden
existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado de
mayor a menor por nota.

*/




#include "main.h"

int main()
{
    int cantidad = 0, vec_dni[60] = {0}, vec_nota[60] = {0};
    int *pt_vec_dni, *pt_vec_nota;

    pt_vec_dni = vec_dni;
    pt_vec_nota = vec_nota;

    cantidad = IngresarDatos (pt_vec_dni, pt_vec_nota);
    Mostrar (pt_vec_dni, pt_vec_nota, cantidad);

    return 0;
}

int IngresarDatos (int *pt_vec_dni, int *pt_vec_nota)
{
    int cant = 0, dni = 5, nota;

    while (cant < 60 && dni >= 0)
    {
        printf ("\n\nIngrese el DNI del alumno (numero negativo para salir) : ");
        do
        {
            fflush(stdin);
            scanf ("%d", &dni);
            if (dni > 99999999)
                printf ("\nEse numero de DNI es muy grande, intente nuevamente : ");
        }while (dni > 99999999);
        if (dni >= 0)
        {
           if(BuscarDuplicados (pt_vec_dni, dni, cant) )
           {
               printf ("\n\nDNI ya ingresado, intente nuevamente.");
           }
           else
            {

                printf ("\n\nIngrese la nota del alumno : ");
                do
                {
                fflush(stdin);
                scanf ("%d", &nota);
                if (nota < 0 || nota > 10)
                    printf ("\nEsa nota no existe, intente nuevamente : ");
                }while (nota < 0 || nota > 10);
                *(pt_vec_dni + cant) = dni;
                *(pt_vec_nota + cant) = nota;
                cant ++;
            }
        }
    }
    return cant;
}

bool BuscarDuplicados (int *pt_vec_dni, int dni, int cant)
{

    for (int a = 0 ; a < cant ; a++)
    {
        if (*(pt_vec_dni) == dni)
            return true;
    }
    return false;
}

void Mostrar (int *pt_vec_dni, int *pt_vec_nota, int cantidad)
{
    int i, dni_aux, nota_aux;

    for (i = 0 ; i < cantidad-1 ; i++)
    {
        for (int j = 0 ; j < cantidad-1-i ; j++)
        if (*(pt_vec_nota + j) < *(pt_vec_nota + j+1))
        {
            dni_aux = *(pt_vec_dni+j);
            nota_aux = *(pt_vec_nota+j);
            *(pt_vec_dni+j) = *(pt_vec_dni+j+1);
            *(pt_vec_nota+j) = *(pt_vec_nota+j+1);
            *(pt_vec_dni+j+1) = dni_aux;
            *(pt_vec_nota+j+1) = nota_aux;
        }
    }
    system("cls");
    printf("Listado de alumnos con su correspondiente DNI y la nota obtenida.\n\n");
    for (i = 0 ; i < cantidad ; i++)
    {
        printf("\n%d\t\t\t%d", *pt_vec_dni+i, *(pt_vec_nota+i));
    }
}
