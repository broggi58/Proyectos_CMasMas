#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{
    char name[50];
    int age;
}sPerson;

int main()
{
    sPerson people[15];
    FILE* myFile = fopen("DAT.BIN","r");
    char nameInmput[50];
    int i=0,flag=-1;;
    if(myFile==NULL)
    {
        printf("No se pude abrir el archivo rey, pero si queres me podes abrir otra cosa ndeeee\n");
        exit(1);
    }
    while(!feof(myFile))
    {
        fread(people[i],sizeof(sPerson),1,myFile);
        i++;
    }
    printf("Archivo cargado re piola loro.Ndeeeeeeaaaaahh 1 sueñooooooooooooo!\n");
    printf("Mete el nombre a buscar perreke"));
    fflush(stdin);
    scanf("%s",nameInput);
    for(int j=0;j<=i;j++)
    {
       flag= strcmp(people[j].name,nameImput);
       if(flag==0)
       {
        printf("El nombre esta. Es %s y su edad es %d\n",people[i].name,people[i].age);
        break;
       }
    }
    if (flag==-1)
    {
        printf("Error. No se encontro el nombre, pero igual sabes donde encontrarme a mi ndeeeaaaaaa\n");
    }

    return 0;

}
