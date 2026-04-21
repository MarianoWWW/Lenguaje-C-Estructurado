#include "funciones.h"

int main()
{
    FILE *arch=fopen("empleados.dat","rb+");
    if (arch == NULL)
    {
        printf("\n\nError al abrir el archivo.");
        system("pause");
        exit(1);
    }
    t_empleados empleado, empleado_mas_uno;
    int i,j, bytes, cant;

    fseek(arch,0, SEEK_END);
    bytes = ftell(arch);
    cant = bytes/sizeof(t_empleados);
    rewind(arch);
    for (i = 0 ; i < cant-1 ; i++)
    {
        for (j = 0; j < cant-i-1; j++)
        {
            fseek(arch, j * sizeof(t_empleados), SEEK_SET);
            fread(&empleado, sizeof(t_empleados), 1, arch);
            fread(&empleado_mas_uno, sizeof(t_empleados), 1, arch);
            if (empleado_mas_uno.legajo < empleado.legajo)
            {
                fseek(arch, j * sizeof(t_empleados), SEEK_SET);
                fwrite(&empleado_mas_uno, sizeof(t_empleados), 1, arch);
                fwrite(&empleado, sizeof(t_empleados), 1, arch);
            }

        }
    }

    rewind(arch);
    for (i = 0 ; i < cant ; i++)
    {
        fread(&empleado, sizeof(t_empleados),1, arch);
        printf("%d\n", empleado.legajo);
    }

    fclose(arch);
    printf("\n\n");
    system("pause");
    return 0;
}
