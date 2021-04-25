#include <stdio.h>
#include <stdlib.h>

int main()
{int a,cont=0,max,min,acu=0,flag=0;
float prom;
while (cont<30)
{printf("num");
fflush(stdin);
scanf("%d",&a);
acu+=a;
if (flag==0)
{
    max=a;
    min=a;
    flag++;
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
prom=(float)acu/30;
    printf("Hello world!\n %d %d %f",max,min,prom);
    return 0;
}
