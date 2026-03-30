#include "main.h"

void Enter(char vec_codigo[COL])
{
    int i = 0;
    while (vec_codigo[i] != '\0')
    {
        if (vec_codigo[i] == '\n')
            vec_codigo[i] = '\0';
        else
            i++;
    }
}
