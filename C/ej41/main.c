#include <stdio.h>
#include <stdlib.h>

int main()
{int a,cont=0,max,min,flag=0;
while (cont<5)
{
    printf("num");
    fflush(stdin);
    scanf("%d",&a);
    if(flag==0)
    {
        max=a;
        min=a;
    }
    if (max<a)
    {
        max=a;
    }
    if (min>a)
    {
        min=a;
    }
    cont++;

}
    printf("Hello world!\n%d %d",max,min);
    return 0;
}
