#include <stdlib.h>
#include <stdio.h>
#include "string.h"
typedef struct
{
    char name[50];
    int age;
}sPerson;

int main()
{
    sPerson person[15];
    int i=0;
    FILE* personFile= fopen("BIN.DAT","w");
    if (personFile==NULL)
    {
        printf("Error. La cagaste rey ndeeeeeeeeee\n");
        exit(1);
    }
    while(i<15)
    {
    printf("Para dejar de escribir cositas mete parar en el nombre rey uwu. Y desp pensa lo q te dije\n");
    printf("mETE EL nombre rey.dale rey. Me das un beso rey? \n ndeaaaaah re puto era jajjajja.");
    printf("Dale me das o no? jajja ah seguia. Te estoy jodiendo rey. A menos q quieras. Queres o no?\n");
    fflush(stdin);
    scanf("%s",person[i].name);
    if(strcmp(person[i].name,"parar")==0)
    {
        break;
    }
    printf("Ahora meteme la edad. A menos q me quieras meter otra cosa ajjaj. Te estoy jodiendo. A menos q me la quieras meter\n");
    printf("Vo decime rey nose. jajja mentira. pero si queres decime rey sin compromiso\n");
    fflush(stdin);
    scanf("%d",&person[i].age);
    i++;
    }
    if(i)
    {
    fwrite(&person,sizeof(person),i,personFile);
    }

    fclose(myFile);

    return 0;
    }
