#include "main.h"

int main()
{
    t_producto producto;
    int cod, elec, flag = -1;
    char desc[TAM+1];
    float prec;

    FILE * arch = fopen(PATH, "r+b");

    if (arch == NULL)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        exit(1);
    }
    do
    {
        cod = Codigo(0);
        if (cod != 0)
        {
            rewind(arch);
            while (fread(&producto, sizeof(t_producto), 1, arch) == 1)
            {
                if (producto.codigo == cod)
                {
                     printf("\n\n--- Datos actuales del producto ---");
                     printf("\nCodigo      : %d", producto.codigo);
                     printf("\nDescripcion : %s", producto.descripcion);
                     printf("\nPrecio      : %.2f", producto.precio);
                     flag = 1;
                     printf("\n\nQue desea modificar.\nMenu : \n1. Precio\n2. Descripcion\n3. Ambos\n\nSu eleccion : ");
                     do
                     {
                         scanf("%d", &elec);
                         if (elec < 1 || elec > 3)
                             printf("\n\nElección fuera de rango, debe ser 1, 2 o 3. Intente nuevamente : ");
                     }while (elec < 1 || elec > 3);

                     switch(elec)
                     {
                         case 1: prec = Precio();
                                 producto.precio = prec;
                                break;
                         case 2: Descripcion(desc);
                                 strcpy(producto.descripcion, desc);
                                break;
                        default: prec = Precio();
                                 producto.precio = prec;
                                 Descripcion(desc);
                                 strcpy(producto.descripcion, desc);
                     }
                     fseek(arch, -(long)sizeof(t_producto), SEEK_CUR);
                     fwrite(&producto, sizeof(t_producto), 1, arch);
                     fflush(arch);
                }
            }
            if (flag == -1)
                 printf("\n\nError, ese codigo no existe en el archivo, intente con otro.");
            else
                flag = -1;
        }


    }while (cod != 0);


    printf("\n\n--- Contenido actual del archivo ---\n");
    rewind(arch);
    while (fread(&producto, sizeof(t_producto), 1, arch) == 1)
        {
            printf("Codigo: %d | Descripcion: %s | Precio: %.2f\n",
            producto.codigo, producto.descripcion, producto.precio);
        }
    fclose(arch);
    printf("\n\n");
    system("pause");
    return 0;
}
