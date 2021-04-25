#include "Operaciones.h"

float Sumar(float operandoA, float operandoB)
{
    return operandoA+operandoB;
}
float Restar(float operandoA, float operandoB)
{
    return operandoA-operandoB;
}
float Multiplicar(float operandoA, float operandoB)
{
    return operandoA*operandoB;
}

float Dividir(float operandoA,float operandoB)
{
    return operandoA/operandoB;
}

long long int CalcularFactorial(float num)
{

    long long int retorno=num;

    if(num==0)
        retorno=1;
    for(int i=num-1;i>1;i--)
    {
        retorno*=i;
    }
    return retorno;
}
