#include "main.h"

void INFORME(t_cliente *cliente,t_venta *venta,int cantidad_clientes,int cantidad_ventas)

{
    t_cliente aux_cliente;
    double aux, total_facturado[TAM] = {0};
    int i, j, cant_ventas_cli = 0, cant_ventas_vendedor = 0;

    system("cls");

    for ( i = 0 ; i < cantidad_clientes ; i++)
        {
            for ( j = 0 ; j < cantidad_ventas ; j++)
                {
                    if ((cliente+i)->codigo == (venta+j)->cod)
                        cant_ventas_cli ++;
                }
            if (cant_ventas_cli != 0)
                printf("\nLa cantidad de ventas al cliente %d es de %d .", (cliente+i)->codigo, cant_ventas_cli);
            cant_ventas_cli = 0;
        }
    printf("\n");

    for ( i = 1 ; i <= 10 ; i++)
        {
            for ( j = 0 ; j < cantidad_ventas ; j++)
                {
                    if (i == (venta+j)->num_vendedor)
                        cant_ventas_vendedor ++;
                }
            if (cant_ventas_vendedor != 0)
                printf("\nLa cantidad de ventas del vendedor %d es de %d .", i, cant_ventas_vendedor);
            cant_ventas_vendedor = 0;
        }
    printf("\n%-20s%-52s%s", "CODIGO DE CLIENTE", "NOMBRE Y APELLIDO", "TOTAL FACTURADO");
    //printf("\n\nCODIGO DE CLIENTE\tNOMBRE Y APELLIDO\tTOTAL FACTURADO");

    for ( i = 0 ; i < cantidad_clientes ; i++)
        {
            for ( j = 0 ; j < cantidad_ventas ; j++)
                {
                    if ((cliente+i)->codigo == (venta+j)->cod)
                        total_facturado[i] = total_facturado[i] + (venta+j)->importe;
                }
        }
    for ( i = 0 ; i < cantidad_clientes-1 ; i++)
        {
            for ( j = 0 ; j < cantidad_clientes-1-i ; j++)
                {
                    if (total_facturado[j] < total_facturado[j+1])
                    {
                        aux = total_facturado[j];
                        total_facturado[j] = total_facturado[j+1];
                        total_facturado[j+1] = aux;
                        aux_cliente = cliente[j];
                        cliente[j] = cliente[j+1];
                        cliente[j+1] = aux_cliente;
                    }
                }
        }
    for ( i = 0 ; i < cantidad_clientes ; i++)
        {
            if (total_facturado[i] != 0)
            printf("\n%-20d%-52s$ %.2f", (cliente+i)->codigo, (cliente+i)->NyA, total_facturado[i]);
            //printf("\n\t%d\t\t%s\t$ %.2f", (cliente+i)->codigo, (cliente+i)->NyA, total_facturado[i]);
        }

}
