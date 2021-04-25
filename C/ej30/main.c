#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3;
    printf("ingrese num");
    fflush(stdin);
    scanf("%d",&num1);
    printf("ingrese num");
    fflush(stdin);
    scanf("%d",&num2);
    printf("ingrese num");
    fflush(stdin);
    scanf("%d",&num3);
    if(num2>num3 || num2<num1)
    {
        printf(" no essta atroden");
    }
    else{
        printf("esta atroden");
    }

    return 0;
}
