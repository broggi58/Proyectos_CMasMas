#ifndef ARRAYMASCOTAS_H_INCLUDED
#define ARRAYMASCOTAS_H_INCLUDED
#include "arrayRazas.h"
#include "pais.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    int idTipo;
    int idRaza;
    float peso;
    int isEmpty;

}eMascota;

typedef struct
{
    char descripcion[20];
    int idTipo;
}eTipo;

int initMascotas(eMascota list[], int len);

void HardcodearTipos (eTipo tipos[]);

void HardcodearMascotas (eMascota mascotas[]);

int BuscarTipo(eTipo tipos [],int tamTipos, int idTipo);

void MostrarMascota(int id,char* nombre,char sexo,int edad,char* descripcionTipo,char* descripcionRaza,float peso,char* pais,int codigoTel );

void MostrarMascotas(eMascota mascotas[],int tamMascotas, eTipo tipos[],int tamTipos, eRaza razas[],int tamRazas, eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPais);

int BuscarLibre(eMascota mascotas[],int tam);

int AgregarMascota(eMascota mascotas[], int tam, int id, char nombre[],char
sexo,int edad,int idTipo,int idRaza,float peso);

int CrearMascota(eMascota mascotas[],int TAM,int id,eRaza razas[],int tamRazas,eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes);

int EncontrarMascotaPorId(eMascota mascota[], int tam,int id);

int RemoverMascota(eMascota mascota[], int tam, int id);

void MostrarOpciones();

void MostrarOpcionesParaModificar();

int ModificarMenu();

int ModificarMascota(eMascota mascota[],int tam,int id,eRaza razas[],int tamRazas,eTamanio tamanio[],int tamTamanio);

int menu();

void EliminarMascotaPorRaza (eMascota mascotas[],int tamMascota,int idRaza);
#include "arrayMascotas.c"

#endif // ARRAYMASCOTAS_H_INCLUDED
