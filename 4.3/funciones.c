#include "funciones.h"

void Logica()
{
    FILE * arch=fopen(PATH, "rb");
    if (arch == NULL)
    {
        printf("\n\nError al intentar leer el archivo %s", PATH);
        system("pause");
        exit(1);
    }
    FILE * arch1=fopen("COSTOS.dat", "rb");
    if (arch1 == NULL)
    {
        printf("\n\nError al intentar leer el archivo.");
        system("pause");
        fclose(arch);
        exit(1);
    }
    FILE * arch2=fopen("gastos.dat", "wb+");
    if (arch2 == NULL)
    {
        printf("\n\nError al intentar abrir el archivo.");
        system("pause");
        fclose(arch);
        fclose(arch1);
        exit(1);
    }
    t_llamada llamada;
    t_costos costos;
    t_gastos gastos;
    t_llama_valorizado val;

    fread(&costos, sizeof(t_costos), 1, arch1);
    fclose(arch1);

    char sector_nuevo[16], sector_maxi[16];
    int cant_1 = 0, cant_2 = 0, cant_3 = 0, max = 0, tiempo_max = 0;
    int tipo_1 = 0, tipo_2 = 0, tipo_3 = 0;

    fread(&llamada, sizeof(t_llamada), 1, arch);
    while (! feof(arch))
    {
        strcpy(sector_nuevo, llamada.sector);
        do
        {
            switch(llamada.tipo_de_llamada)
            {
            case 1: cant_1++;
                    tipo_1 = tipo_1 + llamada.duracion;
                break;
            case 2: cant_2++;
                    tipo_2 = tipo_2 + llamada.duracion;
                break;
            default: cant_3++;
                     tipo_3 = tipo_3 + llamada.duracion;
            }
            tiempo_max = tiempo_max + llamada.duracion;


            fread(&llamada, sizeof(t_llamada), 1, arch);
        }while ((strcmp(llamada.sector, sector_nuevo) == 0) && (! feof(arch)));
        printf("\n-------------------------------------------------------------------------------------------------------------");
        printf("\n%-17s%-35s%s", "Sector", "Tipo de llamada", "Cantidad de llamadas");
        printf("\n%-17s%-35s%d", sector_nuevo, "local", cant_1);
        printf("\n-------------------------------------------------------------------------------------------------------------");
        printf("\n%-17s%-35s%s", "Sector", "Tipo de llamada", "Cantidad de llamadas");
        printf("\n%-17s%-35s%d", sector_nuevo, "larga distancia", cant_2);
        printf("\n-------------------------------------------------------------------------------------------------------------");
        printf("\n%-17s%-35s%s", "Sector", "Tipo de llamada", "Cantidad de llamadas");
        printf("\n%-17s%-35s%d", sector_nuevo, "celular", cant_3);

        if (tiempo_max > max)
        {
            strcpy(sector_maxi, sector_nuevo);
            max = tiempo_max;
        }

        strcpy(gastos.total_sector, sector_nuevo);
        gastos.total_gastado = tipo_1 * costos.caso_1 + tipo_2 * costos.caso_2 + tipo_3 * costos.caso_3;
        fwrite(&gastos,sizeof(t_gastos),1, arch2);

        val.duracion_seg = tipo_1;
        val.tipo_llamada = 1;
        val.costo = costos.caso_1;
        Escribir(sector_nuevo, &val);

        val.duracion_seg = tipo_2;
        val.tipo_llamada = 2;
        val.costo = costos.caso_2;
        Escribir(sector_nuevo, &val);

        val.duracion_seg = tipo_3;
        val.tipo_llamada = 3;
        val.costo = costos.caso_3;
        Escribir(sector_nuevo, &val);

        strcpy(sector_nuevo, llamada.sector);
        cant_1 = 0;
        cant_2 = 0;
        cant_3 = 0;
        tiempo_max = 0;
        tipo_1 = 0;
        tipo_2 = 0;
        tipo_3 = 0;
    }
    printf("\n-------------------------------------------------------------------------------------------------------------");
    printf("\nSector que hablo la mayor cantidad de tiempo : %s", sector_maxi);
    printf("\n-------------------------------------------------------------------------------------------------------------");

    fclose(arch);
    rewind(arch2);
    Mostrar(arch2);
}

void Mostrar (FILE *arch2)

{
    t_gastos gastos;

    printf("\n%-20s%s", "Sector", "Total gastado");
    while (fread(&gastos, sizeof(t_gastos),1, arch2) == 1)
        printf("\n%-20s $ %.2f", gastos.total_sector, gastos.total_gastado);
    printf("\n-------------------------------------------------------------------------------------------------------------");
    fclose(arch2);
}
void Escribir(char sector[16], t_llama_valorizado *val)

{
    char ruta[50];

    strcpy(ruta, sector);
    strcat(ruta, ".dat");

    FILE * arch=fopen(ruta,"ab+");
    if (arch == NULL)
    {
        printf("\n\nError al intentar leer el archivo %s", PATH);
        system("pause");
        exit(1);
    }
    fwrite (val, sizeof(t_llama_valorizado),1, arch);
    fclose(arch);
}
