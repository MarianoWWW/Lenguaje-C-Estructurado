#include "funciones.h"
int main()
{
    FILE *arch=fopen("viajes.dat","rb+");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo.");
        system("pause");
        exit(1);
    }
    FILE *arch1=fopen("recaudacion.dat","wb+");
    if (arch1 == NULL)
    {
        printf("\n\nError al hacer el archivo.");
        system("pause");
        fclose(arch);
        exit(1);
    }
    t_tarifas tarifas[8];
    t_tarifas *tarifa = tarifas;
    t_viajes viajes;
    t_cantidad_mes cantidad_mes;
    int contador, i, interno_nuevo, cantidad_viajes = 0, interno_min = 0, flag = -1;
    float importe_total = 0, importe_parcial = 0;
    contador = CargaTarifas(tarifas);
    fread(&viajes, sizeof(t_viajes), 1, arch);
    while (!feof(arch))
    {
        interno_nuevo = viajes.num_interno;
        do
        {
            for (i = 0 ; i < contador ; i++)
            {
                if (strcmp(viajes.codigo_tarifa, tarifa->cod_tarifa) == 0)
                {
                    importe_total = importe_total + tarifa->precio;
                    importe_parcial = importe_parcial + tarifa->precio;
                    tarifa = tarifas;
                    break;
                }
                tarifa++;
            }
            cantidad_viajes++;
            fread(&viajes, sizeof(t_viajes), 1, arch);
        }while (interno_nuevo == viajes.num_interno && (!feof(arch)));
        cantidad_mes.num_interno = interno_nuevo;
        cantidad_mes.cantidad_viajes = cantidad_viajes;
        cantidad_mes.recaudacion = importe_parcial;
        fwrite(&cantidad_mes, sizeof(t_cantidad_mes), 1, arch1);
        if (cantidad_viajes < interno_min || flag == -1)
        {
            interno_min = cantidad_viajes;
            flag = 0;
        }
        importe_parcial = 0;
        cantidad_viajes = 0;
    }
    printf("\n\nImporte total a cobrar por la empresa : $%-.2f", importe_total);
    printf("\n\nInterno/s con la menor cantidad de viajes : ");
    rewind(arch);
    while (!feof(arch))
    {
        interno_nuevo = viajes.num_interno;
        do
        {
            cantidad_viajes++;
            fread(&viajes, sizeof(t_viajes), 1, arch);
        }while (interno_nuevo == viajes.num_interno && (!feof(arch)));
        if (cantidad_viajes == interno_min)
            printf("%d ", interno_nuevo);
        cantidad_viajes = 0;
        fread(&viajes, sizeof(t_viajes), 1, arch);
    }
    tarifa = tarifas;
    for (i = 0 ; i < contador ; i++)
    {
        printf("\n%-7d%-12s%.2f", tarifa->mes, tarifa->cod_tarifa, tarifa->precio);
        tarifa++;
    }
    rewind(arch);
    OrdenarViajes(arch, contador);
    MostrarViajes(arch, arch1);
    fclose(arch);
    fclose(arch1);
    printf("\n\n");
    system("pause");
    return 0;
}
