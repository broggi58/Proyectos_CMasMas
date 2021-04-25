#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleados.h"

#define TAM 1000





int main()
{
    Employee lista[TAM];
    char salir = 'n';
    int flag=0;
    int id=1000;
    char name[51];
    char lastName[51];
    int sector;
    float salary;

    initEmployees(lista, TAM);


    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets( name );

            printf("Ingrese apellido:");
            fflush(stdin);
            gets( lastName );



            printf("Ingrese sector:");
            scanf("%d", &sector);

            printf("Ingrese salario:");
            scanf("%f", &salary);


            if (addEmployee(lista,TAM,id,name,lastName,salary,sector))
            {
                id++;
                flag++;
            }
            break;
        case 2:
            if (flag!=0)
            {
                modifyEmployee(lista, TAM);
            }
            else
            {
                printf("Error. No hay empleados cargados\n");
            }


            break;
        case 3:

            if (flag!=0)
            {
                removeEmployee(lista, TAM);
            }
            else
            {
                printf("Error. No hay empleados cargados\n");
            }

            break;
        case 4:

            if (flag!=0)
            {
                InformEmployee (lista,  TAM);
            }
            else
            {
                printf("Error. No hay empleados cargados\n");
            }


            break;

        case 5:
            printf("Corfirma Salida?");
            fflush(stdin);
            salir = getch();

            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}


