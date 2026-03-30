#include "main.h"

int main()
{
    t_alumno alumno[TAM];

    int cantidad;

    cantidad = Ingreso(alumno);

    if (cantidad)
        RESULTADO(alumno, cantidad);
    else
        printf("\n\nNo se ingresaron alumnos.");

    printf("\n\n");
    system("pause");
    return 0;
}
