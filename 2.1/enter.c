#include "main.h"

void Enter (char *codigo)
{
    while (*codigo != '\0')
    {
        if (*codigo == '\n')
            {
            *codigo = '\0';
            return;
            }
        else
            codigo++;
    }
}
