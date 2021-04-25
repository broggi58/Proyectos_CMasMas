#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num1,num2,aux;
        printf("mete num1");
        scanf("%d",&num1);
        printf("mete num2");
        fflush(stdin);
        scanf("%d",&num2);
        aux=num1;
        num1=num2;
        num2=aux;
        printf(" %d %d",num1,num2);

        return 0;
}
