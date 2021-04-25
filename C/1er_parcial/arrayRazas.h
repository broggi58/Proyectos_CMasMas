#ifndef ARRAYRAZAS_H_INCLUDED
#define ARRAYRAZAS_H_INCLUDED
#include "arrayMascotas.h"
#include "pais.h"
typedef struct
{
    char descripcion[20];
    int idTam;
    int idRaza;
    int idPais;
    int isEmpty;
}eRaza;

typedef struct
{
    char descripcion[20];
    int idTam;
}eTamanio;




int initRazas(eRaza list[], int len);

void HardcodearTamanios (eTamanio tamanio[]);

void HardcodearRazas (eRaza razas[]);

int BuscarRaza(eRaza razas [],int tamRazas, int idRaza);

int BuscarTamanio(eTamanio tamanios [],int tamTamanios, int idTamanio);

void MostrarRazas(eRaza razas[], int tamRazas,eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPaises,eContinente continentes[], int tamContinentes);

int BuscarRazaLibre(eRaza razas[],int tamRazas);

int AgregarRaza(eRaza razas[], int tamRaza, int idTam,int idPais,int idRaza,char descripcion[]);

int CrearRaza (eRaza razas[],int tamRazas,int idRaza,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes);

int RemoverRaza(eRaza razas[], int tamRaza, int idRaza);

void MostrarTamanios(eTamanio tamanios[],int tamTamanios);

int BuscarRazaPorTamanio(eRaza razas [],int tamRazas, int idTamanio);
#include "arrayRazas.c"



#endif // ARRAYRAZAS_H_INCLUDED
