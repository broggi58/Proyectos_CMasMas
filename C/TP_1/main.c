#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "InputUsuario.h"
#include "Validaciones.h"
#include "Mostrar.h"


int main()
{

    float operandoA;
    float operandoB;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    long long int resultadoFactorialA;
    long long int resultadoFactorialB;
    int flagExisteA;
    int flagExisteB;
    int flagCheckDivision;
    int flagCheckFactorialdeA;
    int flagCheckFactorialdeB;
    int flagCheckOperaciones;
    int salir;

    flagCheckOperaciones=0;
    flagExisteA=0;
    flagExisteB=0;
    salir=0;

    do{
            system("cls");
            MostrarOpciones(flagExisteA,flagExisteB,operandoA,operandoB);
        switch(opciones())
        {
            case 1:
                operandoA= PedirNumero();
                flagExisteA=1;
                break;
            case 2:
                operandoB= PedirNumero();
                flagExisteB=1;
                break;
            case 3:
                if(flagExisteA && flagExisteB)
                {
                    resultadoSuma=Sumar(operandoA,operandoB);
                    resultadoResta=Restar(operandoA,operandoB);
                    flagCheckDivision=validarDivision(operandoB);
                    if(flagCheckDivision==1)
                    {
                        resultadoDivision=Dividir(operandoA,operandoB);
                    }

                    resultadoMultiplicacion=Multiplicar(operandoA,operandoB);

                    flagCheckFactorialdeA=ValidarFactorial(operandoA);
                    if(flagCheckFactorialdeA==1)
                    {
                        resultadoFactorialA= CalcularFactorial(operandoA);
                    }

                    flagCheckFactorialdeB=ValidarFactorial(operandoB);
                    if(flagCheckFactorialdeB==1)
                    {
                        resultadoFactorialB= CalcularFactorial(operandoB);
                    }
                    printf("Se han realizado todas las operaciones.\n");
                    flagCheckOperaciones=1;
                }
                else
                {
                    printf("No se pueden realizar las operaciones porque no se ingresaron ambos operandos.\n");

                }
                fflush(stdin);
                printf("Pulse enter para continuar\n");
                getchar();
                break;
            case 4:
                if(flagCheckOperaciones==1)
                       {
                        MostrarResultados(resultadoSuma,resultadoResta,resultadoDivision,resultadoMultiplicacion,resultadoFactorialA,resultadoFactorialB,flagCheckDivision,flagCheckFactorialdeA,flagCheckFactorialdeB);
                       }
                else
                {

                    printf("No se pueden mostrar las operaciones porque todavia no se calcularon.\n");

                }
                fflush(stdin);
                printf("Pulse enter para continuar\n");
                getchar();
                break;
            case 5:
                printf("Introduzca 1 para salir\n");
                fflush(stdin);
                scanf("%d",&salir);
                break;
           default:
                fflush(stdin);
                printf("Introduzca una opcion valida.\n Pulse enter para continuar\n");
                getchar();

        }

    }while(salir!=1);

        return 0;
}
