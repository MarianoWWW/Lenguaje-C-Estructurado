#include "main.h"

void Punto_E (PERSONA2 *personal)

{
    printf("\nIngrese el Apellido (maximo 15 caracteres) : ");
    fflush(stdin);
    gets(personal->nom_ape.apellido);
    printf("\nIngrese el Nombre (maximo 15 caracteres) : ");
    fflush(stdin);
    gets(personal->nom_ape.nombre);
    printf("\nIngrese el dia de nacimiento (entre 1 y 31) : ");
    fflush(stdin);
    scanf("%d", &personal->nacimiento.dia_nacimiento);
    printf("\nIngrese el mes de nacimiento (entre 1 y 12) : ");
    fflush(stdin);
    scanf("%d", &personal->nacimiento.mes_nacimiento);
    printf("\nIngrese el anio de nacimiento (entre 1950 y 2026): ");
    fflush(stdin);
    scanf("%d", &personal->nacimiento.anio_nacimiento);
}
