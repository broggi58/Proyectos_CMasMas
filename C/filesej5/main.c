#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* myFile=fopen("DAT.BIN","r");
    char buscar[50];
    char buffer;
    char data[1000];
    int i=0;
    char* ptrName;

    if (myFile==NULL)
    {
        printf("Error. no se cargo pero no pasa nada si queres ya q estas me podes pasar a visitar x casa sin compromiso jaja\n");
        printf("Ndee jajaja re trolo. Na pero igual estoy solo si queres veni jajja seguia. Tocame timbre");
        exit(1);
    }
    printf("Mete el string y bueno si el archivo anda no vas a poder leer lo q puse pero te lo resumo aca. Venite estoy solo si queres\n");
    scanf("%s",buscar);
    while((buffer = fgetc(myFile))!= EOF)
    {
        data[i]=buffer;
        i++;
    }
    ptrName=strstr(data,buscar);
    if (ptrName==NULL)
    {
        printf("No se encontro lo q buscabas rey. Pero si me queres encontrar a mi ya sabes odnde encontrarme\n");
    }
    else
    {
        printf("Buena man, la clavaste esta aca lo q buscabas. Igual si queres pasate x casa nose vofijate");
    }



    printf("Hello world!\n");
    return 0;
}

