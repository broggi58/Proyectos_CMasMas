#include "pais.h"
#include "arrayMascotas.h"
#include "arrayRazas.h"
void HardcodearPaises(ePais paises[],int tamPaises)
{
    int i;
    ePais buffer[5]={{"Tailandia",1,66,1},{"Persia",1,98,2},{"Alemania",2,49,3},{"Belgica",2,32,4},{"Argentina",3,54,5}};
    for(i=0;i<tamPaises;i++)
    {
        paises[i]=buffer[i];
    }
}
void HardcodearContinentes(eContinente continentes[],int tamContinentes)
{
    int i;
    eContinente buffer[5]={{1,"Asia"},{2,"Europa"},{3,"America"},{4,"Africa"},{5,"Oceania"}};
    for(i=0;i<tamContinentes;i++)
    {
        continentes[i]=buffer[i];
    }
}
void MostrarPaises(ePais paises[],int tamPaises,eContinente continentes[], int tamContinentes)
{
    int i;
    int c1;
    printf("ID              Pais            Continente\n");
    for (i=0;i<tamPaises;i++)
    {
        c1=BuscarContinente(continentes,tamContinentes,paises[i].idContinente);
        printf("%d    %15s   %15s   \n",paises[i].idPais,paises[i].nombreDePais,continentes[c1].descripcion);
    }
}

int BuscarPais(ePais paises [],int tamPaises, int idPais)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamPaises;i++)
    {
        if( paises[i].idPais== idPais)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int BuscarContinente(eContinente continentes [],int tamContinentes, int idContinente)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamContinentes;i++)
    {
        if( continentes[i].idContinente== idContinente)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
