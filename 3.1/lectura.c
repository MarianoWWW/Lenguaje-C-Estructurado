#include "main.h"

void LECTURA(t_alumno *alumno)

{
    FILE * arch = fopen("alumnos.dat", "rb");

    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo para lectura.");
        system("pause");
        exit(1);
    }
    system("cls");
    printf("\n\nLectura de datos del archivo alumnos.dat : ");
    printf("\n%-10s %-80s %-6s %-6s %-6s", "DNI", "Nombre y Apellido", "Nota 1", "Nota 2", "Promedio");

    while ((fread (alumno, sizeof(t_alumno),1,arch)) == 1)
    {
        printf ("\n%-10d %-80s %-6d %-6d %-6.1f", alumno->dni, alumno->nom_ape, alumno->notas.nota1,
                alumno->notas.nota2, alumno->nota_promedio);
    }
    fclose(arch);
}
