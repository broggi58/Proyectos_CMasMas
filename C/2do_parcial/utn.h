#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include "string.h"
#include "Controller.h"

int isDigit(char* string);

int isAlpha(char* string);

int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos);

int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos);

int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

int utn_getCaracterSex(char* pResultado,char* mensaje, char* mensajeError, char uno,char dos,int reintentos);

int utn_getStringName(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

int utn_getStringNumber(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);
#include "utn.c"

#endif // UTN_H_INCLUDED
