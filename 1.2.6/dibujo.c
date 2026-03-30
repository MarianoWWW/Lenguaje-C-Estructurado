#include "main.h"

void Dibujo(int vida)
{
    printf("\n\n\n\n\t\t\t+----------+");
    printf("\n\t\t\t|          |");

    if (vida < 5)
        printf("\n\t\t\t|          O");
    else
        PALO();
    if (vida < 4)
        {
        printf("\n\t\t\t|          |");

        }
    else
        {
        PALO();
        }
    if (vida < 3)
        {
        printf("\n\t\t\t|         /|\\");
        }
    else
        {
        PALO();
        }

     if (vida < 2)
        printf("\n\t\t\t|          |");
    else
        PALO();
    if (vida < 1)
        printf("\n\t\t\t|         / \\");
    else
        PALO();
    PALO();
    PALO();
    printf("\n\t\t  =====================");
    printf("\n\t\t=========================");
}
