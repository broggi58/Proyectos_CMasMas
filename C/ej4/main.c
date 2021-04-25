#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int num1;
    int num2;
    int resta;
    printf("ingrese num1");
    scanf("%d",&num1);
    printf("ingrese num2");
    fflush(stdin);
    scanf("%d",&num2);
    resta=num1-num2;
    if(resta<=0){
        printf("resultado negativo");
    }
    else if(resta>=0){
        printf("resultado positivo");
    }



    return 0;
}
