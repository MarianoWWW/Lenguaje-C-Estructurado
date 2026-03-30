#include "main.h"

int main()
{
    //Por lo que entiendo, voy a simular la memoria principal con una Funcion.
    char Matriz[TAM][COL];
    int cantidad, vec_cant_dias[TAM] = {0};
    float cotiza, vec_alquiler_precio_diario[TAM];


    time_t hoy = time(NULL);
    struct tm *fecha = localtime(&hoy);

    int dia = fecha->tm_mday;
    int mes = fecha->tm_mon + 1;
    int anio = fecha->tm_year + 1900;



    Mem(Matriz);

    printf("\nAhora ingrese la cotizacion del dolar $ : ");
    scanf("%f", &cotiza);

    cantidad = Alquiler(Matriz, vec_cant_dias, vec_alquiler_precio_diario);

    Mostrar(Matriz, vec_cant_dias, vec_alquiler_precio_diario, cantidad, dia, mes, anio, cotiza);

    printf("\n\n");
    system("pause");

    return 0;
}
