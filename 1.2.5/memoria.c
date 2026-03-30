#include "main.h"

void Mem(char Matriz[][COL])
{
    char str[4];
    for (int i = 0 ; i < TAM ; i++)
    {
        strcpy(Matriz[i], "AAA");
        sprintf(str, "%d", i+100);
        strcat(Matriz[i], str);
    }
}
