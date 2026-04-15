#include "funciones.h"

int fecha_valida(t_fecha *fecha)

{
    if(fecha->anio >= 1900)
        if(fecha->mes >=1 && fecha->mes <= 12)
            if(fecha->dia >=1 && fecha->dia <= cant_dias_mes(&fecha->mes, &fecha->anio))
            return 1;
    return 0;
}
int cant_dias_mes(int *m, int *a)

{
    int dm[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (*m == 2 && bisiesto(a))
        return 29;
    return dm[*m];
}

int bisiesto(int *anio)

{
    return (*anio % 4 == 0 && (*anio % 100 !=0 || *anio % 400 == 0));
}
