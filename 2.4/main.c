#include "main.h"

int main()
{
    t_cliente cliente[TAM];

    t_venta venta[TAM*10] ={0}; //posibles combinaciones de clientes y vendedores

    int cantidad_clientes, cantidad_ventas;

    cantidad_clientes = CARGA_CLIENTE(cliente);

    if (cantidad_clientes != 0)
    {
         cantidad_ventas = VENTAS(cliente, venta, cantidad_clientes);
         INFORME(cliente, venta, cantidad_clientes, cantidad_ventas);

    }
    else
    {
        system("cls");
        printf("\n\nNo se cargaron datos.");
    }






    printf("\n\n");
    system("pause");
    return 0;
}
