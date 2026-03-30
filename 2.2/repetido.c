#include "main.h"

int Repetido(t_medicamento *medicamento, int cod, int cantidad)
{
    int i, pos = -1;

    for (i = 0; i < cantidad ; i++)
        {
            if ((medicamento+i)->codigo == cod)
                {
                    pos = i;
                    break;
                }
        }


    return pos;
}
