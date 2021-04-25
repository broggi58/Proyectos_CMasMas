#include <stdio.h>
#include <stdlib.h>

int main()
{int num;
int cont=0;
int suma=0;
float prom=0;


    while (cont<5)
{
    cont++;
    printf("ingrese un num");
    scanf("%d",&num);
    fflush(stdin);
    suma=suma+num;



}
     prom=suma/5;
    printf("la media es %f\n",prom);
    return 0;
}
