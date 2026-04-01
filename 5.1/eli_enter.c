#include "main.h"

void Eli_enter(char *desc)

{
    while (*desc != '\0')
        {
            if (*desc == '\n')
                *desc = '\0';
            else
                desc++;
        }
}
