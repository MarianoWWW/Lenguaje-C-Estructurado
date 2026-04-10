#include "funciones.h"

int main()
{
    t_rating rat;
    t_promedio prom;
    FILE *arch = fopen("RATING.dat", "rb");
    FILE *arch1 = fopen("promedios.dat", "wb+");
    if (arch == NULL || arch1 == NULL)
    {
        exit(1);
    }
    int canal_igual, canal_max;
    float max = 0, puntos = 0, promedio_ = 0, cont_prom = 0;
    fread(&rat,sizeof(t_rating),1,arch);
    while (!feof(arch))
    {
        canal_igual = rat.num_canal;
        do
        {
            puntos = puntos + rat.rating;
            promedio_ = promedio_ + rat.rating;
            cont_prom++;
            fread(&rat,sizeof(t_rating),1,arch);
        }while((!feof (arch)) && (canal_igual == rat.num_canal));
        if (puntos < 15 )
        {
            printf("\n\nEl canal %d obtuvo menos de 15 puntos en total.", canal_igual);
        }
        prom.numero_canal = canal_igual;
        prom.promedio = (promedio_ / cont_prom);
        fwrite(&prom, sizeof(t_promedio),1, arch1);
        if (puntos > max)
        {
            max = puntos;
            canal_max = canal_igual;
        }
        puntos = 0;
        promedio_ = 0;
        cont_prom = 0;
    }

    printf("\n\nEl canal mas visto fue %d .", canal_max);

    Mostrar(arch1);

    fclose(arch);
    fclose(arch1);

    printf("\n\n");
    system("pause");
    return 0;
}
