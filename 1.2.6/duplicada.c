#include "main.h"

int Duplicada(char escondida[TAM+10], char letra)
{
    int i = 0;
    while (escondida[i] != '\0')
    {
        if (escondida[i] == letra)
            return 0;
        else
            i++;
    }
return 1;
}
