#include "funciones.h"

void Agregar_pasajeros(t_vuelos *vuelo,FILE * arch1, int cantidad)

{
    t_pasajeros pasajeros;

    while(fread(&pasajeros, sizeof(t_pasajeros), 1, arch1) == 1)
    {
        for (int i = 0 ; i < cantidad ; i++)
        {
            if (pasajeros.num_vuelo == (vuelo+i)->numero_vuelo)
            {
                (vuelo+i)->pasajeros = (vuelo+i)->pasajeros +1;
                break;
            }
        }
    }
    fclose(arch1);
}

void Guardar(t_vuelos *vuelo, int cantidad)

{
    FILE *arch = abrir_archivos("Aero1.dat", "wb");

    int i;
    char eleccion;

    for (i = 0 ; i < cantidad ; i++)
    {
        if (strcmp((vuelo+i)->codigo, "AERO1") == 0)
            fwrite((vuelo+i), sizeof(t_vuelos), 1, arch);
    }
    fclose(arch);

    do
    {
        printf("\n\nDesea grabar el archivo Aero1 en formato .csv (para abrir con Excel) S/N : ");
        scanf(" %c", &eleccion);
        eleccion = tolower(eleccion);
        if (eleccion != 's' && eleccion != 'n')
            printf("\n\nError eligiendo, debe ser S (si) o N (no). Intente nuevamente.");
    }while (eleccion != 's' && eleccion != 'n');

    if (eleccion == 's')
    {
            FILE *arch1 = abrir_archivos("Aero1.csv", "wt");

            fprintf(arch1,"Codigo Aerolinea;Dia;Numero de Vuelo;Costo del pasaje;Pasajeros\n");
            for (i = 0 ; i < cantidad ; i++)
            {
                if (strcmp((vuelo+i)->codigo, "AERO1") == 0)
                    fprintf(arch1,"%s;%d;%d;%.2f;%d\n", (vuelo+i)->codigo, (vuelo+i)->dia, (vuelo+i)->numero_vuelo,
               (vuelo+i)->costo_pasaje, (vuelo+i)->pasajeros);
            }
            fclose(arch1);
    }

}

FILE* abrir_archivos(char *nombre, char *modo)

{
    FILE *f = fopen(nombre, modo);
    if (f == NULL) {
        printf("Error fatal con el archivo.");
        exit(1);
    }
    return f;
}

t_vuelos* crear_vuelos(int cap)
{
    t_vuelos *p = (t_vuelos*) malloc(cap * sizeof(t_vuelos));

    if (p == NULL)
    {
        printf("\n\nError. No hay memoria RAM suficiente.");
        system("pause");
        exit(1);
    }
    return p;
}
