#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define TAM 10

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    int idTipo;
    int idRaza;
    int isEmpty;

}eMascota;

typedef struct
{
    char descripcion[20];
    int idTam;
    int idRaza;
    char pais[20];
}eRaza;

typedef struct
{
    char descripcion[20];
    int idTipo;
}eTipo;

typedef struct
{
    char descripcion[20];
    int idTam;
}eTamanio;

int initMascotas(eMascota list[], int len)
{
    int retorno;
    int i;
    retorno=-1;
    if(list!=NULL || len!=10)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }
 return retorno;
}
void HardcodearTipos (eTipo tipos[])
{
    int i;
    eTipo buffer[3]= {{"perro",1},{"gato",2},{"raro",3}};

    for(i=0;i<3;i++)
    {
        tipos[i]=buffer[i];
    }
}
void HardcodearTamanios (eTamanio tamanio[])
{
    int i;
    eTamanio buffer[3]= {{"chico",1},{"mediano",2},{"grande",3}};

    for(i=0;i<3;i++)
    {
        tamanio[i]=buffer[i];
    }
}
void HardcodearRazas (eRaza razas[])
{
    int i;
    eRaza buffer[4]= {{"siames",1,1,"tailandia"},{"doberman",3,2,"alemania"},{"persa",2,3,"persia"},{"pastor belga",3,4,"belgica"}};

    for(i=0;i<4;i++)
    {
        razas[i]=buffer[i];
    }
}
void HardcodearMascotas (eMascota mascotas[])
{
    int i;
    eMascota buffer[5]= {{1000,"Felix",'m',3,2,1,0},{1001,"Claudia",'f',4,1,2,0},{1002,"Sergio",'m',3,2,3,0},{1003,"Gabriel",'f',5,1,4,0},{1004,"Pipa",'f',4,2,4,0}};

    for(i=0;i<5;i++)
    {
        mascotas[i]=buffer[i];
    }
}
int BuscarRaza(eRaza razas [],int tamRazas, int idRaza)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamRazas;i++)
    {
        if( razas[i].idRaza== idRaza)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int BuscarTipo(eTipo tipos [],int tamTipos, int idTipo)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamTipos;i++)
    {
        if( tipos[i].idTipo== idTipo)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int BuscarTamanio(eTamanio tamanios [],int tamTamanios, int idTamanio)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamTamanios;i++)
    {
        if( tamanios[i].idTam== idTamanio)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
void ImprimirMascotas(eMascota mascotas[],int tamMascotas, eTipo tipos[],int tamTipos, eRaza razas[],int tamRazas, eTamanio tamanios[],int tamTamanios)
{
    int r;
    int t;
    int i;
    for(i=0;i<tamMascotas;i++)
    {
        if(mascotas[i].isEmpty==0)
        {
            r=BuscarRaza(razas,tamRazas,mascotas[i].idRaza);
            t=BuscarTipo(tipos,tamTipos,mascotas[i].idTipo);
            printf("%d %10s %c %d %10s %10s %10s\n" ,mascotas[i].id,mascotas[i].nombre,mascotas[i].sexo,mascotas[i].edad,tipos[t].descripcion,razas[r].descripcion,razas[r].pais);
        }

    }
}

int main()
{

    eMascota mascotas[TAM];
    eTipo tipos[3];
    eTamanio tamanios[3];
    eRaza razas[4];
    initMascotas(mascotas,TAM);
    HardcodearTipos(tipos);
    HardcodearTamanios(tamanios);
    HardcodearRazas(razas);
    HardcodearMascotas(mascotas);

    ImprimirMascotas(mascotas,TAM,tipos,3,razas,4,tamanios,3);







    return 0;
}
