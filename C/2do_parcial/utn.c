#include "utn.h"
int isDigit(char* string)
{
	int retorno;
	int i;
	i=0;
	retorno=-1;
	if(string!=NULL)
	{
		retorno=0;
		while(string[i]!='\0')
		{
			if(string[i]=='0'||string[i]=='1'||string[i]=='2'||string[i]=='3'||string[i]=='4'||string[i]=='5'||string[i]=='6'||string[i]=='7'||string[i]=='8'||string[i]=='9')
			{
				retorno=1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int isAlpha(char* string)
{
	int retorno;
	int i;
	i=0;
	retorno=-1;
	if(string!=NULL)
	{
		retorno=0;
		while(string[i]!='\0')
		{
			if(string[i]!='0'||string[i]!='1'||string[i]!='2'||string[i]!='3'||string[i]!='4'||string[i]!='5'||string[i]!='6'||string[i]!='7'||string[i]!='8'||string[i]!='9')
			{
				retorno=1;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getCaracterSex(char* pResultado,char* mensaje, char* mensajeError, char uno,char dos,int reintentos)
{
	int retorno=-1;
	char buffer;
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL  && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&buffer);
			if(buffer ==uno || buffer ==dos)
			{
				*pResultado=buffer;
				retorno=0;
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

int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos)
{
	int retorno=-1;
	char buffer[4000];
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
int utn_getStringName(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos)
{
	int retorno=-1;
	char  buffer[4000];
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimoCaracteres <= maximoCaracteres && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%s",buffer);
			if(strlen(buffer) >=minimoCaracteres && strlen(buffer) <=maximoCaracteres && !isDigit(buffer))
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

int utn_getStringNumber(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos)
{
	int retorno=-1;
	char  buffer[4000];
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!= NULL && minimoCaracteres <= maximoCaracteres && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%s",buffer);
			if(strlen(buffer) >=minimoCaracteres && strlen(buffer) <=maximoCaracteres && !isAlpha(buffer))
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
