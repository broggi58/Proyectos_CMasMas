#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num;
        printf("ingrese un num");
        fflush(stdin);
        scanf("%d",&num);
        if (num<0)
        {
            printf("positivo");
        }
        else if (num>0)
        {
            printf("negativo");
        }
        return 0;
}
