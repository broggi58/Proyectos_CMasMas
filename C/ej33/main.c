#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a,b;
        float plusa=0,plusb=0;
        printf("mete num de mozo");
        fflush(stdin);
        scanf("%d",&a);
        if (a==0)
        {
            exit(0);
        }

        printf("mete num de mozo");
        fflush(stdin);
        scanf("%d",&b);
        if (b==0)
        {
            exit(0);
        }
        plusa=  a+ (float) a*0.33;
        plusb=  b+ (float) b*0.33;
        if(plusa>plusb)
        {
            printf("%f",plusa);
        }
        else{
            printf("%f",plusb);
        }

        return 0;
    }



