#include <stdio.h>
#include <stdlib.h>
#include "string.h"
/*
    Se hace una funcion menu para mostrar las opciones, y otra funcion para cada operacion, a la que se accede desde el main
    a traves del retorno de la funcion menu.
*/



int menu();
int cargarvector(int vector[]);
void mostrarvector(int vector[]);


int main()
{
    int vector[29],salir=1;
    while(salir)
    {
        switch(menu())
        {
            case 1:
                cargarvector(vector);
                printf("El vector fue cargado breeoooooo\n");
                break;
            case 2:
                mostrarvector(vector);
                printf ("Pulse una tecla para continuar...\n");
                getchar();
                break;
            case 3:
                salir=0;
                printf ("Pulse una tecla para salir...");
                getchar();


        }

    }

    return 0;
}
//Pide al usuario un entero del 1 al 3,que lo ingrese por teclado.  Se guarda la opcion en una
//variable entera y se retorna su valor para ser utilizada en la iteracion de la funcion main.
int menu()
{
    int opcion;
    system("cls");
    do{
    printf("ELegi una opcion dog\n1- Ingresar datos\n2- Mostrar\n3- Salir ndeaaaaah\n");
    scanf("%d",&opcion);}while (opcion <0 || opcion >3);
    return opcion;


}
//Se carga el valor con un nombre y 30 numeros ingresados por teclado. Se retorna 0 pero se podria no retornar nada.
int cargarvector(int vector[])
{
    printf("Introduzca 30 nums plz\n");
    for (int i=0;i<=29;i++)
    {
        fflush(stdin);
        scanf("%d",&vector[i]);
    }
    return 0;
}

// Se imprine todos los valores cargados en el array en orden. No se retorna nada.
void mostrarvector(int vector[])
{
    for(int i=0;i<=29;i++)
    {
        printf("%d\n",vector[i]);
    }
}
