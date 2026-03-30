#include "main.h"

int Ingreso(t_alumno *alumno)
{
    int contador = 0, dni_alumno, i = 0, pos = -1;

    printf("\n\nHora de cargar los datos referentes a los alumnos.");

       do
       {
           printf("\n\nIngrese el numero de DNI del alumno (cero para terminar la carga) : ");

           dni_alumno = Carga_Numeros(BAJO, 99999999);

               if (dni_alumno != 0)
               {
                   while (i < contador && pos == -1)
                   {
                       if ((alumno+i)->dni == dni_alumno)
                       {
                           printf("\n\nError, ese DNI ya fue cargado en la base de datos, intente nuevamente.");
                           pos = i;
                       }
                       else
                        i++;
                   }
                   i = 0;
                   if (pos != -1)
                        pos = -1;
                    else
                    {
                        (alumno+contador)->dni = dni_alumno;

                        printf("\n\nIngrese el Apellido y Nombre del alumno cuyo DNI es %d : ", dni_alumno);
                        fflush(stdin);
                        gets ((alumno+contador)->vec_Ape_Nom);

                        printf("\n\nIngrese la primer nota de %s : ", (alumno+contador)->vec_Ape_Nom);
                        (alumno+contador)->notas.nota1 = Carga_Numeros(BAJO, ALTO);
                        printf("\n\nIngrese la segunda nota de %s : ", (alumno+contador)->vec_Ape_Nom);
                        (alumno+contador)->notas.nota2 = Carga_Numeros(BAJO, ALTO);

                        (alumno+contador)->promedio = (((float)(alumno+contador)->notas.nota1) +
                                                        ((alumno+contador)->notas.nota2)) / 2;
                        contador++;
                    }

               }

   }while (contador < TAM && dni_alumno != 0);

    return contador;
}
