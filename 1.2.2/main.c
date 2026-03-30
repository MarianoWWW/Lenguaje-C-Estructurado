#include "main.h"
int main()
{
    char vec_nombre[42], vec_apellido[42], vec_todo[81], en_medio[3] = ", ";
    char *pt_vec_nombre, *pt_vec_apellido, *pt_vec_todo;

    pt_vec_nombre = vec_nombre;
    pt_vec_apellido = vec_apellido;
    pt_vec_todo = vec_todo;

    do
    {
        printf("\n\nIngresa el Nombre (Maximo 40 caracteres) : ");
        fgets(pt_vec_nombre,42,stdin);
        if ( strlen(pt_vec_nombre) > 40)
            printf ("\n\nError, te pasaste de los 40 caracteres, intenta nuevamente.");
    }while (strlen(pt_vec_nombre) > 40);
     Enter(pt_vec_nombre);
    do
    {
        printf("\n\nIngresa el Apellido (Maximo 40 caracteres) : ");
        fgets(pt_vec_apellido,42,stdin);
        if ( strlen(pt_vec_apellido) > 40)
            printf ("\n\nError, te pasaste de los 40 caracteres, intenta nuevamente.");
    }while (strlen(pt_vec_apellido) > 40);
    Enter(pt_vec_apellido);

    strcpy(pt_vec_todo, pt_vec_nombre);
    strcat(pt_vec_todo, en_medio);
    strcat(pt_vec_todo, pt_vec_apellido);

    printf("\n\n");
    puts(pt_vec_todo);

    printf("\n\n");
    system("pause");
    return 0;
}
