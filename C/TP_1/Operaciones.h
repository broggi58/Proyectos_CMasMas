#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Suma dos numeros.
 *
 * \param operandoA El primer sumando.
 * \param operandoB El segundo sumando.
 * \return La suma de ambos operandos.
 *
 */

float Sumar(float operandoA, float operandoB);

/** \brief Resta dos numeros.
 *
 * \param operandoA El minuendo de la operaci�n.
 * \param operandoB El sustraendo de la operaci�n.
 * \return La diferencia entre ambos.
 *
 */

float Restar(float operandoA, float operandoB);

/** \brief Multiplica dos numeros.
 *
 * \param operandoA El multiplicando de la operaci�n.
 * \param operandoB El multiplicador de la operaci�n.
 * \return El producto entre ambos.
 *
 */

float Multiplicar(float operandoA, float operandoB);

/** \brief Divide dos numeros.
 *
 * \param operandoA El dividendo de la operaci�n
 * \param operandoB El divisor de la operaci�n
 * \return El cociente entre ambos
 *
 */

float Dividir(float operandoA,float operandoB);

/** \brief Calcula el factorial de un numero
 *
 * \param num Numero a calcular su factorial
 * \return El factorial del numero
 *
 */

long long int CalcularFactorial(float num);

#include "Operaciones.c"
#endif // OPERACIONES_H_INCLUDED
