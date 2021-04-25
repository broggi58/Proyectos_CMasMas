#include <stdio.h>
#include <stdlib.h>

int main()
{
        int lado1,lado2,lado3,max,acumulador=0,aux;
        printf("ingresar lado");
        fflush(stdin);
        scanf("%d",&lado1);
        printf("ingresar lado");
        fflush(stdin);
        scanf("%d",&lado2);
        printf("ingresar lado");
        fflush(stdin);
        scanf("%d",&lado3);

        if(lado1>lado2)
        {
            if(lado1>lado3)
            {
                max=lado1;
            }
        }
        else if(lado2>lado1)
        {
            if(lado2>lado3)
            {
                max=lado2;
            }
        }
        else if (lado3>lado1)
        {
            if(lado3>lado2)
            {
                max=lado3;
            }
        }
        acumulador=lado1+lado2+lado3;
        aux=acumulador-max;
        if(aux<max)
        {
            printf("es un triangulo");
            if(lado1==lado2)
            {
                if(lado1==lado3)
                {
                    printf("\nel triangulo es equilatero");
                }
                else
                {
                    printf("\nel tiangulo es isoceles");
                }
            }
            else if(lado1!=lado2)
            {
                if (lado1!=lado3)
                {
                    printf("\n el triangulo es escaleno");
                }
                else
                {
                    printf("\n el triangulo es isoceles");
                }
            }

        }


        return 0;
}
