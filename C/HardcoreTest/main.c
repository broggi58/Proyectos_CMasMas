#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    char apellido[20];
    char pais[20];
}Wachin;
void ordenarXApellido(Wachin array[],int tam)
{

    Wachin aux;
    for (int i=0;i<tam;i++)
    {
        for(int j=i;j<tam;j++)
        {
            if(strcmp(array[i].apellido,array[j].apellido)==1)
            {
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    }
}
void printArray(Wachin array[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("%s    %s     %s\n",array[i].nombre,array[i].apellido,array[i].pais);
    }
}
int validarNombre(char name[],int tam)
{
    int retorno=0;
    if(strlen(name)>tam)
    {
        printf("Muy largo el nombre rey\n");
        retorno=1;
    }
    else if(strlen(name)==0)
    {
        printf("Mete un nombre la concha de tu madre\n");
        retorno=1;
    }
    for(int i=0;i<tam;i++)
    {
        if(name[i]=='0'||name[i]=='1'||name[i]=='2'||name[i]=='3'||name[i]=='4'||name[i]=='5'||name[i]=='6'||
           name[i]=='7'||name[i]=='8'||name[i]=='9')
        {
            printf("No van numeros en el nombre gil, mandale de nuevo\n");
            retorno=1;
            break;
        }
    }
    if(!retorno)
        printf("Bien alla dog lo embocaste `piola\n");
    return retorno;
}
int main()
{
    char name[20]="";
    int check=0;
    Wachin array[5]={{"gabi","perez","bolivia"},
    {"hernan","sanguinetto","virgolandia"},
    {"carlos","adfskjf","venezuela"},
    {"ivan","el trolazo","gayskol"},
    {"isabeeel","sape","usa"}};
    ordenarXApellido(array,5);
    printArray(array,5);
    printf("Manda un nombre rey\n");
    do{
    fflush(stdin);
    scanf("%[^\n]s ",name);
    check=validarNombre(name,20);
    }while(check);
    printf("Manda intro para salir rey\n");
    fflush(stdin);
    getchar();
    return 0;
}
