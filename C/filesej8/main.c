#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef struct
{ char nom[30] , dir[30] ;
    int cp , nro_cli;
}cliente;

typedef struct
{
    char nom[30];
    int nro_cli;
}clienteMini;


int main()
{
    cliente persona;
    clienteMini datos;
    FILE* myFile=fopen("clientes.dat","w");
    FILE* myFile2=fopen("asdakmd.dat","w");
    if(myFile==NULL)
    {
        printf("No se abrio rey q quere . Anda a jugar al valoran\n");
        exit(1);
    }
    if(myFile2== NULL)
    {
        printf("Nooo borooo alto sueño. No e abre el archivo handa a hacer noni\n");
        exit(1);
    }
    strcpy(persona.nom,"Tito");
    strcpy(persona.dir,"Chicago 456");
    persona.cp=1998;
    persona.nro_cli=154;
    fwrite(&persona,sizeof(cliente),1,myFile);
    strcpy(datos.nom,persona.nom);
    datos.nro_cli=persona.nro_cli;
    fwrite(&datos,sizeof(clienteMini),1,myFile2);
    fclose(myFile);
    fclose(myFile2);
    printf("Hello world!\n");
    return 0;
}
