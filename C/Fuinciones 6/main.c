#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char Nombre[100];
    int legajo;
    int nota;
}Ealumnos;


int main()
{
    Ealumnos alumnos[24];
    printf("Hello world!\n");
    return 0;
}
void Cargar_Datos(Ealumno alumnos[])
{
    for (int i=0;i<=24;i++)
    {
        printf("Igresar Nombre de alumno %d\n",i+1);
        gets(alumnos[i].nombre);
        printf("Ingresar legajo de alumno %d\n",i+1);
        fflush(stdin);
        scanf("%d",alumnos[i].legajo);
        printf("Ingresar nota alumno %d\n",i+1);
        printf("ALUMNO CARGADO\n");
    }
}
float Porcentaje_Aprobados(Ealumnos[] alumnos)
{
    int contador=0;
    float porcentaje;
    for(int i=0;i<=24;i++)
    {
        if(alumnos[i].nota >=7)
        {
            contador++;
        }
    }
    porcentaje =(float) contador /25 *100;
    return porcentaje;
}
void Mostrar_Aprobados(Ealumno[] alumnos)
{
    printf("Alumnos Aprobados\n");
    for(int i=0;i<=24;i++)
    {

        if (alumno[i].nota >=7)
        {
            printf("%s       ",alumno[i].nombre);
            printt("%d ",alumno[i].nota);
        }
    }
}
