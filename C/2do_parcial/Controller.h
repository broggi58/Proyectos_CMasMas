#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(LinkedList* listaConcursantes, int* flagParticipantes,char* path);

void PrintOptions();

int menu();

void PrintOptionsLoad();

int menuLoad();

int controller_listElements(LinkedList* listaConcursantes,int* flagParticipantes);

//int controller_evaluarParticipantes(LinkedList* listaConcursantes,int *flagHayConcursantes);

int controller_evaluarParticipantesSegundaFase(LinkedList* listaConcursantes,int *flagHayConcursantes,char* path,int* flagSegundaFase);

int controller_informar(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase);

int controller_guardarDatos(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase);

int controller_elegirFinalistas(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase);

int controller_controller_evaluarParticipantesEtapaTres(LinkedList* listaConcursantes,int* flagHayConcursantes,char path,int* flagSegundaFase);

#include "Controller.c"
#endif // CONTROLLER_H_INCLUDED
