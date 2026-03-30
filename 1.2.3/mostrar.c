#include "main.h"

void Mostrar(char Matriz[][52], int *pt_vec_dni, int cantidad)
{
    char vec_name[52], aux_nombre[52];
    int aux_dni, i = 0, j, encontrado = 0;

    system("cls");

    if (cantidad == 0)
    {
        printf ("\n\nNO SE INGRESARON DATOS.");
    }
    else
    {
    do
    {
        printf ("\n\nIngrese el nombre a buscar (sino escriba NOBUSCARMAS para terminar)");
        Nombre(vec_name);
        if (strcmpi(vec_name, "NOBUSCARMAS") != 0)
        {
            do
            {
                if (strcmpi(vec_name, Matriz[i]) == 0)
                {
                    printf ("\n\nEl DNI del alumno %s es : %d", Matriz[i], *(pt_vec_dni+i));
                    encontrado = 1;
                }
                else
                    i++;
            }while (i < cantidad && encontrado == 0);
        if (encontrado == 1)
            encontrado = 0;
        else
            printf ("\n\nAlumno no encontrado, intente con otro.");

        }

    }while (strcmpi(vec_name, "NOBUSCARMAS") != 0);






    for ( i= 0 ; i < cantidad -1 ; i++)
    {
        for (j = 0 ; j < cantidad-1-i ; j++)
        {
            if (strcmpi(Matriz[j], Matriz[j+1]) > 0)
            {
                aux_dni = *(pt_vec_dni+j);
                *(pt_vec_dni+j) = *(pt_vec_dni+j+1);
                *(pt_vec_dni+j+1) =aux_dni;
                strcpy(aux_nombre, Matriz[j]);
                strcpy(Matriz[j], Matriz[j+1]);
                strcpy(Matriz[j+1], aux_nombre);
            }
        }
    }
    printf("\n\n Listado de alumnos: ");
    printf("\nNombre\tDNI");
     for ( i= 0 ; i < cantidad ; i++)
    {
        printf ("\n%s\t%d", Matriz[i], *(pt_vec_dni+i));
    }
    }
}
