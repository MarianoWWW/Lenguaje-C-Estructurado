#include "main.h"

int main()
{
    t_alumno alumno;

    FILE *arch = fopen("alumnos.dat", "wb");

    int n1, n2, i, dni_ingresado;
    char name[TAM];

    if (arch == NULL)
    {
        printf("\nError al abrir el archivo de lectura.");
        system("pause");
        exit(1);
    }


    printf("\n\nVamos a ingresar los datos de alumnos para guardarlos.");

    do
    {
        printf("\n\nIngrese el numero de DNI (cero para terminar).");
        dni_ingresado = Limite (1000000, 99999999, MINI);
        if (dni_ingresado != 0)
        {
            do
            {
                printf("\n\nIngrese el nombre del alumno : ");
                fflush(stdin);
                fgets(name, TAM, stdin);
                i = 0;
                while (name[i] != '\0')
                {
                    if (name[i] == '\n')
                        (name[i] = '\0');
                    else
                        i++;
                }
                if (strlen(name) > TAM-2)
                    printf("\nError, Nombre y Apellido muy largos, intente nuevamente.");
            }while (strlen(name) > TAM-2);
            printf("\n\nIngrese la primera nota del alumno.");
            n1 = Limite(MINI, MAXI, MAXI);
            printf("\n\nIngrese la segunda nota del alumno.");
            n2 = Limite(MINI, MAXI, MAXI);

            alumno.dni = dni_ingresado;
            strcpy(alumno.nom_ape, name);
            alumno.notas.nota1 = n1;
            alumno.notas.nota2 = n2;
            alumno.nota_promedio = ((float)n1 + n2)/2;
            fwrite (&alumno, sizeof(t_alumno), 1, arch);
        }
    }while (dni_ingresado != 0);
    fclose(arch);

    LECTURA(&alumno);

    printf("\n\n");
    system ("pause");

    return 0;
}
