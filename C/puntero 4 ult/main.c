#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    float pre;
    int cant;
}Med;


int main()
{
    Med* a= (Med*) malloc(sizeof(Med));

    if (a==NULL)
    {
        printf("No hay lugar ndeaaaaaaaah");
        exit(0);
    }
    for (int i=0;i<50;i++)
    {
        printf("mete el codigo perreke");
        scanf("%d",a.cod +i );
        printf("mete el precio dog");
        scanf("%f",a.pre+i);
        printf("mete cantidad");
        scanf("%d", a.cant+i);
    }
    for (int i=0;i<50;i++)
    {
        printf("codigo : %d  precio: %f  cantidad : %d",*(Med.cod+i),*(Med.pre+i),*(Med.cant+i));
    }




    printf("Hello world!\n");
    return 0;
}
