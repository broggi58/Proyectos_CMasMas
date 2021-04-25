#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctime>
/*
    Se declara una estructura incluyendo el nombre de un alumno y 30 de sus notas. Se generan en una funcion y en otra se
    muestra por pantalla el nombre del alumno y promedio total de sus notas.
*/
typedef struct
{
    char nombre[51];
    int notas[29];
}Ealumno;

void Generar_Notas(Ealumno alumno);
void Mostrar_Promedio(Ealumno alumno);

int main()
{
    srand(time(NULL));
    Ealumno alumno;
    strcpy(alumno.nombre,"Pipo Argenti");
    Generar_Notas(alumno);
    Mostrar_Promedio(alumno);

    return 0;
    snprintf(Ealumno alumno.nombre,sizeof(alumno.nombre),"Pipo Argenti");



}
//Genera notas al azar para el alumno entre 1 y 10.
void Generar_Notas(Ealumno alumno)
{
    for(int i=0;i<=29;i++)
    {
        alumno.notas[i]= (rand() %9 + 1);
    }
}
// Imprime el nombre del alumno y e promedio de sus notas.
void Mostrar_Promedio(Ealumno alumno)
{
    float promedio=0;
    printf("El nombre es %s",alumno.nombre);

    for (int i=0;i<=29;i++)
    {
        promedio+=alumno.notas[i];
    }
    printf("Promedio %.2f",promedio/30);
}


