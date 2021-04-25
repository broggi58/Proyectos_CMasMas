#include "Mostrar.h"

void MostrarOperandoA(int flagExisteA,float operandoA)
{
    if(flagExisteA)
    {
        printf(("1. Ingresar 1er operando (A=%.2f)\n"),operandoA);
    }
    else
    {
        printf("1. Ingresar 1er operando (A=x)\n");
    }

}

void MostrarOperandoB(int flagExisteB,float operandoB)
{
    if(flagExisteB)
    {
        printf(("2. Ingresar 2do operando (B=%.2f)\n"),operandoB);
    }
    else
    {
        printf("2. Ingresar 2do operando (B=x)\n");
    }

}

void MostrarOpciones(int flagExisteA,int flagExisteB, float operandoA,float operandoB)
{
    MostrarOperandoA(flagExisteA,operandoA);
    MostrarOperandoB(flagExisteB,operandoB);
    printf("3. Calcular todas las operaciones\n");
    printf("     a) Calcular la suma (A+B)\n ");
    printf("    b) Calcular la resta (A-B)\n ");
    printf("    c) Calcular la division (A/B)\n ");
    printf("    d) Calcular la multiplicacion (A*B)\n ");
    printf("    e) Calcular el factorial (A!)\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n");
}


void MostrarResultados(float resultadoSuma,float resultadoResta,float resultadoDivision, float resultadoMultiplicacion,long long int resultadoFactorialA,long long int resultadoFactorialB,int flagDivision,int flagFactorialA,int flagFactorialB)
{

    printf("   a) \" El resultado de A+B es : %.2f\"\n",resultadoSuma);
    printf("   b) \" El resultado de A-B es : %.2f\"\n",resultadoResta);
    if(flagDivision==1)
    {
        printf("   c) \" El resultado de A/B es : %.2f\"\n",resultadoDivision);
    }
    else
    {
        printf("\"No se puede dividir por 0\"\n");
    }
    printf("   d) \"El resultado de A*B es: %.2f\"\n",resultadoMultiplicacion);
    if(flagFactorialA)
    {
        printf("   e) \"El  factorial de A es: %I64d \"\n",resultadoFactorialA);
    }
    else
    {
        printf("   e) \" No se puede hacer el factorial de A porque no es un numero natural. \"\n");
    }
    if(flagFactorialB==1)
    {
        printf("      \"El factorial de B es: %I64d \"\n",resultadoFactorialB);
    }
    else
    {
        printf("         No se puede hacer el factorial de B porque no es un numero natural\"\n");
    }

}
