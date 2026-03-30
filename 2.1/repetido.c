#include "main.h"

int Repetido(char *codigo,t_productos *vec_productos, int contador)
{
    for (int i = 0 ; i < contador ; i++)
    {
        if (strcmp(codigo, (vec_productos+i)->codi) == 0)
            return i;
    }
    return -1;
}
