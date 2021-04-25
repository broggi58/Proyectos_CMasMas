#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int suma=0;
    printf("ingrese un num");
    scanf("%d",&num);
    while (num>=0)
    {
        suma+=num;
        num--;
    }
    printf("el resultado es %d",suma);

    return 0;
}
