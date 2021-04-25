#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#define loop for(int i=0;i<size;i++)
typedef struct
{
    char patent [6];
    int isEmpty;
    clock_t tiempo;
}car;
void initCars(car* ptr, int size)
{
    for(int i=0;i<size;i++)
    {
        ptr[i].isEmpty=1;
    }
}
int menu()
{
    int option;
    printf("1- 1 autito se mete. Piii Piiii \n");
    printf("2- 1 autito se va. Q no se haga el logi y q pague\n");
    printf("3 - Cerramo todo y vamo a jugar al valorant UwU\n");
    do{
    fflush(stdin);
    scanf("%d",&option);
    if(option<0 || option >3)
        printf("Mete bien la opcion salchicha\n");
    }while(option<0 || option >3);
    return option;
}
int searchFree(car* ptr,int size)
{
    int retorno,i;
    for( i=0;i<size;i++)
    {
        if(ptr->isEmpty)
            retorno=i;

    }
    if(i==99 && ptr[99].isEmpty==0)
    {
        printf("No hay mas lugar rey ndee \n");
        retorno=-1;
    }
    return retorno;
}
int isNumber(char letter)
{
    int retorno=0;;
    if(letter=='1'||letter=='2'||letter=='3'||letter=='4'||letter=='5'||letter=='6'||letter=='7'||letter=='8'
       ||letter=='9'||letter=='0')
        retorno=1;

    return retorno;
}
char* setPatent()
{
    char aux[256];
    char retorno[6];
    int flag=0;
    int tries=0;
    printf("Mete la patente de este perejil\n");
    do{
    fflush(stdin);
    scanf("%s",aux);
    if(strlen(aux)>6|| strlen(aux)<6)
    {
        printf("Mete bien la patente la puta q te re mil re pario\n");
        tries++;
    }
    else
    {
        for(int i=0;i<strlen(aux);i++)
        {
            if(i<3 && isNumber(aux[i]))
            {
                printf("Mete bien la patente pedazo de gato\n");
                tries++;
                break;
            }
            if(i>3 && !isNumber(aux[i]))
            {
                printf("Mete bien la patente pedazo de gato\n");
                tries ++;
                break;
            }
            else if (i+1==strlen(aux))
            {
                tries++;
                if(tries==1)
                {
                    printf("Buena man, la metiste al toque\n");
                    flag=1;
                }
                else
                {
                    printf("AAL fiiiin la puta q te pario, viste, no era tan dificil\n");
                    flag=1;
                }
            }
        }
    }

    }while(!flag);
    strcpy(retorno,aux);
    return retorno;
}
void newCar(car* ptr,int size,int index,char* setPatent())
{
    strcpy(ptr[index].patent,setPatent());
    ptr[index].tiempo= clock();
    printf("Carga3 lince\n");
}
int searchPatent(car* ptr,int size,char* patent)
{
    int retorno=-1;
    loop
    {
        if(!strcmp(ptr[i].patent,patent))
            retorno=i;
            break;
    }
    return retorno;
}
clock_t getTime(car* ptr,int index)
{
    clock_t retorno;
    ptr[index].tiempo= clock() -ptr[index].tiempo;
    retorno=ptr[index].tiempo;
    return retorno;
}
void carLeaves(car* ptr,int size,char* function())
{
    printf("Mete la patente del borracho q se va\n");
    fflush(stdin);
    char* aux=function();
    char time[50];
    clock_t aux;
    int index=searchPatent(ptr,size,aux);
    if(index!=-1)
    {
        ptr[index].isEmpty=1;
        aux=getTime(ptr,index);
        ptr[index].tiempo=aux;
       // ptr[index].tiempo =clock()-ptr[index].tiempo;
        strftime(time,50,%X,ptr.tiempo);
        printf("El wachin estuvo %s  tiempo COBRALE MUCHO HACELO MIERDAAAAAA\n",time);
    }
}
int main(){

    int index,out=1;
    car* ptr=(car*)malloc(sizeof(car)*100);
    if(ptr==NULL)
    {
        printf("No tenes lugar para tantos autos salchicha\n");
        exit(EXIT_FAILURE);
    }
    initCars(ptr,100);
    do{
    switch(menu())
    {
        case 1: index=searchFree(ptr,100);
                newCar(ptr,100,index,setPatent());
                printf("Wenardo, mete intro para seguir\n");
                getchar();
            break;
        case 2:
            carLeaves(ptr,100,setPatent());
             printf("Wenardo, mete intro para seguir\n");
                getchar();
            break;
        case 3:
            printf("Dale q cerramooooooooo. Mete 0 y nos tomamo e palo\n");
            fflush(stdin);
            scanf("%d",&out);
            if(out)
            {
                printf("Nos re vimooo perritoo malvadooooooo\n");
                 printf("Wenardo, mete intro para seguir\n");
                getchar();
                out=0;
            }
            break;
        default:printf("Metela bien rey, ya me canse de validar cosas me quero ir a la camucha\n");
    }
    }while(out);
    printf("Hello world!\n");
    return 0;
}
