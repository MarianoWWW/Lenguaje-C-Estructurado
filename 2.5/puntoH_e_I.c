#include "main.h"

void Punto_H_e_I (PERSONA3 *pers)

{
    printf("\nApellido           : %s", pers->nom_ape.apellido);
    printf("\nNombre             : %s", pers->nom_ape.nombre);
    printf("\nDia de nacimiento  : %d", pers->nacimiento.dia_nacimiento);
    printf("\nMes de nacimiento  : %d", pers->nacimiento.mes_nacimiento);
    printf("\nAnio de nacimiento : %d", pers->nacimiento.anio_nacimiento);
    printf("\nCodigo de materia/s aprobada/s : ");

    for (int i = 0 ; i < 36 ; i++)
    {
        if ( pers->materias_aprobadas[i] == 0)
            break;
        else
             printf("%d , ", pers->materias_aprobadas[i]);
    }
}

