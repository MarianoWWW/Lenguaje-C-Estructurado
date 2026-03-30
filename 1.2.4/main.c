#include "main.h"
int main()
{
    char Matriz[TAM][COL];
    float vec_precio[TAM];
    float *pt_vec_precio;
    int cantidad, vec_cant_unidades_vendidas[TAM] = {0};
    int *pt_vec_cant_unidades_vendidas;

    pt_vec_precio = vec_precio;
    pt_vec_cant_unidades_vendidas = vec_cant_unidades_vendidas;

    cantidad = CargaDatos(Matriz, pt_vec_precio);
    Ventas(Matriz, pt_vec_cant_unidades_vendidas, cantidad);
    Mostrar (Matriz, pt_vec_precio, pt_vec_cant_unidades_vendidas, cantidad);

    printf("\n\n");
    system("pause");
    return 0;
}
