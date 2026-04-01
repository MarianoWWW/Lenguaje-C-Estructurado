#include "main.h"

void Descripcion(char *desc)

{
    do
    {
        printf ("\n\ningrese la nueva descripcion del producto : ");
        fflush(stdin);
        fgets(desc, TAM+1, stdin);
        Eli_enter(desc);
        if (strlen(desc) > TAM-1)
            printf ("\n\nError, la descripcion no puede superar los 20 caracteres. Intente nuevamente.");
    }while (strlen(desc) > TAM-1);
}
