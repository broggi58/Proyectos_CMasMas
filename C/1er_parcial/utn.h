#ifndef UTN_H_INCLUDED

#define UTN_H_INCLUDED

int isDigit(char* string);

int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos);

int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos);

int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

#include "utn.c"
#endif // UTN_H_INCLUDED
