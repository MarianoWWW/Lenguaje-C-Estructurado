#include "main.h"

void Punto_D (PERSONA2 *personal)

{
    printf("\nApellido           : %s", personal->nom_ape.apellido);
    printf("\nNombre             : %s", personal->nom_ape.nombre);
    printf("\nDia de nacimiento  : %d", personal->nacimiento.dia_nacimiento);
    printf("\nMes de nacimiento  : %d", personal->nacimiento.mes_nacimiento);
    printf("\nAnio de nacimiento : %d", personal->nacimiento.anio_nacimiento);
}
