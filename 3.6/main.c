/*

3.6 Realizar un programa que tome el archivo Faltantes.dat del ejercicio anterior y unifique las cantidades
sumariándolas por artículo (la empresa trabaja con 10 artículos en total, pero no todos pueden estar en
falta). Generar una planilla Excel para enviar al proveedor con el pedido a realizar. Para ello se debe crear un
nuevo archivo llamado pedido.csv que contenga los registros por artículo conteniendo:
• Código de artículo (entero)
• Cantidad (entero)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    int cantidad;
}t_faltantes;

int main()
{
    FILE * arch = fopen("faltantes.dat", "rb");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo.");
        system("pause");
        exit(1);
    }
    FILE * arch1 = fopen("pedido.csv", "wt");
    if (arch1 == NULL)
    {
        printf("\n\nError al abrir el archivo.");
        fclose(arch);
        system("pause");
        exit(1);
    }

    t_faltantes faltantes;
    int acumulador[10] = {0}, i;

    while(fread(&faltantes, sizeof(t_faltantes), 1, arch) == 1)
    {
        i = (faltantes.codigo) - 1000;
        *(acumulador+i) = *(acumulador+i) + faltantes.cantidad;
    }
    fprintf(arch1,"Codigo;Cantidad\n");
    for (i = 0 ; i < 10 ; i++)
    {
        if (*(acumulador+i) != 0)
        {
            fprintf(arch1,"%d;%d\n", i+1000, acumulador[i]);
        }
    }


    fclose(arch);
    fclose(arch1);
    printf("\n\n");
    system("pause");
    return 0;
}
