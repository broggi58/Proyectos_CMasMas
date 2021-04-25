#include <stdio.h>
#include <stdlib.h>

int main()
{int a,b,c,d,max,flag=0;
printf("nun");
fflush(stdin);
scanf("%d",&a);
printf("nun");
fflush(stdin);
scanf("%d",&b);
printf("nun");
fflush(stdin);
scanf("%d",&c);
printf("nun");
fflush(stdin);
scanf("%d",&d);
if (flag==0 )
{
    max=a;
    flag++;
    if (max<b)
    {
        max=b;
    }
    if(max<c)
    {
        max=c;
    }
    if(max<d)
    {
        max=d;
    }


}



    printf("Hello world!\n%d",max);
    return 0;
}
