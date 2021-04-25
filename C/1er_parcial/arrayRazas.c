#include "arrayMascotas.h"
#include "arrayRazas.h"

int initRazas(eRaza list[], int len)
{
    int retorno;
    int i;
    retorno=-1;
    if(list!=NULL || len!=10)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }
 return retorno;
}



void HardcodearTamanios (eTamanio tamanio[])
{
    int i;
    eTamanio buffer[3]= {{"chico",1},{"mediano",2},{"grande",3}};

    for(i=0;i<3;i++)
    {
        tamanio[i]=buffer[i];
    }
}
void HardcodearRazas (eRaza razas[])
{
    int i;
    eRaza buffer[6]= {{"siames",1,1,1,0},{"doberman",3,2,3,0},{"persa",2,3,2,0},{"pastor belga",3,4,4,0},{"dogo argentino",3,5,5,0},{"pastor aleman",3,6,3,0}};

    for(i=0;i<6;i++)
    {
        razas[i]=buffer[i];
    }
}

int BuscarRaza(eRaza razas [],int tamRazas, int idRaza)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamRazas;i++)
    {
        if( razas[i].idRaza== idRaza && razas[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int BuscarTamanio(eTamanio tamanios [],int tamTamanios, int idTamanio)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamTamanios;i++)
    {
        if( tamanios[i].idTam== idTamanio)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void MostrarRazas(eRaza razas[], int tamRazas,eTamanio tamanios[],int tamTamanios,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes)
{
    int i;
    int t;
    int p1;
    int c1;
    printf("Raza                      tamanio        pais             continente Codigo  ID\n");
    for(i=0;i<tamRazas;i++)
    {
        p1=BuscarPais(paises,tamPaises,razas[i].idPais);
        c1=BuscarContinente(continentes,tamContinentes,paises[p1].idContinente);
        t=BuscarTamanio(tamanios,tamTamanios,razas[i].idTam);
        if(razas[i].isEmpty==0)
        {
           printf("%15s  %15s  %15s  %15s      %d    %d\n",razas[i].descripcion,tamanios[t].descripcion,paises[p1].nombreDePais,continentes[c1].descripcion,paises[p1].CodigoTelefonico,razas[i].idRaza);
        }

    }
}

int BuscarRazaLibre(eRaza razas[],int tamRazas)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamRazas;i++)
    {
      if(razas[i].isEmpty==1)
      {
          indice=i;
      }
    }
    return indice;
}
int AgregarRaza(eRaza razas[], int tamRaza, int idTam,int idPais,int idRaza,char descripcion[])
{
    int retorno;
    int indice;
    retorno=-1;
    indice= BuscarRazaLibre(razas,tamRaza);
    if(indice>=0)
    {
        razas[indice].idRaza=idRaza;
        strcpy(razas[indice].descripcion,descripcion);
        razas[indice].idTam=idTam;
        razas[indice].idPais=idPais;

        razas[indice].isEmpty=0;
        retorno=0;
    }

  return retorno;
}
int CrearRaza (eRaza razas[],int tamRazas,int idRaza,ePais paises[],int tamPaises,eContinente continentes[],int tamContinentes)
{
    int retorno;
    retorno=-1;
    eRaza raza;
    MostrarPaises(paises,tamPaises,continentes,tamContinentes);
    if(utn_getString(raza.descripcion,"Ingrese nombre de la raza: \n","Error. Nombre invalido.\n",2,19,3)==0)
    {
        if(utn_getInt(&raza.idTam,"Ingresar tamanio (1- chico, 2- mediano, 3- grande):\n","Error. Tamanio invalido",1,3,
                      3)==0)
        {
            if(utn_getInt(&raza.idPais,"Ingresar pais de origen: \n","Error. Pais invalido.\n",1,5,3)==0)
            {
                retorno= AgregarRaza (razas,tamRazas,raza.idTam,raza.idPais,raza.idRaza,raza.descripcion);
            }

        }
    }
    return retorno;
}

int RemoverRaza(eRaza razas[], int tamRaza, int idRaza)
{
    int retorno;
    int indice;
    retorno=-1;
    if(razas!=NULL|| tamRaza!=10)
    {
        indice= BuscarRaza(razas,tamRaza,idRaza);
    }
    if(indice>=0)
    {
        razas[indice].isEmpty=1;
        retorno=0;
    }
 return retorno;
}

int BuscarRazaPorTamanio(eRaza razas [],int tamRazas, int idTamanio)
{
    int indice;
    int i;
    indice=-1;
    for(i=0;i<tamRazas;i++)
    {
        if( razas[i].idTam== idTamanio && razas[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void MostrarTamanios(eTamanio tamanios[],int tamTamanios)
{
    int i;
    printf("ID    Tamanio\n");
    for(i=0;i<tamTamanios;i++)
    {
        printf("%d    %10s\n",tamanios[i].idTam,tamanios[i].descripcion);
    }
}
