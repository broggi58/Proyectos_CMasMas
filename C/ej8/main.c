#include <stdio.h>
#include <stdlib.h>

int main()
{

       float base;
       float altura;
       float superficie;
       printf("ingrese base");
       scanf("%f",&base);
       printf("ingrese altura");
       fflush(stdin);
       scanf("%f",&altura);
       superficie=base*(altura/2);
       printf("la superficie es %f",superficie);


        return 0;
}
