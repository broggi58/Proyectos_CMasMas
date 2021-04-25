#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int cont=0;
    int cont0=0;
    int contpos=0;
    int contneg=0;
    while (cont<10)
    {
        printf("ingrese un num");
        scanf("%d",&num);
        if (num==0)
        {
            cont0++;
        }
        else if (num<0)
        {
            contneg++;
        }
        else if(num>0);
        {
            contpos++;
        }
        cont++;
    }
    printf (" hay %d ceros, %d mayores y %d menores",cont0,contpos,contneg);

    return 0;
}
