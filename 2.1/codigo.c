#include "main.h"

void Cod (char *codigo, int largo)
{
    do
    {
        fflush(stdin);
        fgets(codigo, largo, stdin);
        Enter (codigo);
        if (strlen(codigo) > largo-2 || codigo[0] == ' ' || codigo[0] == '\0')
            printf("\n\nError en la longitud de caracteres ingresada, intente nuevamente : ");
    }while (strlen(codigo) > largo-2 || codigo[0] == ' ' || codigo[0] == '\0');
}
