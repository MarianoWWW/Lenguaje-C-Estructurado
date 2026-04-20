#include "funciones.h"

int CargaTarifas(t_tarifas *tarifas)

{
    FILE *arch=fopen("tarifas.dat","rb");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo.");
        system("pause");
        exit(1);
    }
    int mes_elegido, cont = 0;
    t_tarifas *ptr = tarifas;
    do
    {
        printf("\n\nIngrese el numero del mes_elegido (1 a 12) : ");
        scanf("%d", &mes_elegido);
        if (mes_elegido < 1 || mes_elegido > 12)
            printf("\n\nError en el mes_elegido ingresado, intente nuevamente.");
    }while (mes_elegido < 1 || mes_elegido > 12);

    while (fread(ptr, sizeof(t_tarifas), 1, arch) == 1)
    {
        if (ptr->mes == mes_elegido)
        {
            ptr ++;
            cont ++;
        }
    }
    fclose(arch);
    return cont;
}

void OrdenarViajes(FILE *arch, int cant)
{
    t_viajes viajes, viajes_mas_uno;
    int interno_nuevo, i, j, cant_interno;
    long pos_inicio;

    rewind(arch);
    fread(&viajes, sizeof(t_viajes), 1, arch);
    while (!feof(arch))
    {
        interno_nuevo = viajes.num_interno;
        pos_inicio = ftell(arch) - sizeof(t_viajes);
        cant_interno = 0;

        do
        {
            cant_interno++;
            fread(&viajes, sizeof(t_viajes), 1, arch);
        }while (interno_nuevo == viajes.num_interno && !feof(arch));

        for (i = 0; i < cant_interno - 1; i++)
        {
            for (j = 0; j < cant_interno - i - 1; j++)
            {
                fseek(arch, pos_inicio + j * sizeof(t_viajes), SEEK_SET);
                fread(&viajes, sizeof(t_viajes), 1, arch);
                fread(&viajes_mas_uno, sizeof(t_viajes), 1, arch);
                if (strcmp(viajes.codigo_tarifa, viajes_mas_uno.codigo_tarifa) > 0)
                {
                    fseek(arch, pos_inicio + j * sizeof(t_viajes), SEEK_SET);
                    fwrite(&viajes_mas_uno, sizeof(t_viajes), 1, arch);
                    fwrite(&viajes, sizeof(t_viajes), 1, arch);
                }
            }
        }
    }
}

void MostrarViajes(FILE *arch, FILE *arch1)

{
    t_cantidad_mes cant_mes;
    t_viajes viajes;

    rewind(arch1);
    printf("\n\n%-10s%-25s%-15s", "Interno", "Cantidad de viajes", "Recaudacion");
    while ((fread(&cant_mes, sizeof(t_cantidad_mes), 1, arch1)) == 1)
    {
         printf("\n%-10d%-25d%-15.2f", cant_mes.num_interno, cant_mes.cantidad_viajes, cant_mes.recaudacion);
    }
    rewind(arch);
    printf("\n\n%-10s%-10s%-20s%-5s%-5s", "Interno", "SUBE", "Codigo tarifa", "dia", "mes");
    while ((fread(&viajes, sizeof(t_viajes), 1, arch)) == 1)
    {
         printf("\n%-10d%-10d%-20s%-5d%-5d", viajes.num_interno, viajes.num_sube, viajes.codigo_tarifa,
                  viajes.dia, viajes.hora);
    }
}
