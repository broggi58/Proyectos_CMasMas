#include <stdlib.h>
#include "Concursantes.h"
#include <string.h>

/*static int isValidNumeroConcursante(char* numeroConcursante);

static int isValidAnioDeNacimiento(char* anio);

static int isValidNombre(char* nombre);

static int isValidDni(char* dni);

static int isValidFechaPresentacion(char* fecha);

static int isValidTemaPresentacion(char* temaPresentacion);

static int isValidPuntajePrimeraRonda(char* puntajePrimeraRonda);*/

int ListElement(eConcursante* concursante)
{
    int retorno;
   /* int numerodeConcursante;
    int anioDeNacimiento;
    char nombre[50];
    char dni[8];
    eFecha fechaDePresentacion;
    char temaDePresentacion[30];
    int puntajePrimeraRonda;*/
    retorno=-1;
    if(concursante!=NULL)
    {
        /*eConcursante_getnumeroConcursante(concursante,&numerodeConcursante);
        eConcursante_getAnioDeNacimiento(concursante,&anioDeNacimiento);
        eConcursante_getnombre(concursante,nombre);
        eConcursante_getdni(concursante,dni);
        eConcursante_getfecha(concursante,&fechaDePresentacion);
        eConcursante_gettemaDePresentacion(concursante,temaDePresentacion);
        eConcursante_getpuntajePrimeraRonda(concursante,&puntajePrimeraRonda);*/
        // printf("%2d %4d %10s %8s %2d/%2d/%4d %30s %2d\n",numerodeConcursante,anioDeNacimiento,nombre,dni,fechaDePresentacion.dia,fechaDePresentacion.mes,fechaDePresentacion.anio,temaDePresentacion,puntajePrimeraRonda);
         printf("%2d %4d %10s %8s %2d/%2d/%4d %30s %2d\n",concursante->numerodeConcursante,concursante->anioDeNacimiento,concursante->nombre,concursante->dni,concursante->fechaDePresentacion.dia,concursante->fechaDePresentacion.mes,concursante->fechaDePresentacion.anio,concursante->temaDePresentacion,concursante->puntajePrimeraRonda);
         retorno=0;
        // printf("%s",nombre);
    }

    return retorno;
}

eConcursante* concursante_new()
{
    eConcursante* concursante=(eConcursante*)malloc(sizeof(eConcursante));

    return concursante;
}

void parsear_Fecha(char* mesString,char* diaString,char* anioString,char* FechaString)
{
    if (FechaString!=NULL)
    {

        int i;
        for(i=0;i<=5;i++)
        {
            if(FechaString[i]=='/')
            {
                switch(i)
                {
                    case 1:
                        mesString[0]=FechaString[0];
                        mesString[1]='\0';
                    break;
                    case 2:
                        mesString[0]=FechaString[0];
                        mesString[1]=FechaString[1];
                        mesString[2]='\0';
                        break;
                    case 3:
                        diaString[0]=FechaString[2];
                        diaString[1]='\0';
                        anioString[0]=FechaString[4];
                        anioString[1]=FechaString[5];
                        anioString[2]=FechaString[6];
                        anioString[3]=FechaString[7];
                        anioString[4]='\0';
                        break;
                    case 4:
                        diaString[0]=FechaString[2];
                        diaString[1]=FechaString[3];
                        diaString[2]='\0';
                        anioString[0]=FechaString[5];
                        anioString[1]=FechaString[6];
                        anioString[2]=FechaString[7];
                        anioString[3]=FechaString[8];
                        anioString[4]='\0';
                        break;
                    case 5:
                        diaString[0]=FechaString[3];
                        diaString[1]=FechaString[4];
                        diaString[2]='\0';
                        anioString[0]=FechaString[6];
                        anioString[1]=FechaString[7];
                        anioString[2]=FechaString[8];
                        anioString[3]=FechaString[9];

                        break;
                }
            }
        }
    }
}

eConcursante* concursante_newParametros(char* numeroConcursanteString,char* anioDeNacimientoString,char* nombre,char* dni,char* FechaString,char* temaPresentacion,char* puntajePrimeraRondaString)
{
    eConcursante* concursante= concursante_new();
	int numeroConcursante;
    int anioDeNacimiento;
    int len;
    char nombreAux[50];
    char dniAux[8];
    eFecha fechaPresentacion;
    char temaPresentacionAux[30];
    int puntajePrimeraRonda;
    //int i;
    char diaString[3];
    char mesString[3];
    char anioString[5];
	if(concursante != NULL && numeroConcursanteString!=NULL && anioDeNacimientoString!=NULL && nombre!=NULL && dni!=NULL && FechaString!=NULL && temaPresentacion!=NULL && puntajePrimeraRondaString!=NULL)
	{
        numeroConcursante=atoi(numeroConcursanteString);
        anioDeNacimiento=atoi(anioDeNacimientoString);
        puntajePrimeraRonda=atoi(puntajePrimeraRondaString);

        parsear_Fecha(mesString,diaString,anioString,FechaString);
        fechaPresentacion.dia=(atoi(diaString));
        fechaPresentacion.mes=atoi(mesString);
        fechaPresentacion.anio=atoi(anioString);
        strcpy(nombreAux,nombre);
        strcpy(dniAux,dni);
        strcpy(temaPresentacionAux,temaPresentacion);
        eConcursante_setnumeroConcursante(concursante,numeroConcursante);
        eConcursante_setAnioDeNacimiento(concursante,anioDeNacimiento);
        eConcursante_setnombre(concursante,nombre);
        eConcursante_setdni(concursante,dniAux);
        eConcursante_setfecha(concursante,fechaPresentacion);
        eConcursante_setpuntajePrimeraRonda(concursante,puntajePrimeraRonda);
        eConcursante_settemaPresentacion(concursante,temaPresentacionAux);

	}
    return concursante;
}

int eConcursante_setnumeroConcursante(eConcursante* this,int numeroConcursante)
{
	int result;
	result=-1;
	if(this != NULL && numeroConcursante > 0 )
	{
        this->numerodeConcursante=numeroConcursante;
        result=0;
	}
    return result;
}

int eConcursante_getnumeroConcursante(eConcursante* this,int* numeroConcursante)
{
	int result;
	result=-1;
	if(this != NULL && numeroConcursante!=NULL )
	{
        *numeroConcursante=this->numerodeConcursante;
        result=0;
	}
    return result;
}

int eConcursante_setAnioDeNacimiento(eConcursante* this,int anioDeNacimiento)
{
	int result;
	result=-1;
	if(this != NULL && anioDeNacimiento > 0 )
	{
        this->anioDeNacimiento=anioDeNacimiento;
        result=0;
	}
    return result;
}

int eConcursante_getAnioDeNacimiento(eConcursante* this,int* anioDeNacimiento)
{
	int result;
	result=-1;
	if(this != NULL && anioDeNacimiento!=NULL)
	{
        *anioDeNacimiento=this->anioDeNacimiento;
        result=0;
	}
    return result;
}
int eConcursante_setnombre(eConcursante* this,char* nombre)
{
	int result;
	result=-1;
	if(this != NULL && nombre > 0 )
	{
        strcpy(this->nombre,nombre);
        result=0;
	}
    return result;
}

int eConcursante_getnombre(eConcursante* this,char* nombre)
{
	int result;
	result=-1;

	if(this != NULL && nombre!=NULL)
	{
        strcpy(nombre,this->nombre);
        result=0;
	}
    return result;
}
int eConcursante_setdni(eConcursante* this,char* dni)
{
	int result;
	result=-1;
	if(this != NULL && strlen(dni)>=7 && strlen(dni)<=8  )
	{
        strcpy(this->dni,dni);
        result=0;
	}
    return result;
}

int eConcursante_getdni(eConcursante* this,char* dni)
{
	int result;
	result=-1;
	if(this != NULL && dni!=NULL )
	{
        strcpy(dni,this->dni);
        result=0;
	}
    return result;
}
int eConcursante_setfecha(eConcursante* this,eFecha fecha)
{
	int result;
	result=-1;
	if(this != NULL  )
	{
        this->fechaDePresentacion=fecha;
        //strcpy(this->fechaDePresentacion,fecha);
        result=0;
	}
    return result;
}

int eConcursante_getfecha(eConcursante* this,eFecha* fecha)
{
	int result;
	result=-1;
	if(this != NULL && fecha!=NULL )
	{
        *fecha=this->fechaDePresentacion;
        //strcpy(fecha,this->fechaDePresentacion);
        result=0;
	}
    return result;
}
int eConcursante_setpuntajePrimeraRonda(eConcursante* this,int puntajePrimeraRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajePrimeraRonda > 0 )
	{
        this->puntajePrimeraRonda=puntajePrimeraRonda;
        result=0;
	}
    return result;
}

int eConcursante_getpuntajePrimeraRonda(eConcursante* this,int* puntajePrimeraRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajePrimeraRonda!=NULL )
	{
        *puntajePrimeraRonda=this->puntajePrimeraRonda;
        result=0;
	}
    return result;
}
int eConcursante_settemaPresentacion(eConcursante* this,char* temaPresentacion)
{
	int result;
	result=-1;
	if(this != NULL && strlen(temaPresentacion)> 0 )
	{
        strcpy(this->temaDePresentacion,temaPresentacion);
        result=0;
	}
    return result;
}

int eConcursante_gettemaDePresentacion(eConcursante* this,char* temaPresentacion)
{
	int result;
	result=-1;
	if(this != NULL && temaPresentacion!=NULL )
	{
        strcpy(temaPresentacion,this->temaDePresentacion);
        result=0;
	}
    return result;
}

int eConcursante_setpuntajeSegundaRonda(eConcursante* this,int puntajeSegundaRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajeSegundaRonda > 0 && puntajeSegundaRonda<=100 )
	{
        this->puntajeSegundaRonda=puntajeSegundaRonda;
        result=0;
	}
    return result;
}

int eConcursante_getpuntajeSegundaRonda(eConcursante* this,int* puntajeSegundaRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajeSegundaRonda!=NULL)
	{
        *puntajeSegundaRonda=this->puntajeSegundaRonda;
        result=0;
	}
    return result;
}

int eConcursante_setpuntajePromedio(eConcursante* this,float puntajePromedio)
{
	int result;
	result=-1;
	if(this != NULL && puntajePromedio > 0 && puntajePromedio<=100 )
	{
        this->puntajePromedio=puntajePromedio;
        result=0;
	}
    return result;
}

int eConcursante_getpuntajePromedio(eConcursante* this,float* puntajePromedio)
{
	int result;
	result=-1;
	if(this != NULL && puntajePromedio!=NULL)
	{
        *puntajePromedio=this->puntajePromedio;
        result=0;
	}
    return result;
}

int eConcursante_getpuntajeTerceraRonda(eConcursante* this,int* puntajeTerceraRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajeTerceraRonda!=NULL)
	{
        *puntajeTerceraRonda=this->puntajeTerceraRonda;
        result=0;
	}
    return result;
}

int eConcursante_setpuntajeTerceraRonda(eConcursante* this,int puntajeTerceraRonda)
{
	int result;
	result=-1;
	if(this != NULL && puntajeTerceraRonda > 0 && puntajeTerceraRonda<=100 )
	{
        this->puntajeTerceraRonda=puntajeTerceraRonda;
        result=0;
	}
    return result;
}

int calificarSegundaEtapa(eConcursante* concursante)
{
    int retorno;
    int num;
    int puntajePrimeraRonda;
    //int puntajeSegundaRonda;
    float puntajePromedio;
    retorno=1;
    if(concursante==NULL)
    {
        retorno=0;
    }
    num= (rand() %100) +1;
    eConcursante_setpuntajeSegundaRonda(concursante,num);
    eConcursante_getpuntajePrimeraRonda(concursante,&puntajePrimeraRonda);
    puntajePromedio=(float) (puntajePrimeraRonda+num)/2;
    eConcursante_setpuntajePromedio(concursante,puntajePromedio);
    return retorno;
}
int guardarResultados (char* path,LinkedList* listaConcursantes)
{
    int retorno;
    char nombreArchivo[100]="\0";
        FILE* pFile;
    int size;
    int i;
    int puntajeSegundaRonda;
    float puntajePromedio;
    eConcursante* concursanteAux;
    retorno=0;
    if(path==NULL || listaConcursantes==NULL)
    {
        retorno=-1;

    }
    else
    {
        size=ll_len(listaConcursantes);
        //nombreArchivo=newString(100);
        //nombreArchivo="resultado";
        fflush(stdin);
        printf("%s",nombreArchivo);
        strcat(nombreArchivo,"resultado");
        strcat(nombreArchivo,path);
       // printf("%s",nombreArchivo);
        pFile=fopen(nombreArchivo,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<size;i++)
            {
                concursanteAux=(eConcursante*)ll_get(listaConcursantes,i);
                //concursanteAux=NULL;
                if(concursanteAux!=NULL)
                {
                    eConcursante_getpuntajeSegundaRonda(concursanteAux,&puntajeSegundaRonda);
                    eConcursante_getpuntajePromedio(concursanteAux,&puntajePromedio);
                    //printf("Ndeaaaa %f\n",*puntajePromedio);
                    fprintf(pFile,"%d , %f \n",puntajeSegundaRonda,puntajePromedio);

                }

            }
            fclose(pFile);
        }
        else
        {
            printf("Error. No se pudo abrir el archivo.\n");
        }

    }



    return retorno;
}
int checkearConcursante (eConcursante* concursante)
{
    int retorno;
    int puntajeAux;
    retorno=0;
    if(concursante!=NULL )
    {
        eConcursante_getpuntajePrimeraRonda(concursante,&puntajeAux);
        if(puntajeAux>70)
        {
            retorno=1;
        }
    }
    return retorno;
}
int  ObtenerNotasMasAltas(LinkedList* listaConcursantes,int notasMaximas[])
{
    int i;
    int j;
    int size;
    int puntajePrimeraRonda;
    eConcursante* aux;
    for(j=0;j<3;j++)
    {
        notasMaximas[j]=0;
    }
    if(listaConcursantes!=NULL)
    {
        size=ll_len(listaConcursantes);
        for(i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            if(aux!=NULL)
            {
                eConcursante_getpuntajePrimeraRonda(aux,&puntajePrimeraRonda);
                if(puntajePrimeraRonda>notasMaximas[0])
                {
                    notasMaximas[2]=notasMaximas[1];
                    notasMaximas[1]=notasMaximas[0];
                    notasMaximas[0]=puntajePrimeraRonda;
                }
                else if(puntajePrimeraRonda>notasMaximas[1])
                {
                    notasMaximas[2]=notasMaximas[1];
                    notasMaximas[1]=puntajePrimeraRonda;
                }
                else if(puntajePrimeraRonda>notasMaximas[2])
                {
                    notasMaximas[2]=puntajePrimeraRonda;
                }
            }
        }
    }
    return 1;
}
int  ObtenerNotasMasAltasEtapaTres(LinkedList* listaConcursantes,int notasMaximas[])
{
    int i;
    int j;
    int size;
    int puntajePrimeraRonda;
    eConcursante* aux;
    for(j=0;j<3;j++)
    {
        notasMaximas[j]=0;
    }
    if(listaConcursantes!=NULL)
    {
        size=ll_len(listaConcursantes);
        for(i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            if(aux!=NULL)
            {
                eConcursante_getpuntajePrimeraRonda(aux,&puntajePrimeraRonda);
                if(puntajePrimeraRonda>notasMaximas[0])
                {
                    notasMaximas[2]=notasMaximas[1];
                    notasMaximas[1]=notasMaximas[0];
                    notasMaximas[0]=puntajePrimeraRonda;
                }
                else if(puntajePrimeraRonda>notasMaximas[1])
                {
                    notasMaximas[2]=notasMaximas[1];
                    notasMaximas[1]=puntajePrimeraRonda;
                }
                else if(puntajePrimeraRonda>notasMaximas[2])
                {
                    notasMaximas[2]=puntajePrimeraRonda;
                }
            }
        }
    }
    return 1;
}

int FiltrarConcursante(eConcursante* concursante,int notasMaximas[])
{
    int retorno;
    //int num;
    int puntajePrimeraRonda;
    int i;
    //int puntajeSegundaRonda;
    //float puntajePromedio;
    retorno=0;
    if(concursante==NULL && notasMaximas==NULL)
    {
        retorno=-1;
    }
    else
    {
        eConcursante_getpuntajePrimeraRonda(concursante,&puntajePrimeraRonda);
        for(i=0;i<3;i++)
        {
            if(puntajePrimeraRonda>=notasMaximas[i])
            {
                retorno=1;
                break;
            }
        }
    }


    return retorno;
}
int FiltrarConcursantes(eConcursante* concursante,int notaReferencia)
{
    int retorno;
    //int num;
    int puntajePrimeraRonda;
   // int i;
    //int puntajeSegundaRonda;
    //float puntajePromedio;
    retorno=0;
    if(concursante==NULL )
    {
        retorno=-1;
    }
    else
    {
        eConcursante_getpuntajePrimeraRonda(concursante,&puntajePrimeraRonda);


            if(puntajePrimeraRonda>=notaReferencia)
            {

                retorno=1;


            }

    }

    return retorno;
}

int FiltrarConcursanteTerceraRonda(eConcursante* concursante,int notaReferencia)
{
    int retorno;
    int num;
    int puntajeTerceraRonda;
    int i;
    //int puntajeSegundaRonda;
    //float puntajePromedio;
    retorno=0;
    if(concursante==NULL )
    {
        retorno=-1;
    }
    else
    {
        eConcursante_getpuntajeTerceraRonda(concursante,&puntajeTerceraRonda);

            if(puntajeTerceraRonda>=notaReferencia)
            {
                retorno=1;

            }

    }


    return retorno;
}

int calificarTerceraEtapa(eConcursante* concursante)
{
    int retorno;
    int num;
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    //int puntajeSegundaRonda;
    float puntajePromedio;
    retorno=1;
    if(concursante==NULL)
    {
        retorno=0;
    }
    num= (rand() %100) +1;
    eConcursante_getpuntajeSegundaRonda(concursante,&puntajeSegundaRonda);
    eConcursante_getpuntajePrimeraRonda(concursante,&puntajePrimeraRonda);
    eConcursante_setpuntajeTerceraRonda(concursante,num);
    puntajePromedio=(float) (puntajePrimeraRonda+puntajeSegundaRonda+num)/3;
    eConcursante_setpuntajePromedio(concursante,puntajePromedio);
    return retorno;
}

int eConcursante_CompareByNotaPrimeraEtapa(eConcursante* c1, eConcursante* c2)
{

    int result;
    int puntaje1;
    int puntaje2;
    if(c1 !=NULL && c2!=NULL)
    {
        eConcursante_getpuntajePrimeraRonda(c1,&puntaje1);
    eConcursante_getpuntajePrimeraRonda(c2,&puntaje2);

    }


    result=0;
    if(puntaje1>puntaje2)
    {
        result=1;
    }
    else if(puntaje1<puntaje2)
    {
        result=-1;
    }

    return result;
}

int eConcursante_CompareByNumeroConcursante(eConcursante* c1, eConcursante* c2)
{

    int result;
    int numeroConcursante1;
    int numeroConcursante2;
    if(c1 !=NULL && c2!=NULL)
    {
        eConcursante_getnumeroConcursante(c1,&numeroConcursante1);
    eConcursante_getnumeroConcursante(c2,&numeroConcursante2);

    }


    result=0;
    if(numeroConcursante1>numeroConcursante2)
    {
        result=1;
    }
    else if(numeroConcursante1<numeroConcursante2)
    {
        result=-1;
    }

    return result;
}
int ObtenerNotaDeReferencia(LinkedList* listaConcursantes,int size)
{
    int retorno;
    int cantidadDeFinalistas;
    int notaReferencia;
    eConcursante* aux=concursante_new();
    retorno=-1;
    if(!utn_getInt(&cantidadDeFinalistas,"Ingresar cuantos finalistas clasifican:\n","Error. Numero invalido.",1,size,3) && aux!=NULL)
    {

        ll_sort(listaConcursantes,eConcursante_CompareByNotaPrimeraEtapa,0);
       /* for(int i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            ListElement(aux);
        }*/

        aux=ll_get(listaConcursantes,cantidadDeFinalistas-1);

        if(aux!=NULL)
        {
            eConcursante_getpuntajePrimeraRonda(aux,&notaReferencia);



            ll_sort(listaConcursantes,eConcursante_CompareByNumeroConcursante,1);
            /*for(int i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            ListElement(aux);
        }*/
            retorno=notaReferencia;
         //   printf("%d",retorno);

        }
        else
        {
            retorno=-1;
        }

    }
    else
    {
        retorno=-1;
    }
    free(aux);
    return retorno;
}
int eConcursante_CompareByNotaTerceraEtapa(eConcursante* c1, eConcursante* c2)
{

    int result;
    int puntaje1;
    int puntaje2;
    if(c1 !=NULL && c2!=NULL)
    {
        eConcursante_getpuntajeTerceraRonda(c1,&puntaje1);
        eConcursante_getpuntajeTerceraRonda(c2,&puntaje2);

    }


    result=0;
    if(puntaje1>puntaje2)
    {
        result=1;
    }
    else if(puntaje1<puntaje2)
    {
        result=-1;
    }

    return result;
}

int ObtenerNotaDeReferenciaEtapaTres(LinkedList* listaConcursantes,int size)
{
    int retorno;
    int cantidadDeFinalistas;
    int notaReferencia;
    eConcursante* aux=concursante_new();
    retorno=-1;
    if(!utn_getInt(&cantidadDeFinalistas,"Ingresar cuantos finalistas clasifican:\n","Error. Numero invalido.",1,size,3) && aux!=NULL)
    {

        ll_sort(listaConcursantes,eConcursante_CompareByNotaTerceraEtapa,0);
       /* for(int i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            ListElement(aux);
        }*/

        aux=ll_get(listaConcursantes,cantidadDeFinalistas);

        if(aux!=NULL)
        {
            eConcursante_getpuntajeTerceraRonda(aux,&notaReferencia);



            ll_sort(listaConcursantes,eConcursante_CompareByNumeroConcursante,1);
            /*for(int i=0;i<size;i++)
        {
            aux=ll_get(listaConcursantes,i);
            ListElement(aux);
        }*/
            retorno=notaReferencia;


        }
        else
        {
            retorno=-1;
        }

    }
    else
    {
        retorno=-1;
    }
    free(aux);
    return retorno;
}

int Desempatar(LinkedList* this,int* size,int cantidad)
{
    int retorno;

    if(this!=NULL )
    {
        ll_sortV2(this,eConcursante_CompareByNotaTerceraEtapa,eConcursante_CompareByNotaPrimeraEtapa,0);
        while(size!=cantidad)
        {
            ll_remove(this,0);
            *size--;
        }
        retorno=0;

    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
/*int GuardarArchivo(eConcursante* concursante)
{
    FILE* myFile;
    char* extension=".csv";
    char nombreArchivo[100]="\0";
    int numerodeConcursante;
    int anioDeNacimiento;
    char nombre[50];
    char dni[8];
    eFecha fechaDePresentacion;
   // char fechaDePresentacion[10];
    char temaDePresentacion[30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float puntajePromedio;
    if(concursante!=NULL)
    {

    }
}*/
/*char* newString (int num)
{
    char* string=(char*)malloc((sizeof(char)*num));
    return string;
}*/
/*static int isValidNumeroConcursante(char* numeroConcursante)
{
    int retorno;
    if(numeroConcursante!=NULL && isDigit(numeroConcursante))
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
static int isValidAnioDeNacimiento(char* anio)
{
    int retorno;
    if(anio!=NULL && strlen(anio)==4 && isDigit(anio))
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    int retorno;
    if(nombre!=NULL && strlen(nombre)<=50 && isAlpha(nombre))
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

static int isValidDni(char* dni)
{
    int retorno;
    if(dni!=NULL && strlen(dni)>=8 && strlen(dni)<=9 && isDigit(dni))
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

static int isValidFechaPresentacion(char* fecha)
{
    int retorno;
    if(fecha!=NULL && strlen(fecha)>=8 && strlen(fecha)<=10)
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

static int isValidTemaPresentacion(char* temaPresentacion)
{
    int retorno;
    if(temaPresentacion!=NULL && strlen(temaPresentacion)<=30)
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

static int isValidPuntajePrimeraRonda(char* puntajePrimeraRonda)
{
    int retorno;
    if(puntajePrimeraRonda!=NULL && isDigit(puntajePrimeraRonda))
    {
     retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}*/
