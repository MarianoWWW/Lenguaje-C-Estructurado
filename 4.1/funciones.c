#include "funciones.h"

void Mostrar( FILE *arch1)

{
    t_promedio prom;
    fseek(arch1, 0, SEEK_SET);
    printf("\n\n----------------------------------------------------------------------------------------------------------------------");
    while(fread(&prom, sizeof(t_promedio),1, arch1) == 1)
    {
        printf("\n\nNumero de canal %d , promedio = %.2f", prom.numero_canal, prom.promedio);
    }
    printf("\n\n----------------------------------------------------------------------------------------------------------------------");
}
