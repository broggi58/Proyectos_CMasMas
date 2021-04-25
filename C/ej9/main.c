#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int cont=0;
    int conta=0, conte=0,conti=0,conto=0,contu=0;

    while(cont<20)
    {
        cont++;
        fflush(stdin);
        printf("ingrese letra");
        scanf("%c",&letra);
        if (letra=='a')
        {
            conta++;
        }
        if (letra=='e')
        {
            conte++;sd
        }
        if (letra=='i')
        {
            conti++;
        }
        if (letra=='o')
        {
            conto++;
        }
        if (letra=='u')
        {
            contu++;
        }

    }
    printf("hay %d a, %d e, %d i,%d o y %d u ",conta,conte,conti,conto,contu);
    return 0;
}
