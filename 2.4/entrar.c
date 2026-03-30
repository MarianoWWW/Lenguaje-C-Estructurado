#include "main.h"

int Entrar(t_cliente *cliente, int contador)

{
    int cli, i = 0;

        cli = Limite(MINIMO, MAXIMO);
        while (i < contador)
        {
            if (((cliente+i)->codigo == cli+1 || (cliente+i)->codigo == cli-1) && cli != 999)
            {
                printf ("\n\nError, numero de cliente correlativo, debera elegir de nuevo.");
                return -1;
            }
            else
                i++;
        }
    return cli;
}
