#include "funciones.h"

void Enter(char * cad)

{
    while (*cad != '\0')
    {
        if (*cad == '\n')
            *cad = '\0';
        else
            cad ++;
    }
}

long long int Pasar(char *cad, long long int cant)

{
    long long int num, i, resultado= 0, contador;
    contador= 1;

    for (i = cant-1 ; i >= 0 ; i--)
    {
        num = *(cad+i)-48;
        resultado = resultado + (num * contador);
        contador=contador*10;
    }
    return resultado;
}
