#include "funciones.h"

int main()
{
    FILE * arch=fopen(PATH,"rb+");
    if (arch == NULL)
    {
        printf("\n\nError abriendo el archivo %s", PATH);
        system("pause");
        exit(1);
    }


    t_fecha fecha_actual;
    int cat, i=0, j = 0, fecha_val, cap_max = 10 ;
    t_empleados *empleados = malloc(cap_max*sizeof(t_empleados));
    if (empleados == NULL)
    {
        printf("\n\nError obteniendo memoria.");
        system("pause");
        exit(1);
    }
    do
    {
        printf("\nIngrese la fecha de hoy, van a ser 3 items.\n Ingrese el anio actual : ");
        scanf("%d", &fecha_actual.anio);
        printf("\nIngrese el mes actual : ");
        scanf("%d", &fecha_actual.mes);
        printf("\nIngrese el dia actual : ");
        scanf("%d", &fecha_actual.dia);



        if (!(fecha_val = fecha_valida(&fecha_actual)))
            printf("\n\nError, esa fecha no existe. Intente nuevamente.");
    }while (!(fecha_val = fecha_valida(&fecha_actual)));

    while (fread(empleados+i, sizeof(t_empleados), 1, arch) == 1)
    {
        if ((empleados+i)->fecha.anio < fecha_actual.anio)
            cat = fecha_actual.anio - (empleados+i)->fecha.anio;
        else
            cat = 0;
        switch(cat)
        {
        case 0:
        case 1:
        case 2: (empleados+i)->categoria = 1;
            break;
        case 3:
        case 4:
        case 5: (empleados+i)->categoria = 2;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:(empleados+i)->categoria = 3;
            break;
        default: (empleados+i)->categoria = 5;
        }


        i++;
        if (i == cap_max)
        {
            cap_max = cap_max * 2;
            empleados = realloc(empleados, cap_max * sizeof(t_empleados));
            if (arch == NULL)
            {
                printf("\n\nError redimensionando la memoria.");
                system("pause");
                exit(1);
            }
        }
    }
    rewind(arch);
    fwrite(empleados, sizeof(t_empleados), i, arch);

    rewind(arch);
    i = 0;
printf("\n\n%-7s%-16s%-31s%-5s%-5s%-5s%-10s", "Legajo", "Apellido", "Nombre", "Dia", "Mes", "Anio", "Categoria");
while (fread(empleados+i, sizeof(t_empleados), 1, arch) == 1)
{
    printf("\n%-7d%-16s%-31s%-5d%-5d%-5d%-10d",
           (empleados+i)->legajo,
           (empleados+i)->apellido,
           (empleados+i)->nombre,
           (empleados+i)->fecha.dia,
           (empleados+i)->fecha.mes,
           (empleados+i)->fecha.anio,
           (empleados+i)->categoria);
    i++;
}
    fclose(arch);
    free(empleados);
    printf("\n\n");
    system("pause");
    return 0;
}
