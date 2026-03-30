#include "main.h"

int Cargar(char Matriz[][52], int *pt_vec_dni)
{
    char vec_nombre[52];
    char *pt_vec_nombre;

    pt_vec_nombre = vec_nombre;
    int cant = 0, i = 0, dni, repetido;

    printf("\n\nVamos a ingresar el nombre de los alumnos del curso.(Ingrese FIN para terminar)");

    do
    {
        repetido = -1;
        Nombre(pt_vec_nombre);
        if (strcmpi(pt_vec_nombre,"FIN") != 0)
        {
            do
            {
                printf("\nIngrese el DNI del alumno : ");
                fflush(stdin);
                scanf("%d", &dni);
                if( dni < 1000000 || dni > 99999999)
                    printf("\nNumero de DNI fuera de rango, intente nuevamente.");
            }while (dni < 1000000 || dni > 99999999);
            while (repetido == -1 && i < cant)
            {
                if (*(pt_vec_dni +i ) == dni)
                {
                    printf("\nNumero de DNI repetido. Comencemos de nuevo desde el nombre por las dudas.");
                    repetido = i;
                }
                else
                {
                    i++;
                }
            }
            if (repetido == -1)
            {
                strcpy(Matriz[cant], pt_vec_nombre);
                *(pt_vec_dni+cant) = dni;
                cant ++;
            }


        }


    }while ( cant < 51 && (strcmpi(pt_vec_nombre,"FIN") != 0));

    return cant;
}
