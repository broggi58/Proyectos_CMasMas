#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,prod=1,suma=0,cont=0;
    while(cont<10)
    {
        cont++;
        do {printf("mete un num");
        fflush(stdin);
        scanf("%d",&num);}while (num==0);


    if (num<0)
        {
            prod=prod*num;
        }
    else if(num>0)
    {
        suma+=num;
    }


    }
    printf("el prod es %d y la suma es %d",prod,suma);
        return 0;
}
