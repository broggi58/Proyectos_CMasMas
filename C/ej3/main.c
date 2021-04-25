#include <stdio.h>
#include <stdlib.h>

int main()
{float num1;
float num2;
float multi=0;
float pot=0;
do{
    num1=rand();
}while(num1==0);
printf("el num 1 es %f",num1);
do{
    num2=rand();
}while(num2==0);
printf("el num2 es %f",num2);
multi=num1*num2;
pot=num1*num1;
    printf("los numeros son %f y %f el producto es %f y la potencia es %f \n",num1,num2,multi,pot);
    return 0;
}
