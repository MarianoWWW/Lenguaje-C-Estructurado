#include "funciones.h"

int main()
{
    t_productos *productos = malloc(200*sizeof(t_productos));

    int cant;

    cant = Carga(productos);
    productos = realloc(productos, cant*sizeof(t_productos));

    Procesar_ventas(productos, cant);

    free(productos);
    printf("\n\n");
    system("pause");
    return 0;
}
