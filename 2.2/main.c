#include "main.h"

int main()
{
    int seleccion, elec =1;
    t_medicamento medicamento[TAM];

    INGRESO(medicamento);

    while (elec == 1)
    {
    do
    {
        system("cls");
        printf ("\n\nMenu :");
        printf ("\n\n1. Para consultar precio de medicamentos.");
        printf ("\n2. Para informar los medicamentos con stock menor a 10 unidades.");
        printf ("\n3. Salir.");
        printf ("\n\nIngrese su eleccion : ");
        fflush(stdin);
        scanf("%d", &seleccion);
        if (seleccion < 1 || seleccion > 3)
        {
            printf ("\n\nError. Debe decidir entre 1, 2 o 3.\n\n");
            system("pause");
        }

    }while (seleccion < 1 || seleccion > 3);

    switch (seleccion)
    {
        case 1: BUSQUEDA_MEDI(medicamento);
            break;
        case 2: INFORME(medicamento);
            break;
        default: elec = 0;
    }

    }



    printf ("\n\n");
    system("pause");
    return 0;
}
