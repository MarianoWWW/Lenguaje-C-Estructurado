#include "main.h"

void INGRESO(t_medicamento *medicamento)

{
    int i, cod, repe, canti;
    double prec;

    printf("\n\nVamos a ingresar los datos referentes a los medicamentos.");
    for (i = 0 ; i < TAM ; i++)
    {
    do
    {
        printf("\n\nIngrese el codigo del medicamento numero %d/50 (3 cifras) : ", i+1);
        cod = Code(MIN, MAX);
        repe = Repetido(medicamento, cod, i);
        if (repe != -1)
            printf ("\n\nError, codigo ya ingresado, intente nuevamente.");
    }while (repe != -1);

    do
    {
        printf("\n\nIngrese el precio del medicamento que tiene por codigo el %d :", cod);
        fflush(stdin);
        scanf ("%lf", &prec);
        if (prec <= 0)
            printf ("\n\nError, el precio es negativo o cero, intente nuevamente.");
    }while (prec <= 0);

    do
    {
        printf("\n\nIngrese el stock del medicamento que tiene por codigo el %d :", cod);
        fflush(stdin);
        scanf ("%d", &canti);
        if (canti < 0)
            printf ("\n\nError, la cantidad es negativa, intente nuevamente.");
    }while (canti < 0);

    (medicamento+i)->codigo = cod;
    (medicamento+i)->precio = prec;
    (medicamento+i)->stock = canti;

    }

}
