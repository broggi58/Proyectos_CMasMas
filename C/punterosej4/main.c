#include <stdio.h>
#include <stdlib.h>
int menu()
{
    int option;
    printf("1- Encontrar num adentro del array\n");
    printf("2- Encontrar la posicion q  contiene 1 num\n");
    printf("3- Tomarse el palo\n");
    do{
    fflush(stdin);
    scanf("%d",&option);
    }while(option<0 || option >3);
    return option;
}
int* allocNumber(int*array[])
{
    int aux;
    int* num=malloc(sizeof(num));
    if(num!=NULL)
    {
        scanf("%d",&aux);
        *num=aux;
        return num;
    }
    else{
        return NULL;
    }
}
void loadArray(int* array[],int size)
{
    int* aux;
    for(int i=0;i<size;i++)
    {
        aux=allocNumber(array);
        if(aux==NULL)
        {
            printf("No hay memoria para los num breoooo\n");
            break;
        }
        else
        {
            array[i]=aux;
        }
    }
}

int findPosition(int* array[],int size)
{
    int num,i;
    printf("Mete el num a buscar bbto\n");
    fflush(stdin);
    scanf("%d",&num);
    for( i=0;i<size;i++)
    {
        if(num==*array[i])
            break;
    }
    return i+1;
}
int findNumber(int* array[], int size)
{
    int num;
    printf("Meter el numero de la posicion q queres encontrar bbto\n");
    do{
    fflush(stdin);
    scanf("%d",&num);
    if(num<1||num>20)
        printf("mete el indice bien la concha de tu madre\n");
    }while(num<1||num>20);
    return *array[num-1];
}
int main()
{
    int* array[20];
    int position;
    int num;
    int out;
    loadArray(array,20);
    do{
    switch(menu())
    {
        case 1:position=findPosition(array,20);
                printf("El num q metiste esta en el ogt. AH y en la posicion %d",position);
            break;
        case 2:num=findNumber(array,20);
                printf("el num q esta en la posicion q metiste es el %d",num);
            break;
        case 3: printf("Te queres tomar el palo? Mete 0 si si.");
                fflush(stdin);
                scanf("%d",&out);
            break;
    }
    }while(out);
    return 0;
}
