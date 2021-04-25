#include <stdio.h>
#include <stdlib.h>

int main()
{
        int peso,contneg=0,contpos=0,seguir;
        do{printf("ingresar peso");
        scanf("%d",&peso);
        fflush(stdin);
        printf("para continuar introducir numero deiferente de 0");
        scanf("%d",&seguir);
        }while (seguir !=0);
        if(peso<=80)
        {
            contneg++;
        }
        else{
            contpos++;
        }
        printf("%d %d",contneg,contpos);
        return 0;
}
