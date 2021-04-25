#include <stdio.h>
#include <stdlib.h>
/*
    Se Cargan Numeros Hasta Que El Usuario Quiera, Preguntandole Si Quiere Continuar Desp De Cada Introduccion.
    Luego Sumar Todos Los Numeros Y Mostrar El Resultado. Validar La Respuesta Con La Funcion.
*/

int validaS_N(void);
int sumar(int numeros[],int tam);

int main()
{
    int numeros[256];
    int suma=0,i=0,flag=0;
//    char letra;
    do{
        printf("mete num\n");
        scanf("%d",&numeros[i]);
        fflush(stdin);
        i++;
        flag=validaS_N();

    }while (flag!=0);
    suma=sumar(numeros,i);


    printf("La suma de todos los numeros es %d\n",suma);
    return 0;
}
int validaS_N(void)
{
    char letra;
    int retorno;
    do{
    printf("Seguir?\n");
    scanf("%c",&letra);}while (letra!='S' && letra !='N');
    if (letra=='S')
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}

int sumar(int numeros[],int tam)
{
    int total=0;
    while(tam!=0)
    {
        total+=numeros[tam];
        tam--;
    }
    return total;
}


