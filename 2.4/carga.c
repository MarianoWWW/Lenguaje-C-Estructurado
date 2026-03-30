#include "main.h"

int CARGA_CLIENTE(t_cliente *cliente)

{
    int contador = 0, cli, dup;

    printf("\n\nTodo inicia con la carga de clientes (del 1000 al 9999).");

    do
    {
        do
        {
            printf("\n\nIngrese el numero de cliente (4 digitos, clientes no correlativos, o 999 para terminar) : ");

            cli = Entrar(cliente, contador);
            dup = Duplicado(cliente, cli, contador);
            if (dup != -1)
            {
                printf("\n\nNumero de cliente ya ingresado, intente nuevamente.");
            }
        }while (cli == -1 || dup != -1);


        if (cli != 999)
        {
            (cliente+contador)->codigo = cli;
            printf("\n\nIngrese Nombre y Apellido (50 caracteres maximo) : ");
            fflush(stdin);
            gets((cliente+contador)->NyA);
            contador ++;
        }
    }while (contador < TAM && cli != 999);
    return contador;
}
