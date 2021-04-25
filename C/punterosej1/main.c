#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* array[20];
    int aux;
    int* ptr;
    for(int i=0;i<20;i++)
    {
        printf("Mete el num de la posicion %d ",i+1);
        fflush(stdin);
        scanf("%d",&aux);
        ptr=(int*)malloc(sizeof(int));
        if(ptr!=NULL)
            *ptr=aux;
        array[i]=ptr;
    }
    for(int i=0;i<20;i++)
    {
        printf("  %d  \n",*array[i]);
    }
    printf("Hello world!\n");
    return 0;
}
