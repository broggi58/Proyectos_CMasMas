#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{
    char name[50];
    int age;
   // int isEmpty;
}tipoN;

int menu()
{
    int opcion;
    system("cls");
    printf("Mete lo q queres hacer rey\n");
    fflush(stdin);
    printf("1-Alta tipo n");
    printf("2- Baja tipo n");
    printf("3- Modificar tipo n");
    printf("4- Mostrar tipos n");
    printf("5- Ordenar Tipo N x edad");
    printf("6- Ortenar x nombre");
    printf("7- tomarse el palo");
    scanf("%d",&opcion);
    return opcion;
}

void initLogis(tipoN* vatos[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        vatos[i]=NULL;
    }
}
int alta(tipoN* vatos[],tipoN buffer,int tam)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(vatos[i]==NULL)
        {
            strcpy(vatos[i]->name,buffer.name);
            vatos[i]->age=buffer.age;
            retorno=0;
            break;
        }
    }
    if((retorno=(-1)))
    {
        printf("Error . No hay mas lugar para meter mas logis\n");
    }
    return retorno;
}
int validarNombre(char* nombre)
{
    int retorno=0;
    int j=strlen(nombre);
    for(int i=0;i<j;i++)
    {
        if(nombre[i]=='0'||nombre[i]=='1'||nombre[i]=='2'||nombre[i]=='3'||nombre[i]=='4'||nombre[i]=='5'||nombre[i]=='6'||
           nombre[i]=='7'||nombre[i]=='8'||nombre[i]=='9')
        {
            retorno=1;
            printf("Q metes numeros en el nombre salame. Pedazo de gato\n");
            break;
        }
    }
    return retorno;
}
int validarEdad(int edad)
{
    int retorno=0;
    if (edad<0||edad>150)
    {
        printf("mete bien la edad la concha de tu madre\n");
        retorno=1;
    }
    return retorno;
}
tipoN cargarDatos()
{
    tipoN aux;
    int flag;
    do{
    printf("Mete l nombre reu\n");
    fflush(stdin);
    scanf("%s",aux.name);
    flag=validarNombre(aux.name);
    }while (flag);
   do{
    printf("Mete la edad titan\n");
    fflush(stdin);
    scanf("%d",&aux.age);
    flag=validarEdad(aux.age);
   }while(flag);

    return aux;
}
int comprobarExistencia(tipoN* vatos[],tipoN buffer,int tam)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
       if(!strcmp(vatos[i]->name,buffer.name))
       {
           retorno=0;
           break;
       }
    }
    return retorno;
}
int buscarNombre(tipoN* vatos[],int tam,char* name)
{
    int retorno=-1;
    for( int i=0;i<tam;i++)
    {
    if (!strcmp(vatos[i]->name,name))
    {
        retorno=i;
        break;
    }
    }
    return retorno;
}
int borrarWachin(tipoN* vatos[],int auxNum)
{
    int retorno=-1;
    vatos[auxNum]=NULL;
    retorno=0;
    return retorno;
}

char* pedirNombre(char aux[])
{

    printf("Mete el nombre del pancho que queres borrar\n");
                    fflush(stdin);
                    scanf("%s",aux);
    return aux;
}
void modificarWachin(tipoN* vatos[],int auxNum)
{
    int auxEdad;
    printf("Mete la nueva edad rey fuaaaaaaa\n");
    fflush(stdin);
    scanf("%d",&auxEdad);
    if(vatos[auxNum]->age==auxEdad)
    {
        printf("Para que mierda lo cambias si vas a poner el mismo la re calcada concha de tu pudra madre hijo de puta te voy a cagar a tiros la puta q te parioooooooooooo. ENfermo\n");

    }
    vatos[auxNum]->age=auxEdad;
}

void imprimirWachines(tipoN* vatos[],int SIZE)
{
    for(int i=0;i<SIZE;i++)
    {
        if(vatos[i]!=NULL)
        {
            printf("Nombre del iº :     %s \n     Edad :      %d",vatos[i]->name,vatos[i]->age);
        }
    }
}
int meterSentido()
{
    int sentido;
    printf("Mete 0 para ordenarlo ascendente y 1 para ordenarlo descendente. Dale que quiero ver 1 pelii porno bro ndeaaaa\n");
    fflush(stdin);
    do{
    scanf("%d",&sentido);
    if (sentido < 0 || sentido >1)
        printf("Mete 1 num bien mama guebo\n");
    }while(sentido<0 || sentido>1);
    return sentido;
}

void OrdenarWachinesXEdad(tipoN* vatos[],int tam)
{
    int sentido=meterSentido();
    tipoN aux;
    if (!sentido)
    {
        for(int i=0;i<tam-1;i++)
        {
            for(int j=1;j<tam;j++)
            {
                if(vatos[i]->age>vatos[j]->age)
                {
                    aux=*vatos[i];
                    vatos[i]=vatos[j];
                    *vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 ascendenmente amigueroooo \n");
    }
    if (sentido)
    {
        for(int i=0;i<tam-1;i++)
        {
            for(int j=1;j<tam;j++)
            {
                if(vatos[i]->age<vatos[j]->age)
                {
                    aux=*vatos[i];
                    *vatos[i]=*vatos[j];
                    *vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 adesendente mente  amigueroooo como los andes ndeeaaaa\n");
    }
}

/*void OrdenarWachinesXNombre(tipoN* vatos,int tam)
{
    tipoN aux;
    if(!meterSentido())
    {
        for (int i=0;i<tam-1;i++)
        {
            for(int j=1;i>tam;j++)
            {
                if(strcmp((vatos[i].name),(vatos[j].name))==1)
                {
                    aux=vatos[i];
                    vatos[i]=vatos[j];
                    vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 rey pa arshiba\n");
    }
    if (meterSentido())
     {
        for (int i=0;i<tam-1;i++)
        {
            for(int j=1;i>tam;j++)
            {
                if(strcmp(vatos[i].name,vatos[j].name)==-1)
                {
                    aux=vatos[i];
                    vatos[i]=vatos[j];
                    vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 rey pabajo. Hasta abajo mami, hasat abajo ndeeee\n");
    }

}*/
void OrdenarWachinesXNombre(tipoN* vatos[],int tam)
{
    tipoN aux;
    if(!meterSentido())
    {
        for (int i=0;i<tam-1;i++)
        {
            for(int j=1;i>tam;j++)
            {
                if(strcmp((vatos[i]->name),(vatos[j]->name))==1)
                {
                    aux=*vatos[i];
                    *vatos[i]=*vatos[j];
                    *vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 rey pa arshiba\n");
    }
    if (meterSentido())
     {
        for (int i=0;i<tam-1;i++)
        {
            for(int j=1;i>tam;j++)
            {
                if(strcmp(vatos[i]->name,vatos[j]->name)==-1)
                {
                    aux=*vatos[i];
                    *vatos[i]=*vatos[j];
                    *vatos[j]=aux;
                }
            }
        }
        printf("Ordena3 rey pabajo. Hasta abajo mami, hasat abajo ndeeee\n");
    }

}

int main()
{
    const int SIZE =10;
    int indice=0;
    tipoN* vatos= malloc(sizeof(tipoN)*SIZE);
    tipoN buffer;
    if(vatos==NULL)
    {
        printf("No se pudo mandar mecha amiguerooooooo\n");
        exit(1);
    }
    FILE* myFIle=fopen("empresa.dat","r");
    if(myFIle==NULL)
    {
        printf("No se abrio el archivo rey, anda a hacer noni\n");
        exit(1);
    }
    while(!feof(myFIle))
    {
        fread(&buffer,sizeof(tipoN),1,myFIle);
        vatos[indice]=buffer;
        indice++;
    }
    fclose(myFIle);
    tipoN** ptr=&vatos;
    char auxName[50];
    char aux[50];
    int salir=1,confirmar,auxNum;
    do{
        switch(menu())
        {
            case 1:
                    buffer= cargarDatos();
                    alta(ptr,buffer,SIZE);
                    break;
            case 2:

                    strcpy(auxName,pedirNombre(aux));
                    auxNum = buscarNombre(ptr,SIZE,auxName);
                    if (auxNum!=-1)
                    {
                        printf("Nombre encontrado man En el indice %d. Lo liquidamo?  Mete 0 x si.\n",auxNum);
                        fflush(stdin);
                        scanf("%d",&confirmar);
                        if(!confirmar)
                        {
                            if(!borrarWachin(ptr,auxNum))
                            {
                                printf("Caduco fiera. Ndeaaaa re rugbier era\n");
                            }
                            else
                            {
                                printf("No lo liquidamo.Disculpa amigo nose q salio mal○\n");
                            }
                        }
                        else
                        {
                            printf("Safo este gato. Si lo agarraba yo lo destruia. Ndeaaa quien era el man\n");
                        }
                    }
                    else
                    {
                        printf("No esta rey disculpame titanic\n");
                    }

                    break;
            case 3:
                    strcpy(auxName,pedirNombre(aux));
                    auxNum= buscarNombre(ptr,SIZE,auxName);
                    modificarWachin(ptr,auxNum);
                    printf("Modificatres lincre. Igual si pusiste el mismo num de neuvo sos 1 forro");

                    break;
            case 4:
                   imprimirWachines(ptr,SIZE);
                   break;
            case 5 :
                    OrdenarWachinesXEdad(ptr,SIZE);
                    break;
            case 6:
                    break;
            case 7:
                    printf("Seguro te queres tomar el palo? Manda 0 si si bb\n");
                    fflush(stdin);
                    scanf("%d",&confirmar);
                    if(!confirmar)
                    {
                        myFIle=fopen("empresa.dat","w");
                        if(myFIle==NULL)
                        {
                            printf("No se pudo abrir el archivo rey\n");
                            exit(1);
                            printf("Este printf no lo va a leer nadie asi q puedo decir lo q quiera. SOY GAYYYYYY");
                        }

                        printf("Hasta la vista, baby. FUAAAAAAa\n");
                        salir=0;


                    }
                    break;
            default:
                printf("Mete una q vlga salchicha ndeeee\n");
        }
    }while(salir!=0);

    printf("Es una wacha borracha floja de bombacha, mira a la atrevida, como se agacha, ndeeeeee\n");
    return 0;
}
