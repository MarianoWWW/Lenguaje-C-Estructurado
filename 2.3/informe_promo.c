#include "main.h"

void INFORME_PROMO(t_alumno *alumno, int cantidad)
{
    printf("\n\n Listado de alumnos PROMOCIONADOS : \n");
    for (int i = 0 ; i < cantidad ; i++)
    {
        if ((alumno+i)->notas.nota1 >= 7 && (alumno+i)->notas.nota2 >= 7 )
            printf("\n%d - %s - %.1f", (alumno+i)->dni, (alumno+i)->vec_Ape_Nom, (alumno+i)->promedio);
    }
}
