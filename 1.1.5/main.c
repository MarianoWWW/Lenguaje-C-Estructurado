#include "main.h"

int main()
{
    int repetido, cod, contador = 0, vec_cod_libro[TAM], Matriz[TAM][COL] = {{0}};
    int *pt_repetido, *pt_cod, *pt_contador, *pt_vec_cod_libro;

    pt_repetido = &repetido;
    pt_cod = &cod;
    pt_contador = &contador;
    pt_vec_cod_libro = vec_cod_libro;

    CargaLibros (pt_vec_cod_libro, pt_contador, pt_cod, pt_repetido);
    CargaVentas (pt_vec_cod_libro, pt_contador, pt_cod, pt_repetido, Matriz);
    Mostrar (pt_vec_cod_libro, pt_contador, Matriz);

    printf("\n\n");
    system ("pause");

    return 0;
}
