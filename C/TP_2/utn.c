#include "utn.h"

int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno=-1;
	char buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimo <= maximo && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);
			if(buffer >=minimo && buffer <=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno=-1;
	int buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimo <= maximo && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&buffer);
			if(buffer >=minimo && buffer <=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos)
{
	int retorno=-1;
	float buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimo <= maximo && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&buffer);
			if(buffer >=minimo && buffer <=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_getString(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos)
{
	int retorno=-1;
	char  buffer[4000];
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimoCaracteres <= maximoCaracteres && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%s",buffer);
			if(strlen(buffer) >=minimoCaracteres && strlen(buffer) <=maximoCaracteres)
			{
				strcpy(pResultado,buffer);
				retorno=0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
