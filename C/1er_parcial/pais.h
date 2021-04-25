#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include "arrayMascotas.h"
#include "arrayRazas.h"
typedef struct
{
    char nombreDePais[20];
    int idContinente;
    int CodigoTelefonico;
    int idPais;
}ePais;

typedef struct
{
    int idContinente;
    char descripcion[20];
}eContinente;

void HardcodearPaises(ePais paises[],int tamPaises);

void HardcodearContinentes(eContinente continentes[],int tamContinentes);

void MostrarPaises(ePais paises[],int tamPaises,eContinente continentes[], int tamContinentes);

int BuscarPais(ePais paises [],int tamPaises, int idPais);

int BuscarContinente(eContinente continentes [],int tamContinentes, int idContinente);

#include "pais.c"


#endif // PAIS_H_INCLUDED
