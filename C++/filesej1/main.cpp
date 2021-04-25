#include <iostream>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    int age;
}sPerson;


using namespace std;

int main()
{
    sPerson person;
    FILE* personFile= fopen("BIN.DAT","w");
    if (personFile==NULL)
    {
        printf("Error. La cagaste rey ndeeeeeeeeee\n");
        exit(1);
    }

    printf("mETE EL nombre rey.dale rey. Me das un beso rey? \n ndeaaaaah re puto era jajjajja.");
    printf("Dale me das o no? jajja ah seguia. Te estoy jodiendo rey. A menos q quieras. Queres o no?\n");
    fflush(stdin);
    scanf("%s",person.name);
    printf("Ahora meteme la edad. A menos q me quieras meter otra cosa ajjaj. Te estoy jodiendo. A menos q me la quieras meter\n");
    printf("Vo decime rey nose. jajja mentira. pero si queres decime rey sin compromiso\n");
    fflush(stdin);
    scanf("%d",&person.age);
    fwrite(&person,sizeof(person),1,personFile);




    return 0;
    }


