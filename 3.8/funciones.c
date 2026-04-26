#include "funciones.h"

FILE * Archivos(char *path, char *modo)

{
    FILE *p=fopen(path, modo);
    if (p == NULL)
    {
        printf("\n\nError con el archivo.");
        system("pause");
        exit(1);
    }
    return p;
}

int Carga_inscriptos(FILE *arch, t_inscriptos *inscriptos)

{
    int i = 0;
    rewind(arch);
    while (fread(inscriptos, sizeof(t_inscriptos), 1, arch) == 1)
    {
        printf("%-10d%-25s%d\n", inscriptos->dni, inscriptos->ayn, inscriptos->pagado);
        inscriptos++;
        i++;
    }
    return i;
}
int Ingreso_dni(t_inscriptos *inscriptos, int cant, FILE * arch1)

{
    t_interesados interesado;
    char nombre[23] = {0};
    int pedir_dni, alumno_dni, paga, nuevo, desea, num = 0;

    do
    {
        do
        {
            printf("\n\nIngrese un DNI (un numero negativo para salir) por favor : ");
            scanf(" %d", &pedir_dni);
            if (pedir_dni < 0 )
                break;
            if (pedir_dni < 1000000 || pedir_dni > 99999999)
                printf("\n\nError, el DNI debe ser un numero entre 1.000.000 y 99.999.999");
        }while (pedir_dni < 1000000 || pedir_dni > 99999999);

        if (pedir_dni > 0)
        {
            alumno_dni = Buscar(inscriptos, cant, pedir_dni);
            if (alumno_dni != -1)
            {
                if ((inscriptos+alumno_dni)->pagado == 1)
                    printf("\n\nEl alumno ya esta inscripto y pago la cuota.");
                else
                {
                    printf("\n\nEl alumno ya esta inscripto, adeuda la cuota.");
                    printf("\nDesea pagar la cuota? (S/N) : ");
                    paga = Elegir();
                    if (paga == 1)
                    {
                        (inscriptos+alumno_dni)->pagado = 1;
                    }
                }
            }
            else
            {
                printf("\n\nEl alumno no esta en la base de datos. Desea anotarlo? (S/N) : ");
                nuevo = Elegir();
                if (nuevo == 1)
                {
                    if (cant < TAM)
                    {
                        nom_ape(nombre);

                        (inscriptos+cant)->dni = pedir_dni;
                        strcpy((inscriptos+cant)->ayn,nombre);
                        (inscriptos+cant)->pagado = 0;
                        cant++;
                    }
                    else
                    {
                        printf("\n\nYa no quedan cupos en el curso.");
                        printf("\n\nDesea quedar registrado para un curso futuro? S/N : ");
                        desea = Elegir();
                        if (desea == 1)
                        {
                            nom_ape(nombre);
                            do
                            {
                                printf("\n\nIngrese su numero telefonico : ");
                                scanf(" %d", &num);
                                if (num < 0 )
                                    printf("\n\nError no puede ser numero negativo.");
                            }while (num < 0 );
                            strcpy(interesado.ayn_interesado, nombre);
                            interesado.dni_interesado =  pedir_dni;
                            interesado.telefono = num;
                            fwrite(&interesado, sizeof(t_interesados), 1, arch1);
                        }
                    }
                }
            }
        }
    }while(pedir_dni > 0);
    return cant;
}

int Buscar(t_inscriptos *inscriptos, int cant, int pedir_dni)

{
    int i = 0;

    while (i < cant)
    {
        if (inscriptos->dni == pedir_dni)
        {
            return i;
        }
    i++;
    inscriptos++;
    }
    return -1;
}

int Elegir()

{
    char elige;
    do
    {
        scanf(" %c", &elige);
        elige = tolower(elige);
        if (elige != 's' && elige != 'n')
            printf("\n\nEleccion incorrecta, debe elegir entre S (si) o N (no) : ");
    }while (elige != 's' && elige != 'n');

    if (elige =='s')
        return 1;
    return 0;
}

void nom_ape(char *nombre)

{
    int i;
    do
        {
            printf("\n\nIngrese el Apellido y nombre del alumno (maximo 20 caracteres) : ");
            fflush(stdin);
            fgets(nombre, 23, stdin);
            i = 0;
            while (*(nombre+i) != '\0')
            {
                if (*(nombre+i) == '\n')
                    *(nombre+i) = '\0';
                else
                    i++;
            }
            if (strlen(nombre) > 20)
                printf("\n\nError, nombre y apellido muy largo, resuma.");


        }while(strlen(nombre) > 20);
}
