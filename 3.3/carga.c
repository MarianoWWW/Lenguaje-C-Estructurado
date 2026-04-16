#include "main.h"

int Carga(FILE *arch, t_producto *producto)

{
    int i = 0;
    while (i < TAM && (fread(producto+i, sizeof(t_producto), 1, arch) == 1 ))
        i++;
    return i;
}
