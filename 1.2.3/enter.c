#include "main.h"

void Enter(char *vec)

{
    int i = 0;
    while (vec[i] != '\0')
    {
        if (vec[i] == '\n')
            vec[i] = '\0';
        else
            i++;
    }
}
