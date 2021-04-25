#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a,i;
        printf(" intro num");
        fflush(stdin);
        scanf("%d",&a);

        for ( i=1;i<=10;i++)
        {

            printf("%d x %d = %d\nf",a,i,a*i);
        }
        return 0;
}
