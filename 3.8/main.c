#include "funciones.h"

int main()
{
    FILE *arch= Archivos("INSCRIPTOS.dat", "rb+");
    FILE *arch1= Archivos("interesados.dat", "ab+");

    t_inscriptos inscriptos[TAM];
    t_inscriptos ins;
    t_interesados inter;
    int cant;

    cant = Carga_inscriptos(arch, inscriptos);
    cant = Ingreso_dni(inscriptos, cant, arch1);

    rewind(arch);
    fwrite(inscriptos, sizeof(t_inscriptos), cant, arch);

    rewind(arch);
    rewind(arch1);

    while (fread(&ins, sizeof(t_inscriptos), 1, arch) == 1)
    {
        printf("%-10d%-25s%d\n", ins.dni, ins.ayn, ins.pagado);
    }
    printf("\n\n");
    while (fread(&inter, sizeof(t_interesados), 1, arch1) == 1)
    {
        printf("%-10d%-25s%d\n", inter.dni_interesado, inter.ayn_interesado, inter.telefono);
    }


    fclose(arch);
    fclose(arch1);
    printf("\n\n");
    system("pause");
    return 0;
}
