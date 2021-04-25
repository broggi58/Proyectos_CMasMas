#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont=0,contimpar=0;

    while(cont<100)
    {
        cont++;
        if (cont%2!=0)
        {
            contimpar++;
        }
    }
    printf("la cantidad de numeros impares es de %d",contimpar);
    return 0;
}
