#include "main.h"

void Mostrar(char Matriz[][COL], int *vec_cant_dias, float *vec_alquiler_precio_diario, int cantidad, int dia, int mes, int anio, float cotiza)
{
    struct tm fecha_devolucion;

    int i;
    float porcentaje, total = 0;


    system("cls");
    if(cantidad != 0)
    {

    porcentaje = ((float)cantidad / 30) * 100;



    printf("\n\nPorcentaje de autos alquilados durante el dia : %.2f", porcentaje);

    printf("\n\n\t\t\tALQUILER DE AUTOS DEL DIA: %d-%d-%d", dia, mes, anio);
    printf("\n\t\t\t\tCOTIZACION DEL DOLAR: $ %.2f", cotiza);
    printf("\n\nNRO. DE AUTO\t\tDIAS DE ALQUILER\tPRECIO DEL ALQUILER\tFECHA DE DEVOLUCION");
    printf("\n\t\t\t\t\t\t\tEN PESOS\t\tDEL AUTO");

    mktime(&fecha_devolucion);

    for (i = 0 ; i < TAM ; i++)
    {
        if (*(vec_cant_dias+i) > 0)
            {
            total = total + *(vec_alquiler_precio_diario+i) * (*(vec_cant_dias+i));
            fecha_devolucion.tm_mday = dia + *(vec_cant_dias+i);
            fecha_devolucion.tm_mon  = mes - 1;
            fecha_devolucion.tm_year = anio - 1900;
            fecha_devolucion.tm_hour = 0;
            fecha_devolucion.tm_min  = 0;
            fecha_devolucion.tm_sec  = 0;
            fecha_devolucion.tm_isdst = -1;

            mktime(&fecha_devolucion);

            printf("\n%s\t\t\t%d\t\t\t\t%.2f\t\t\t%d/%d/%d",
                Matriz[i],
                *(vec_cant_dias+i),
                (*(vec_alquiler_precio_diario+i))*cotiza,
                fecha_devolucion.tm_mday,
                fecha_devolucion.tm_mon + 1,
                fecha_devolucion.tm_year + 1900
                );
            }
    }
      printf("\n\nTOTAL RECAUDADO X ALQUILER (EN PESOS)\t\t$ %.2f", cotiza * total);
      printf("\n\nTOTAL RECAUDADO X ALQUILER (EN DOLARES)\t\t$ %.2f", total);
    }
    else
        printf("\nNO SE INGRESARON DATOS.");


}
