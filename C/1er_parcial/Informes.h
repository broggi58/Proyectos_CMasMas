#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void MostrarOpcionesInformes();

int InformesMenu();

void MostrarRazasConMascotas(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRaza,eTamanio tamanios[],int tamTamanio,eTipo tipos[],int tamTipo);

void OrdenarPorPeso(eMascota mascotas[],int tamMascota,int sentido);

int ObtenerRazaMasComun(eRaza razas[],int contRaza,eMascota mascotas[],int tamMascota);

void MostrarPaisMasComun(ePais paises[],int tamPaises ,int indice);

void Informes (eMascota mascotas[],int tam,eTamanio tamanios[],int tamTamanios,eTipo tipos[],int tamTipos,eRaza razas[],int tamRazas,ePais paises[],int tamPaises,eContinente continentes[], int tamContinentes);

int ObtenerPaisMasComun(eRaza razas[],int contRaza,eMascota mascotas[],int tamMascota,ePais paises[],int tamPaises);

void OrdenarPorCodigoTelefonico (eMascota mascotas[],int tamMascotas,eRaza razas[],int tamRazas,ePais paises[],int tamPaises);

void CalcularPesoTotalPorTipo (eMascota mascotas[],int tamMascota,eTipo tipos[],int tamTipos,float PesosTotalesPorTipo[]);

void CalcularCantidadDeMascotasPorTipo (eMascota mascotas[],int tamMascota,eTipo tipos[],int tamTipos,int CantidadMascotasPorTipo[]);

void CalcularPromedioPesoPorTipo (float PesoTotalPorTipo[],int CantidadMascotasPorTipo[],float PromedioPesoPorTipo[],int tamTipos);

void MostrarTipos (eTipo tipos[], int tamTipos);

void MostrarPesoTotal (float PesoTotalPorTipo[],int tamTipos);

void MostrarPesoPromedio (float PromedioPesoPorTipo[],int cantidadMascotasPorTipo[],int tamTipos);

void MostrarPesoPorTipo (float PesoTotalPorTipo[],int CantidadMascotasPorTipo[],float PromedioPesoPorTipo[],eTipo tipos[],int tamTipos);

void MostrarMascotasPorTamanio(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRazas,int idTam,eTipo tipos[],int tamTipos,ePais paises[],int tamPaises);

float ObtenerPesoTotalPorTamanio(eMascota mascotas[],int tamMascota,eRaza razas[],int tamRazas,int idTam);

void OrdenarPorTipoyPeso(eMascota mascotas[],int tamMascota,int sentido);
#include "Informes.c"

#endif // INFORMES_H_INCLUDED
