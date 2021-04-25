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
    sPerson person[15];
    int i=0;
    FILE* personFile = fopen("BIN.DAT","a");
    if (personFile==NULL)
    {
        printf("Error rey. Dedicate a otra cosa. Si queres podes probar conmigo ndeeeeee\n");
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
    else{
        printf("No metiste nada en el archivo dog. pero no pasa uan si queres me podes meter algo a mi.\n");
        printf("Ndeaaa re trolo era. Na pero posta si queres meteme algo jajja seguia. A menos q quieras, vo decime");
    }

    fclose(personFile);

    printf("Hello world!\n");
    return 0;
}
