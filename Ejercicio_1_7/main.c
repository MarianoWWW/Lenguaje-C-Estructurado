#include "funciones.h"

int main()
{
    char cad[TAM+2];
    long long int cant, resultado;

    printf("\n\nPasar una cadena string con numeros a un numero int.");

    do
    {
        printf("\nIngrese los numeros enteros que desee transformar : ");
        fgets(cad, TAM+2, stdin);
        Enter(cad);
        cant = strlen(cad);
        if (cant > TAM)
            printf("\nError en la longitud de la cadena, intente nuevamente.");
    }while (cant > TAM);

    resultado=Pasar(cad, cant);

    printf("\n\nEl numero entero es : %lld", resultado);

    printf("\n\n");
    return 0;
}
