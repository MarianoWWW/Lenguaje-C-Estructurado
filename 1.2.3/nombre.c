#include "main.h"

void Nombre(char *pt_vec_nombre)
{
    do
        {
            printf("\n\nIngrese el nombre del alumno : ");
            fflush(stdin);
            fgets(pt_vec_nombre, 52, stdin);
            if (strlen(pt_vec_nombre) > 50)
                 printf("\nNombre demasiado largo, no lo puedo guardar, intente con otro.");
        }while ((strlen(pt_vec_nombre) > 50));
        Enter(pt_vec_nombre);
}
