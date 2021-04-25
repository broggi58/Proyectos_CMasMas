#include "Validaciones.h"


int validarDivision(float num)
{
    int retorno=1;
    if(num==0)
    {
        retorno=0;
    }
    return retorno;
}

int ValidarFactorial(float numero)
{
    int aux= numero;
    int retorno=1;
    if(aux<0|| aux<numero)
    {
        retorno=0;
    }
    return retorno;
}
