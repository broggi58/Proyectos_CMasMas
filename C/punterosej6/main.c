#include <stdio.h>
#include <stdlib.h>
#include "math.h"
typedef struct
{
    int code;
    float price;
    int amount;
}Medicine;

char menu()
{
    char option;
    system("cls");
    printf("a- Listado ordenado por código de producto ndee\n ");
    printf("b- Código del medicamento de precio mas bajo alto sueño brooo\n");
    printf("c- Tomate el palo q tengo sueño titan\n");
    do{
    fflush(stdin);
    scanf("%c",&option);
    if (option !='a'||option!='b')
    {
        printf("Mete bien la opcion salchicha. >>ZZZZZZ\n");
    }
    }while(option !='a'||option!='b');
    return option;
}
void sortByCode (Medicine* array[],int size )
{
    Medicine aux;
    for(int i=0;i<size-1;i++)
    {
        for(int j=1;j<size;j++)
        {
            if (array[i]->code>array[j]->code)
            {
                aux=*array[i];
                *array[i]=*array[j];
                *array[j]=aux;
            }
        }
    }
}
void printList(Medicine* array[],int size)
{
    printf(" Code        price          amount");
    for(int i=0;i<size;i++)
    {
        printf("%d         %.2f             %d",array[i]->code,array[i]->price,array[i]->amount);
    }
}
int findLowestPrice(Medicine* array[],int size)
{
    int i;
    Medicine aux;
    aux.price=2147483647;
    for( i=0;i<size;i++)
    {
        if(array[i]->price<aux.price)
            aux.price=array[i]->price;
    }
    for(i=0;i<size;i++)
    {
        if (array[i]->price==aux.price)
            break;
    }
    return i;
}

int main()
{
    const int items=50;
    int out=0,confirm,index;
    Medicine* arrayPtr[items];
    printf("Hello world!\n");
   do{
    switch(menu())
    {
        case 'a': sortByCode(arrayPtr,items);
                  printList(arrayPtr,items);
            break;
        case 'b': index=findLowestPrice(arrayPtr,items);
                    printf("Aca esta el codigo rey. Nose xq verga me desperte tan temprano me estoy re muriendo%d",arrayPtr[index]->code);

            break;
        case 'c':
            printf("Tengo sueño asi q grax x tomarte el palo. Mete un num para salir q no sea 0\n");
            fflush(stdin);
            scanf("%d",&confirm);
            if(confirm)
                out=1;

            break;
        default: printf("Mete bien la opcion salchicha. >>ZZZZZZ\n");
    }
   }while(!out);

    return 0;
}
