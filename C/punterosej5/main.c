#include <stdio.h>
#include <stdlib.h>
void initTables(float* ptrArray[],int limit)
{
    for(int i=0;i<limit;i++)
    {
        ptrArray[i]=NULL;
    }
}

int menu()
{
    int option;
    printf("1- Alta mesa\n");
    printf("2- Cerrar el local deaa\n");
    do{
    fflush(stdin);
    scanf("%d",&option);
    if (option<0|| option >2)
        printf("Mete bien el num salame zzzz\n");
    }while(option<0|| option >2);
    return option;
}
float* setPrice()
{
    float aux;
    float* ptrAux=(float*)malloc(sizeof(float));
    if (ptrAux!=NULL)
    {
        printf("Cuanto gastaron? uwu\n");
        fflush(stdin);
        scanf("%f",&aux);
        *ptrAux=aux;
    }
    return ptrAux;
}
void setTable(float* array[],int limit,float* ptrAux)
{
    int aux;
    printf("En q mesa se van a centar estos culiados\n");
    do{
    fflush(stdin);
    scanf("%d",&aux);
    }while (aux <1 || aux>limit);
    array[aux-1]= ptrAux;
}
float getTotalSale(float* array[],int limit)
{
    float total=0;
    for(int i=0;i<limit;i++)
    {
        if(array[i]!=NULL)
        total+=*array[i];
    }
    return total;
}
void printUnusedTables(float* array[],int limit)
{
    printf("Mesas no usadas: ");
    for(int i=0;i<limit;i++)
    {
        if(array[i]==NULL)
        {
            printf(" %d",i+1);
        }
    }
}
void printTableWithSales(float* array[], int limit)
{
    printf("Nº de mesa              total");
    for(int i=0;i<limit;i++)
    {
        if (array[i]!=NULL)
        {
            printf("%d                %.2f",i+1,*array[i]);
        }
    }
}
int main()
{
    const int limit=50;
    float* ptrArray[limit];
    float* aux;
    float total;
    do{
        switch(menu())
        {


            case 1: aux=setPrice();
                setTable(ptrArray,limit,aux);
                break;
            case 2:
                    total= getTotalSale( ptrArray, limit);
                    printf("total gastado hoy bro: %.2f \n",total);
                    printUnusedTables(ptrArray, limit);
                    printTableWithSales( ptrArray, limit);
                break;
            default:
                printf("Error. Mete 1 buena asi me voy a dormir\n");
        }

        }while(menu()!=2);

    return 0;
}
