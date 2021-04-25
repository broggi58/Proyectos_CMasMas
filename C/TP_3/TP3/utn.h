#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include "string.h"


/** \brief Checks if a string contains a numeric value
 *
 * \param string char*
 * \return int [1] if it has , [0] if not or [-1] if string is NULL
 *
 */
int isDigit(char* string);

/** \brief Checks if a string contains a letter
 *
 * \param string char*
 * \return int [1] if it has , [0] if not or [-1] if string is NULL
 *
 */
int isAlpha(char* string);

/** \brief Gets a char variable introduced by the user
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo char
 * \param maximo char
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos);

/** \brief Gets an integer number variable introduced by the user
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

/** \brief Gets a float number introduced by the user
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos);

/** \brief Gets a string introduced by the user
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimoCaracteres int
 * \param maximoCaracteres int
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

/** \brief Gets a character introduced by the user between 'm' for male, or 'f' for female
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param uno char
 * \param dos char
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getCaracterSex(char* pResultado,char* mensaje, char* mensajeError, char uno,char dos,int reintentos);

/** \brief Gets a string introduced by the user regarding that no numeric values are contained in it
 *
 * \param pResultado[] char
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimoCaracteres int
 * \param maximoCaracteres int
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getStringName(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

/** \brief Gets a string introduced by the user regarding that it only conteins numeric values
 *
 * \param pResultado[] char
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimoCaracteres int
 * \param maximoCaracteres int
 * \param reintentos int
 * \return int [0] if success or [-1] if failure
 *
 */
int utn_getStringNumber(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);
#include "utn.c"
#endif // UTN_H_INCLUDED

