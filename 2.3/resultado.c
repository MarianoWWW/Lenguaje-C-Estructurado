#include "main.h"

void RESULTADO(t_alumno *alumno, int cantidad)
{
    int aprueba = 0, desaprueba = 0, i;

    system("cls");
    for (i = 0 ; i < cantidad ; i++)
    {
        if ((alumno+i)->promedio >= 4)
            aprueba ++;
        else
            desaprueba++;
    }
    printf("\n\nAprobaron la materia %d alumnos.", aprueba);
    printf("\n\nReprobaron la materia %d alumnos.", desaprueba);

    INFORME_PROMO(alumno, cantidad);
}
