#include "main.h"

int main()
{

    int cant, i;
    t_producto *producto= malloc(TAM * sizeof(t_producto));
    if (producto == NULL)
    {
        printf("\n\nError al asignar memoria.");
        system("pause");
        exit(1);
    }

    FILE * arch = fopen (PATH, "r+b");
    if (arch == NULL)
    {
        printf ("\n\nError al abrir el archivo %s\n", PATH);
        system("pause");
        exit(1);
    }

    cant = Carga(arch, producto);

    if (cant > 0)
    {
        producto = realloc(producto, cant * sizeof(t_producto));
        if (producto == NULL)
        {
            printf("\n\nError al reasignar memoria.");
            system("pause");
            exit(1);
        }
    }
    for (i = 0 ; i < cant ; i++)
    {
        printf("\n%-7d%-7.2f%-52s", (producto+i)->codigo, (producto+i)->precio, (producto+i)->descripcion);
    }

    if (!(Modificar(producto, cant)))
        printf("No hubo modificaciones.");
    else
    {
        rewind(arch);
        fwrite(producto, sizeof(t_producto), cant, arch);
    }

    fclose(arch);
    free(producto);
    printf("\n\n");
    system("pause");
    return 0;
}
