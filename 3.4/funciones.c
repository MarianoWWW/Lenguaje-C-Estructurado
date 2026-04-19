#include "funciones.h"

void Mostrar(char path[])

{
    t_productos producto;
    FILE * arch=fopen(path,"rb");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo para lectura.");
        printf("\n\n");
        system("pause");
        exit(1);
    }
    while (fread(&producto, sizeof(t_productos), 1, arch) == 1 )
    {
        printf("\n%-8d%-15.2f%s", producto.codigo, producto.precio, producto.descripcion);
    }
    fclose(arch);
}

void Porcentaje()

{
    FILE * arch=fopen("PRECIOS.dat", "rb");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo para lectura.");
        printf("\n\n");
        system("pause");
        exit(1);
    }

    char path[] = {"Precios_actualizados.dat"};

    FILE * arch1=fopen(path, "wb");
    if (arch1 == NULL)
    {
        printf("\n\nError al abrir el archivo para escritura.");
        printf("\n\n");
        system("pause");
        fclose(arch);
        exit(1);
    }
    t_productos producto;
    float porcentaje;
    do
    {
        printf("\n\nIngrese el porcentaje que desee para modificar todos los precios : ");
        scanf("%f", &porcentaje);
        if (porcentaje == 0)
            printf("\n\nError, el porcentaje al menos  no deberia ser cero, intente nuevamente.");
    }while (porcentaje == 0);

    while (fread(&producto, sizeof(t_productos), 1, arch) == 1 )
    {
        producto.precio = producto.precio + ((producto.precio * porcentaje) / 100);
        fwrite(&producto, sizeof(t_productos), 1, arch1);
    }
    fclose(arch);
    fclose(arch1);
    Mostrar(path);
}

