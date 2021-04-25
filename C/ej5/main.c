#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    float pot;
    printf("ingrese un num");
    scanf("%f",&num);
    if(num>0)
    {
        pot=num*num;
        printf("el cuadrado es %f",pot);
    }
    else if(num<=0)
    {
        printf("error el num tiene q ser mayor a 0 ndeaaaah");
    }


    return 0;
}
