#include <stdio.h>
#include <stdlib.h>

int main()

{
    int num1,cont=0;
    printf("ingrese num");
    scanf("%d",&num1);
    while (num1>0)
    {
        if (num1%3==0)
        {
            cont++;
        }
        num1--;
    }
    printf("%d",cont);

}
