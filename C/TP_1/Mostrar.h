#ifndef MOSTRAR_H_INCLUDED
#define MOSTRAR_H_INCLUDED

/** \brief Muestra el mensaje de ingresar operando 1, con el nùmero cargado si lo està, o no si no lo està
 *
 * \param flagExisteA Comprobar si el usuario cargo un nùmero o no
 * \param operandoA Numero que el usuario ha cargado
 *
 */

void MostrarOperandoA(int flagExisteA,float operandoA);

/** \brief Muestra el mensaje de ingresar operando 2, con el numero cargado si lo esta, o no si no lo esta
 *
 * \param flagExisteB Comprobar si el usuario cargo un nùmero o no
 * \param operandoB Nùmero que el usuario ha cargado
 *
 */

void MostrarOperandoB(int flagExisteB,float operandoB);

/** \brief Muestra las opciones a las que el usuario puede acceder
 *
 * \param flagExisteA Comprueba si existe el operando A
 * \param flagExisteB Comprueba si existe el operando B
 * \param operandoA Primer operando cargado por el usuario
 * \param operandoB Segundo operando cargado por el usuario
 *
 */

void MostrarOpciones(int flagExisteA,int flagExisteB, float operandoA,float operandoB);
/** \brief Muestra los resultados de todas las operaciones realizadas, o mensajes indicando si no se pueden realizar
 *
 * \param resultadoSuma El resultado de la suma de ambos operandos
 * \param resultadoResta La diferencia entre ambos operandos
 * \param resultadoDivision El cociente entre ambos operandos
 * \param resultadoMultiplicacion El producto entre ambos operandos
 * \param resultadoFactorialA Resultado del factorial del primer operando
 * \param resultadoFactorialB Resultado del factorial del segundo operando
 * \param flagDivision Bandera que indica si es posible dividir o no
 * \param flagFactorialA Bandera que indica si es posible hacer el factorial del primer operando o no
 * \param flagFactorialB Bandera que indica si es posible hacer el factorial del segundo operando o no
 *
 */

void MostrarResultados(float resultadoSuma,float resultadoResta,float resultadoDivision, float resultadoMultiplicacion,long long int resultadoFactorialA,long long int resultadoFactorialB,int flagDivision,int flagFactorialA,int flagFactorialB);

#include "Mostrar.c"
#endif // MOSTRAR_H_INCLUDED
