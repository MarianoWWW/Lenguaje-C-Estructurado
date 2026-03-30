#include "main.h"

void BUSQUEDA_MEDI(t_medicamento *medicamento)

{
    int cod, pos;

    system("cls");
    printf ("\n\nPrecios de medicamentos.");
    do
    {
        printf ("\n\nIngrese el codigo del medicamento que desee saber su precio (3 cifras) : ");
        cod = Code(MIN, MAX);
        pos = Repetido(medicamento, cod, TAM);
        if (pos == -1)
            printf ("\n\nError, ese codigo de medicamento no existe en la base de datos, intente nuevamente.");
    }while (pos == -1);

    printf ("\n\nEl medicamento %d tiene un precio de $%.2lf\n\n", cod, (medicamento+pos)->precio);
    system("pause");
}
