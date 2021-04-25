#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
/** \brief Gets a character introduced by the user
 *
 * \param pResultado char Pointer to where the char is saved
 * \param mensaje char Message to be shown to the user before the entry
 * \param mensajeError Message to be shown if the user enters an invalid value
 * \param minimo char Minimum value the entry can be
 * \param maximo char Maximum value the entry can be
 * \param reintentos int Number of retries the user has
 * \return (-1) if out of retries or (0) if Ok
 *
 */

int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos);
/** \brief Gets an integer number introduced by the user
 *
 * \param pResultado int Pointer to where the number is saved
 * \param mensaje char Message to be shown to the user before the entry
 * \param mensajeError Message to be shown if the user enters an invalid value
 * \param minimo int Minimum value the entry can be
 * \param maximo int Maximum value the entry can be
 * \param reintentos int Number of retries the user has
 * \return (-1) if out of retries or (0) if Ok
 *
 */
int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);
/** \brief Gets a character introduced by the user
 *
 * \param pResultado float Pointer to where the char is saved
 * \param mensaje char Message to be shown to the user before the entry
 * \param mensajeError Message to be shown if the user enters an invalid value
 * \param minimo float Minimum value the entry can be
 * \param maximo float Maximum value the entry can be
 * \param reintentos int Number of retries the user has
 * \return (-1) if out of retries or (0) if Ok
 *
 */
int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos);
/** \brief Gets a character introduced by the user
 *
 * \param pResultado char Pointer to where the char is saved
 * \param mensaje char Message to be shown to the user before the entry
 * \param mensajeError Message to be shown if the user enters an invalid value
 * \param minimoCaracteres char Minimum amount of characters the string can have
 * \param maximoCaracteres char Maximum amount of characters the string can have
 * \param reintentos int Number of retries the user has
 * \return (-1) if out of retries or (0) if Ok
 *
 */
int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

#include "utn.c"

#endif // UTN_H_INCLUDED
