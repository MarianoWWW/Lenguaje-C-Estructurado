#include "funciones.h"

int Carga(t_productos *productos)

{
    FILE * arch=fopen(PRO,"rb");

    if (arch == NULL)
    {
        exit(1);
    }
    int i = 0;

    while(fread((productos+i), sizeof(t_productos),1, arch) == 1)
    i++;

    fclose(arch);

    return i;
}

void Procesar_ventas(t_productos *productos,int cant)

{
    FILE *arch1=fopen("ventas.dat","rb");
    FILE *arch2=fopen("pedidos.dat","wb");
    FILE *arch3=fopen(PRO,"wb");

    if (arch1 == NULL || arch2 == NULL)
    {
        exit(1);
    }

    t_ventas ventas;
    t_pedidos pedidos;
    float imp_total = 0, recaudacion_total = 0;
    char suc_igual[16], suc_mayor[16];
    int i, max = 0, mayor_cant_prod = 0;

    fread(&ventas, sizeof(t_ventas),1, arch1);
    while (!feof(arch1))
    {
        strcpy(suc_igual, ventas.sucursal);
        do
        {
            for (i = 0 ; i < cant ; i++)
            {
                if (ventas.codigo_producto == (productos+i)->cod_prod)
                {
                    imp_total =imp_total + ((productos+i)->precio) * ventas.cantidad;
                    (productos+i)->stock =((productos+i)->stock) - ventas.cantidad;
                    break;
                }
            }
            mayor_cant_prod = mayor_cant_prod + ventas.cantidad;



            fread(&ventas, sizeof(t_ventas),1, arch1);
        }while (!(strcmp(suc_igual, ventas.sucursal)) && (!feof(arch1)));
        if (mayor_cant_prod > max)
        {
            max = mayor_cant_prod;
            strcpy(suc_mayor, suc_igual);
        }
        printf("\nLas ventas totales de la sucursal %s fueron $ %.2f", suc_igual, imp_total);
        recaudacion_total = recaudacion_total + imp_total;
        imp_total = 0;
        mayor_cant_prod = 0;
    }
    printf("\n\nRecaudacion total de la empresa en el mes $ %.2f", recaudacion_total);
    printf("\n\nSucursal que vendio la mayor cantidad de productos : %d fue %s.", max, suc_mayor);
    for (i = 0 ;  i < cant ; i++)
    {
        if (((productos+i)->stock) < ((productos+i)->punto_de_pedido)) //
        {
            pedidos.cod_producto = (productos+i)->cod_prod;
            pedidos.cant = (productos+i)->cantidad_para_pedido;
            fwrite(&pedidos, sizeof(t_pedidos), 1, arch2);
        }
    }
    for (i = 0 ;  i < cant ; i++)
        fwrite((productos+i), sizeof(t_productos),1, arch3);


    fclose(arch1);
    fclose(arch2);
    fclose(arch3);

}
