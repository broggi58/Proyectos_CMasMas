#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer;
    FILE* myFile=fopen("BIN.DAT","r");
    if (myFile==NULL)
    {
        printf("Error rey, no se puede leer titanic. Pero si queres podemos hacer otra cosa ajjajjaj vofi\n");
        exit(1);
    }
    while ((buffer =fgetc(myFile))!=EOF)
    {
        printf("%c",buffer);
    }


    fclose(myFile);

    return 0;
}
