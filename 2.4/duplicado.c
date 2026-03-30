#include "main.h"

int Duplicado(t_cliente *cliente, int cli, int contador)

{
    for (int i = 0 ; i< contador ; i++)
    {
        if ((cliente+i)->codigo == cli)
            return i;
    }
    return -1;
}
