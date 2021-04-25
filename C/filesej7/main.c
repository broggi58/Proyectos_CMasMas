#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int operacion; /* 1- Depósito, 2- Extracción. */
    float monto; /* cantidad de dinero a depositar o extraer */
    char clave[5]; /* clave del usuario para las transacciones ( 4 dígitos ) */
}banco;

int menu()
{
    system("cls");
    int opcion;
    system("cls");
    printf("Mete una opcion perricola\n");
    printf("1- Deposito\n");
    printf("2- Extracciones\n");
    printf("3- Saldo\n");
    printf("4- Salir");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int main()
{
    char clavel[5];
    int salir;
    int check;
    float deposit=0,sacar,sacarTotal;
    banco cliente;
    strcpy(cliente.clave,"1234");
    FILE* myFlie=fopen("clientes del banquito.dat","w");
    if (myFlie==NULL)
    {
        printf("No se abrio el archivo. Anda a jugar al valorant\n");
        exit(1);
    }
   do{
    switch(menu())
    {
        case 1: printf("Ingresa tu clave titan\n");
                fflush(stdin);
                scanf("%s",clavel);
                if(!strcmp(cliente.clave,clavel))
                {
                    cliente.operacion=1;
                    printf("Mete el monto a depositar papito <3\n");
                    fflush(stdin);
                    scanf("%f",&cliente.monto);
                    printf("Fijate si esta todo piola rey\n");
                    printf("Monto a ingresar : %f",cliente.monto);
                    printf("Manda 1 para guardarlo,2 para cambiarlo y 3 para tomarte el palo bbto\n");
                  do{
                    scanf("%d",&check);
                    if(check==1)
                    {
                        fwrite(&cliente,sizeof(banco),1,myFlie);
                        printf("La metiste piola dog\n");
                        deposit+=cliente.monto;
                    }
                    else if(check==2)
                    {
                        printf("Mete el nuevo monto titanic. Y desp meteme otra cosa\n");
                        fflush(stdin);
                        scanf("%f",&cliente.monto);
                        printf("Fijate si esta todo piola rey\n");
                        printf("Monto a ingresar : %f",cliente.monto);
                        printf("Manda 1 para guardarlo,2 para cambiarlo y 3 para tomarte el palo bbto\n");
                    }
                    else if(check==3)
                    {
                        printf("Te tomaste el palo cagon\n");
                        break;
                    }
                    else
                    {
                        printf("Tira un buen numero salame. pedazoo de gato\n");
                    }
                        } while(check!=1||check!=3);
                    }
                    else
                    {
                        printf("La metiste para el orto la clave man, tomatela\n");
                    }
                    break;
                case 2 :
                        printf("Mete la clave titannnnn\n");
                        fflush(stdin);
                        scanf("%s",clavel);
                        if(strcmp(cliente.clave,clavel))
                        {
                            printf("No la metiste forrooooooo\n");

                        }
                        else{
                            printf("Ahora mete el monto q queres sacar rey\n");
                            fflush(stdin);
                            scanf("%f",&sacar);
                            if(sacar>cliente.monto)
                            {
                                printf("No podes gastar mas de lo q tenes. Q sos peroncho?Zurdo de mierda\n");

                            }
                            else
                            {
                                cliente.monto-=sacar;
                                sacarTotal+=sacar;
                                fwrite(&cliente,sizeof(banco),1,myFlie);
                                printf("Ya la sacaste bbro\n");
                            }

                        }
                        break;
                case 3 :
                        printf("Depositos                 Extracciones                    Saldo\n");
                        printf("  %.2f                          %.2f                        %.2f       ",deposit,sacarTotal,cliente.monto);

                        break;
                case 4:
                        printf("ingrese 1 para salir\n");
                        fflush(stdin);
                        scanf("%d",&salir);
                        if (salir ==1)
                        {
                            fclose(myFlie);
                            exit(0);
                        }
                        break;
                }
   }while(1);

        printf("Aca no llegas lince asi q te puedo escribir lo q sea.");
        printf("SOYY GAYYYYYYYYYYYYYYYYYYYYYYYYYYYY FIESTA FIESTAAAA PLUMA PLUMA GAY, PLUMA PLUMA GAY, PLUMAPLUMAPLUMA GAYYY\n");

        return 0;
    }


