#include "main.h"

int main()
{
    char Matriz[50][52];
    int cantidad, vec_dni[50];
    int *pt_vec_dni;

    pt_vec_dni = vec_dni;

    cantidad = Cargar(Matriz, pt_vec_dni);

    Mostrar(Matriz, pt_vec_dni, cantidad);

    printf("\n\n");
    system("pause");
    return 0;
}
