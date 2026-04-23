#include "funciones.h"

int main()
{
    FILE *arch = abrir_archivos("VUELOS.dat", "rb");
    FILE *arch1 = abrir_archivos("PASAJEROS.dat", "rb");

    int i = 0, cap = 2;

    t_vuelos *vuelo = crear_vuelos(cap);

    while(fread((vuelo+i), sizeof(t_vuelos), 1, arch) == 1)
        {
            i++;
            if (i == cap)
            {
                cap = cap * 2;
                vuelo = realloc(vuelo, cap*sizeof(t_vuelos));
                if (vuelo == NULL)
                {
                    printf("Error al asignar memoria\n");
                    exit(1);
                }
            }
        }
    fclose(arch);
    Agregar_pasajeros(vuelo, arch1, i);
    Guardar(vuelo, i);

    printf("\n\n");
    system("pause");
    return 0;
}
