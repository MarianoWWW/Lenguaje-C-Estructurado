#include "main.h"

void IngresaPalabra(char *palabra)
{
    int i = 0;
    do
    {
        printf("\n\nParticipante numero 1, debe ingresar una palabra que tenga un maximo de 10 letras : ");
        fflush(stdin);
        fgets(palabra, TAM, stdin);
        if (strlen(palabra) > 11)
            printf("\n\nError, palabra muy larga. Intente nuevamente.");
    }while (strlen(palabra) > 11);

    while (palabra[i] != '\0')
    {
        if (palabra[i] == '\n')
            palabra[i] = '\0';
        else
        {
            palabra[i] = toupper(palabra[i]);
            i++;

        }
    }


}
