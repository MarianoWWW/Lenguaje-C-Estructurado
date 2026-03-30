#include "main.h"

void Mostrar (int *pt_vec_cod_empresa, float Matriz[][COL], int cantidad, char *pt_vec_tipo_servicio)

{
    int doble = 0;
    float aux, max, vec_max_facturacion[4] = {0}, vec_total_tipo[3] = {0};
    float *pt_vec_max_facturacion, *pt_vec_total_tipo;
    char aux_char, vec_tipo[3] ={'L', 'A', 'G'};
    char *pt_vec_tipo;

    pt_vec_tipo = vec_tipo;
    pt_vec_max_facturacion = vec_max_facturacion;
    pt_vec_total_tipo = vec_total_tipo;

    system("cls");
    if (cantidad == 0)
    {
        printf("\n\nNO SE CARGARON DATOS.");
    }
    else
    {
        int h = 0, i,j, contador = 0;
        printf("Empresa/Mes\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");

        for (i = 0 ; i < cantidad ; i++)
        {
            printf("\n%d\t", *(pt_vec_cod_empresa + i));
            for (j = 0 ; j < COL ; j++)
            {
                printf ("\t%.2f", Matriz[i][j]);
            }
        }
        for (j = 0 ; j < COL ; j++)
        {
            switch (contador)
            {
            case 3: h = 1;
            break;
            case 6: h = 2;
            break;
            case 9: h = 3;
            break;
            }

            for (i = 0 ; i < cantidad ; i++)
            {
                *(pt_vec_max_facturacion+h) = *(pt_vec_max_facturacion+h) + Matriz [i][j];
            }
            contador ++;
        }
        max = *pt_vec_max_facturacion;
        for (i = 1 ; i < 4 ; i++)
        {
            if (*(pt_vec_max_facturacion + i) > max)
                max = *(pt_vec_max_facturacion + i);
        }
        printf ("\n\nEl/los trimestres de mayor facturacion : ");
        for (i = 0 ; i < 4 ; i++)
        {
            if (max == *(pt_vec_max_facturacion + i))
                printf ("%d", i+1);
        }
        printf (" . Con una facturacion de $ %.2f", max);

        for (i = 0 ; i < cantidad ; i++)
        {
            if (*(pt_vec_tipo_servicio +i) == 'L')
                {
                    for (j = 0 ; j < COL ; j++)
                    {
                        *(pt_vec_total_tipo) = *(pt_vec_total_tipo) + Matriz [i][j];
                    }
                }
                else
                {
                    if (*(pt_vec_tipo_servicio +i) == 'A')
                        {
                            for (j = 0 ; j < COL ; j++)
                            {
                                *(pt_vec_total_tipo + 1) = *(pt_vec_total_tipo + 1) + Matriz [i][j];
                            }
                        }
                        else
                        {
                            for (j = 0 ; j < COL ; j++)
                            {
                                *(pt_vec_total_tipo + 2) = *(pt_vec_total_tipo + 2) + Matriz [i][j];
                            }
                        }
                }
        }
        for (i = 0 ; i < 2 ; i++)
            {
                for (j = 0 ; j < 2 - i ; j++)
                {
                    if (*(pt_vec_total_tipo+j) < *(pt_vec_total_tipo+j+1))
                    {
                        aux = *(pt_vec_total_tipo+j);
                        aux_char = *(pt_vec_tipo +j);
                        *(pt_vec_total_tipo+j) = *(pt_vec_total_tipo+j+1);
                        *(pt_vec_tipo +j) = *(pt_vec_tipo +j+1);
                        *(pt_vec_total_tipo+j+1) = aux;
                        *(pt_vec_tipo +j+1) = aux_char;
                    }
                }
            }

        printf ("\n\nTipo\tTotal Facturado");
        for (i = 0 ; i < 2 ; i++)
            {
                printf ("\n%c\t%.2f", *(pt_vec_tipo + i), *(pt_vec_total_tipo+i));
            }
        printf("\n\nEmpresa/s que no hayan facturado en 2 o mas meses : ");
        j = 0;
        for (i = 0 ; i < cantidad ; i++)
            {
                while (doble < 2 && j < COL)
                {
                    if (Matriz [i][j] == 0)
                        doble++;
                }
                if (doble == 2)
                {
                    printf (" %d %c ,", *(pt_vec_cod_empresa+i), *(pt_vec_tipo_servicio+i));
                }
                j = 0;
                doble = 0;
            }
    }
}
