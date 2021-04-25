#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *a= (int*) malloc(sizeof(int)*20);
        if (a==NULL)
        {
            printf("No hay memoria");
        }
        for (int i=0;i<20;i++)
        {
            printf("mete num dog");
            scanf("%d",a+i);
        }
        for (int i=0;i<20;i++)
        {
            printf("%d",*(a+i));
        }

        return 0;
}
