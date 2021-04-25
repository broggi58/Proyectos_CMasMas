#include "InputUsuario.h"

int opciones()
{
    int opcion;
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

float PedirNumero()
{   float retorno;
    printf("Introducir numero: \n");
    fflush(stdin);
    scanf("%f",&retorno);
    return retorno;
}
