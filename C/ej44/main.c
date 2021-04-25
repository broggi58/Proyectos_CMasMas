#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 3


int main()
{
    char d[t][10];
    char aux2[10];
    int tem[t];
    int aux;
    for (int i =0;i<=t;i++)
    {
        printf("dia");
        fflush(stdin);
        scanf("%s",d[i]);
        printf("temp");
        fflush(stdin);
        scanf("%d",&tem[i]);
    }
    for (int i=0;i<=t;i++)
    {
        if (tem[0]<tem[i])
        {
            aux=tem[0];
            tem[0]=tem[i];
            tem[i]=aux;
            strcpy(aux2,d[0]);
            strcpy(d[0],d[i]);
            strcpy(d[i],aux2);
        }

    }
    printf(" %s %c",d[0],tem[0]);








    return 0;
}
