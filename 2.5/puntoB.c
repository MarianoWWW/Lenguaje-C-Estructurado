#include "main.h"

void Punto_B (PERSONA *personal)

{
    printf("\nNumero de legajo   : %d", personal->numero_legajo);
    printf("\nApellido           : %s", personal->apellido);
    printf("\nNombre             : %s", personal->nombre);
    printf("\nAltura             : %f", personal->altura);
    printf("\nSexo               : %c", personal->sexo);
    printf("\nDia de nacimiento  : %d", personal->dia_nacimiento);
    printf("\nMes de nacimiento  : %d", personal->mes_nacimiento);
    printf("\nAnio de nacimiento : %d", personal->anio_nacimiento);
}
