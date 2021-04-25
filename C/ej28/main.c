#include <stdio.h>
#include <stdlib.h>

int main()

{
    int j;
        for(int i =2;i<=100;i++)
        {
            for( j=2;j<=i;j++)
            {
                if (i%j==0)
                {
                    break;
                }
            }
            if(i==j)
            {
                printf("%d\n",i);
            }
        }


        return 0;
}
