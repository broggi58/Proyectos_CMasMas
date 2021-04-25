#ifndef CONCURSANTES_H_INCLUDED
#define CONCURSANTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int numerodeConcursante;
    int anioDeNacimiento;
    char nombre[50];
    char dni[8];
    eFecha fechaDePresentacion;
   // char fechaDePresentacion[10];
    char temaDePresentacion[30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    int puntajeTerceraRonda;
    float puntajePromedio;
}eConcursante;
int ListElement(eConcursante* concursante);

int eConcursantes_setnumeroConcursante(eConcursante* this,int numeroConcursante);

int eConcursante_getnumeroConcursante(eConcursante* this,int* numeroConcursante);

int eConcursante_setAnioDeNacimiento(eConcursante* this,int anioDeNacimiento);

int eConcursante_getAnioDeNacimiento(eConcursante* this,int* anioDeNacimiento);

int eConcursante_setnombre(eConcursante* this,char* nombre);

int eConcursante_getnombre(eConcursante* this,char* nombre);

int eConcursante_setdni(eConcursante* this,char* dni);

int eConcursante_getdni(eConcursante* this,char* dni);

int eConcursante_setfecha(eConcursante* this,eFecha fecha);


int eConcursante_getfecha(eConcursante* this,eFecha* fecha);

int calificarTerceraEtapa(eConcursante* concursante);


int eConcursante_setpuntajePrimeraRonda(eConcursante* this,int puntajePrimeraRonda);

int eConcursante_getpuntajePrimeraRonda(eConcursante* this,int* puntajePrimeraRonda);

int eConcursante_setpuntajeSegundaRonda(eConcursante* this,int puntajeSegundaRonda);

int eConcursante_getpuntajeSegundaRonda(eConcursante* this,int* puntajeSegundaRonda);

int eConcursante_setpuntajePromedio(eConcursante* this,float puntajePromedio);

int eConcursante_getpuntajePromedio(eConcursante* this,float* puntajePromedio);

int eConcursante_getpuntajeTerceraRonda(eConcursante* this,int* puntajeTerceraRonda);

int eConcursante_setpuntajeTerceraRonda(eConcursante* this,int puntajeTerceraRonda);

int calificarSegundaEtapa(eConcursante* concursante);

int guardarResultados (char* path,LinkedList* listaConcursantes);

int checkearConcursante (eConcursante* concursante);

int  ObtenerNotasMasAltas(LinkedList* listaConcursantes,int notasMaximas[]);

int FiltrarConcursante(eConcursante* concursante,int notasMaximas[]);

int FiltrarConcursanteTerceraRonda(eConcursante* concursante,int notaReferencia);

int  ObtenerNotasMasAltasEtapaTres(LinkedList* listaConcursantes,int notasMaximas[]);

int eConcursante_CompareByNotaPrimeraEtapa(eConcursante* c1, eConcursante* c2);

int eConcursante_CompareByNumeroConcursante(eConcursante* c1, eConcursante* c2);

int ObtenerNotaDeReferencia(LinkedList* listaConcursantes,int size);

int FiltrarConcursantes(eConcursante* concursante,int notaReferencia);

int eConcursante_CompareByNotaTerceraEtapa(eConcursante* c1, eConcursante* c2);

int Desempatar(LinkedList* this,int* size,int cantidad);



eConcursante* concursante_newParametros(char* numeroConcursanteString,char* anioDeNacimientoString,char* nombre,char* dni,char* FechaString,char* temaPresentacion,char* puntajePrimeraRondaString);
#include "Concursantes.c"
#endif // CONCURSANTES_H_INCLUDED
