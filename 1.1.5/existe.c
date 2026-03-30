void Existe (int *pt_vec_cod_libro, int *pt_cod, int *pt_repetido, int *pt_contador)
{
    int i=0;
    *pt_repetido = -1;

    while (i < *pt_contador && *pt_repetido == -1)
    {
        if (*(pt_vec_cod_libro+i) == *pt_cod)
            *pt_repetido = i;
        else
            i++;

    }
}
