#include <stdio.h>
#include <stdlib.h>
#include "math.h"

/*
    Se piden valores de A,B y C, pasarselos a la funcion para que calcule las raices. Si son complejas mostar un mensaje
    diciendo que lo son.
*/

float raices(int a,int b,int c);

int main()
{
    int a,b,c;
    float flag;
    printf("Ingrese A");
    fflush(stdin);
    scanf("%d",&a);
    printf("Ingrese B");
    fflush(stdin);
    scanf("%d",&b);
    printf("Ingrese C");
    fflush(stdin);
    scanf("%d",&c);
    flag=raices(a,b,c);


    printf("Hello world!\n");
    return 0;
}

float raices(int a,int b,int c)
{
    float raiz1,raiz2,div=2*a;
    raiz1=(float)(-b + sqrt(b*b -4*a*c))/div;
    raiz2=(float)(-b - sqrt(b*b -4*a*c))/div;
    if(raiz1==raiz2)
    {
        printf("La Raiz es %.2f\n",raiz1);
    }
    else
    {
       printf("Las raices son conplejas conjugadas.\n");
    }
    return 0;
}
