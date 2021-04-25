#include <stdio.h>
#include <stdlib.h>

int main()
{
        int num1,num2,num3,max;
        printf("ingrese num");
        scanf("%d",&num1);
        printf("ingrese num");
        scanf("%d",&num2);
        printf("ingrese num");
        scanf("%d",&num3);

        if (num1>num2)
        {
            if(num1>num3)
            {
                max=num1;
            }
        }
        else if(num2>num1)
        {
            if(num2>num3)
            {
                max=num2;
            }

        }
        else if(num3>num1)
        {
            if(num3>num2)
            {
                max=num3;
            }
        }

        printf("%d",max);

        return 0;
}
