#include "main.h"

void AdivinaPalabra(char *palabra, char *escondida)
{
    char letra, falladas[5];
    int i, j = 0, tapada, vida = 5, adivina = 0, suerte = 0, existe = 1, contador = 0, fallo = 1;

    falladas[0] = '\0';
    tapada = strlen(palabra);
    printf("\n%d", tapada);
    for (i = 0 ; i < tapada*2 ; i++)
    {
        if ((i % 2) == 0)
        escondida[i] = '_';
        else
            escondida[i] = ' ';
    }
    escondida[i] = '\0';

    do
    {



        do
        {
            system("cls");
            Dibujo(vida);
            printf("\n\n\nHora de adivinar la palabra : ");
            printf ("%s", escondida);
            printf("\n\nTenes %d vidas, ingresa tu letra elegida : ", vida);
            fflush(stdin);
            scanf("%c", &letra);
                if (!(letra != '\n' && letra != ' '))
                {
                    printf("\nPresionaste Enter o elegiste un espacio, no te voy a descontar ninguna vida.\n");
                    system("pause");
                    existe = 0;
                }
                else
                {
                    letra = toupper(letra);
                    existe = Duplicada(escondida, letra);
                    if (!existe)
                    {
                    printf("\nEsa letra ya la elegiste, no te voy a descontar ninguna vida.\n");
                    system("pause");
                    }
                }
        }while (!existe);

        while (palabra[j] != '\0')
        {
            if ( palabra[j] == letra)
            {
                escondida[j*2] = letra;
                adivina++;
                suerte++;
            }

            j++;
        }
        if (suerte == 0)
        {
            fallo = Duplicada(falladas, letra);
            if (!fallo)
            {
            printf("\nEsa letra ya la elegiste, no te voy a descontar ninguna vida.\n");
            system("pause");
            }
            else
            {
                vida--;
                falladas[contador] = letra;
                falladas[contador+1] = '\0';
                contador++;
            }

        }

        j = 0;
        suerte = 0;
    }while (vida > 0 && adivina != tapada);
        system("cls");
        Dibujo(vida);
        printf("\n\n\n                    Palabra : ");

        for (i = 0 ; i < tapada*2 ; i++)
    {
        if ((i % 2) == 0)
            printf ("%c", palabra[i/2]);
        else
            printf (" ");
    }


    if (adivina == tapada )
        printf ("\n\nGANASTE !!!!");
    else
        printf ("\n\nLo lamento, has perdido.");

}
