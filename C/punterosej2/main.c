#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char menu()
{
    char option;
    printf("Mete la opcion rey\n");
    printf("a- Cargar array\n");
    printf("b- ordenar el vector\n");
    printf("c- Mostrar el vector. Me tome 1 birra y ya estoy en pedo deaaaaa\n");
   do{
    fflush(stdin);
    scanf("%c",&option);
    if(option>'c')
        printf("Metela bien salchicha ndeee\n");
   }while(option>'c');
    return option;
}
int* allocNum()
{
    int num;
    int* ptr;
    ptr=(int*)malloc(sizeof(int));
    if(ptr!=NULL)
    {
        printf("Mete el num titan\n");
        fflush(stdin);
        scanf("%d",&num);
        *ptr=num;
    }
    return ptr;
}
void loadArray(int* array[],int size)
{
    int* aux;
    for(int i=0;i<size;i++)
    {
        aux= allocNum();
        if (aux!=NULL)
            array[i]=aux;
        else{
            printf("Dio null man no se pudo llenar. Anda a domrir\n");
            break;
        }
    }
}
void sortArray(int*array [],int size)
{
    int* aux;
    for(int i=0;i<size-1;i++)
    {
        for(int j=1;j<size;j++)
        {
            if(*array[i]>*array[j])
            {
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    }
}
void printArray(int* array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("El numero en el indice %d  es %d",i+1,*array[i]);
    }
}
int main()
{
    int* array[20];
    int out=1;
    do{
    switch(menu())
    {
        case 'a':
                loadArray(array,20);
                printf("Array carga2 bbto ☺ \n");
                printf("Pulse una tecla para continuar atr \n");
                getchar();
                break;
        case 'b':
                sortArray(array,20);
                printf("Ordena3 breaoooo ☻\n");
                printf("Pulse una tecla para continuar atr \n");
                getchar();
                break;
        case 'c':
                printArray(array,20);
                printf("Pulse una tecla para continuar atr \n");
                getchar();
                break;
        case 'd':
                printf("Te queres tomar el palo? toca 0 si si ☻\n");
                fflush(stdin);
                scanf("%d",&out);
                break;
        default:
                printf("mete 1 buenaa bro. Ndeaaa re lleno el man ♠\n");
    }
    }while(out);
    printf("Hello world!\n");
    return 0;
}
