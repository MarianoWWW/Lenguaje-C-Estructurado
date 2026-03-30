#include "main.h"

int main()
{
    float Matriz[TAM][COL] = {{0}};
    int cantidad, vec_cod_empresa[TAM];
    char vec_tipo_servicio[TAM];
    int *pt_vec_cod_empresa;
    char *pt_vec_tipo_servicio;

    pt_vec_cod_empresa = vec_cod_empresa;
    pt_vec_tipo_servicio = vec_tipo_servicio;

    cantidad = CargaEmpresas(pt_vec_cod_empresa, pt_vec_tipo_servicio);
    Facturacion(pt_vec_cod_empresa, Matriz, cantidad);


    Mostrar (pt_vec_cod_empresa, Matriz, cantidad, pt_vec_tipo_servicio);

    printf("\n\n");
    system("pause");
    return 0;
}
