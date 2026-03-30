#include "main.h"

int main()
{

    char palabra[TAM], escondida[TAM+10];

    printf("\n\nJuego del ahorcado.");

    IngresaPalabra(palabra);
    AdivinaPalabra(palabra, escondida);






    printf ("\n\n");
    system("pause");

    return 0;
}
