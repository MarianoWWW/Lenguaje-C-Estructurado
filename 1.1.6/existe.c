int Existe (int *pt_vec_cod_empresa, int cod, int contador)
{
    int i = 0, hay = -1;

    while (i < contador && hay == -1)
    {
        if (*(pt_vec_cod_empresa + i ) == cod)
        {
            hay = i;
        }
        else
            i++;
    }
    return hay;
}
