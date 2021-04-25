#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Valida si el divisor de la operacion es 0 o no
 *
 * \param num Divisor a evaluar
 * \return 0 si la division no se puede hacer y 1 si se puede hacer.
 *
 */

int validarDivision(float num);

/** \brief Valida si el numero a sacar su factorial es natural o no
 *
 * \param numero Numero a evaluar
 * \return 0 si no es natural y 1 si lo es
 *
 */

int ValidarFactorial(float numero);

#include "Validaciones.c"

#endif // VALIDACIONES_H_INCLUDED
