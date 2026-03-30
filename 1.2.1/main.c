#include "main.h"

int main()
{
    int i = 0;
    char elegir,vec[10000];
    char *pt_vec;

    pt_vec = vec;

    printf("\n\nIngrese el texto, maximo 9999 caracteres, sino se corta : ");
    fgets (pt_vec, 10000, stdin);

    while ( *(pt_vec+i) != '\0')
    {
        if (*(pt_vec+i) == '\n')
            *(pt_vec+i) = '\0';
        else
            i++;
    }

    printf("\n\nAhora elige A para considerar que las palabras estan separadas por un unico espacio.");
    printf("\nB para considerar que las palabras estan separadas por mas de un espacio consecutivo.");
    do
    {
        printf("\n\nElija ahora (entre A y B) : ");
        fflush(stdin);
        scanf("%c", &elegir);
        elegir = toupper(elegir);
        if (elegir != 'A' && elegir != 'B')
            printf("\nElegiste mal, vuelve a intentarlo.");
    }while (elegir != 'A' && elegir != 'B');

    if (elegir =='A')
        VamosA(pt_vec);
    else
        VamosB(pt_vec);

    printf("\n\n");
    system("pause");
    return 0;
}

void VamosA (char *pt_vec)
{
    int contador = 1, i = 0;

    while ( *(pt_vec + i ) !='\0')
    {
        if (*(pt_vec + i ) == ' ')
            contador++;
    i++;
    }
    printf("\n\nHay %d palabras.", contador);
}

void VamosB (char *pt_vec)
{
    int contador = 1, i = 0;

    if (*(pt_vec + i ) == ' ')
        contador = 0;
    while ( *(pt_vec + i ) !='\0')
    {
        if (*(pt_vec + i ) == ' ')
        {
            while (*(pt_vec + i ) == ' ')
            {
                i++;
            }
        if (*(pt_vec + i ) !='\0')
            contador++;
        }
        else
        {
            i++;
        }
    }
    printf("\n\nHay %d palabras.", contador);
}
