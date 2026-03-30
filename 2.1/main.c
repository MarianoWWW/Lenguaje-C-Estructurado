#include "main.h"

int main()
{
    char Matriz_codigo[TAM][COL] = {0};
    int cant, vec_cantidad_pedida[TAM];

    t_productos vec_productos[TAM] = {0};

    cant = Ingresa(vec_productos);

    if (cant)
    {
        if (Ventas(Matriz_codigo, vec_cantidad_pedida, vec_productos, cant))
            Resolver(vec_productos, Matriz_codigo, vec_cantidad_pedida, cant);
        else
            printf("\n\nNO SE INGRESARON LAS VENTAS DEL MES.");
    }
    else
        printf("\n\nNO SE INGRESARON DATOS.");


    printf("\n\n");
    system("pause");
    return 0;
}
