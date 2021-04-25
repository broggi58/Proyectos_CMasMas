#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    int numeroConcursante;
    int anioDeNacimiento;
    char dni[8];
    char fechaPresentacion[10];
    char temaPresentacion[30];
    int puntajePrimeraRonda;
}eConcursante;

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;

//Publicas
LinkedList* ll_newLinkedList();

int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

int isDigit(char* string);

int isAlpha(char* string);

int utn_getCaracter(char* pResultado,char* mensaje, char* mensajeError, char minimo,char maximo,int reintentos);

int utn_getInt(int* pResultado,char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje, char* mensajeError, float minimo,float maximo,int reintentos);

int utn_getString(char* pResultado,char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

int utn_getCaracterSex(char* pResultado,char* mensaje, char* mensajeError, char uno,char dos,int reintentos);

int utn_getStringName(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

int utn_getStringNumber(char pResultado[],char* mensaje, char* mensajeError, int minimoCaracteres,int maximoCaracteres,int reintentos);

int ListElement(eConcursante* concursante);

void PrintOptions();

int menu();

void PrintOptionsLoad();

int menuLoad();

int controller_loadFromText(LinkedList* listaConcursantes);


int controller_listElements(LinkedList* listaConcursantes);

int parser_FromText(FILE* pFile, LinkedList* listaConcursantes,char* path);

int main()
{
    int idConcursante;
    int idConcursanteParaBuscar;
    int salir;
    int confirmarSalir;

    LinkedList* listaConcursantes=ll_newLinkedList();


    do{
        switch(menu())
        {

        case 1:

                    controller_loadFromText(listaConcursantes);
                break;
            case 2:


                    controller_listElements(listaConcursantes);
                    break;

            case 3:

                    utn_getInt(&confirmarSalir,"Confirmar salida? Introducir 1 para confirmar o 2 para continuar.\n","Error. Opcion invalida.\n",1,2,22);
                    if(confirmarSalir==1)
                    {
                        salir=1;
                    }

                    break;
    }
    }while(salir!=1);

    printf("Hello world!\n");
    return 0;
}


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
int ListElement(eConcursante* concursante)
{
    printf("Numero de concursante   anio de nacimiento   D.N.I.   Fecha de presentacion   Tema de presentacion   Puntaje primera ronda\n");
    printf("%d  %d  %8s  %d/%d/%d  %s  %d\n",concursante->numeroConcursante,concursante->anioDeNacimiento,concursante->dni,concursante->fechaPresentacion.dia,concursante->fechaPresentacion.mes,concursante->fechaPresentacion.anio,concursante->temaPresentacion,concursante->puntajePrimeraRonda);
    return 1;
}

void PrintOptions()
{

	printf("1-Cargar los datos de los concursantes desde un archivo de texto.\n");
	printf("2-Impimir concursantes\n");
	printf("3-Salir\n");

}

int menu()
{
    int option;
    system("cls");
    PrintOptions();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,3,3);
    return option;
}


void PrintOptionsLoad()
{

	printf("1-Cargar los datos de .\n");
	printf("1-Cargar los datos de .\n");
	printf("1-Cargar los datos de .\n");
	printf("4- Regresar .\n");

}

int menuLoad()
{
    int option;
    system("cls");
    PrintOptions();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,4,3);
    return option;
}

int controller_loadFromText(LinkedList* listaConcursantes)
{
    char* path;
    int result;
    result=0;
    path=NULL;
    FILE* pFile;
	if(listaConcursantes !=NULL)
	{
       /* FILE *pFile;
        pFile=fopen(path,"r");
        if(pFile==NULL)
        {
            printf("Error al abrir el archivo.\n");
            result=-1;
        }*/
        if(!utn_getString(path,"Ingrese nombre del archivo a cargar:\n,","Error. Archivo con ese nombre no existe.",5,20,3))
        {
            if(parser_FromText(pFile,listaConcursantes,path)==0)
            {
                printf("Archivo cargado con exito!\n");
            }
            else
            {
                printf("Error al cargar el archivo.\n");
            }
        }

        }
    //ll_pop(listaConcursantes,0);
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;

}

int controller_listElements(LinkedList* listaConcursantes)
{
    int i;
    int size;
    eConcursante* concursanteAux;
    size=ll_len(listaConcursantes);
    if(size>0)
    {
        for(i=0;i<size;i++)
        {
            concursanteAux= ll_get(listaConcursantes,i);
            ListElement(concursanteAux);
        }
    }

    return 0;
}

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));

   if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
int ret=-1;

    if(this!=NULL)
    {
    	ret=this->size;
    }

return ret;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)

{

Node* pNode=NULL;
int i;
int size=ll_len(this);

        if(this!=NULL && nodeIndex >=0 && nodeIndex <size)
	    {
		  pNode=this->pFirstNode;

		for(i=0;i<nodeIndex;i++)
		{
		    if(pNode!=NULL)
           {
		      pNode=pNode->pNextNode;
		   }
	    }
       }

 return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
 int ret=-1;
 Node* pNode=(Node*)malloc(sizeof(Node));
 Node* pAuxNode;
 int size=ll_len(this);

    if(this != NULL)
    {
    	if(pNode !=NULL && nodeIndex >=0 && nodeIndex <=size)
    	{
    	  if(nodeIndex ==0)
    	  {
               pNode->pNextNode=this->pFirstNode;
               this->pFirstNode=pNode;
               pNode->pElement=pElement;
               this->size++;
               ret=0;
    	  }
    	  else
    	  {
    	      pAuxNode=getNode(this,nodeIndex-1);
    	      pNode->pNextNode=pAuxNode->pNextNode;
    	      pAuxNode->pNextNode=pNode;
    	      pNode->pElement=pElement;
    	      this->size++;
    	      ret=0;
    	  }

        }
    }

 return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
 int ret=-1;
 int size=ll_len(this);

      if(this !=NULL)
    {
      if(!addNode(this,size,pElement))
      {
       ret=0;
      }
    }

return ret;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
void* ret=NULL;
int size=ll_len(this);
Node* pNode;

    if(this !=NULL && index >=0 && index <=size)
    {
    	 pNode=getNode(this,index);
          if(pNode !=NULL)
         {
    	   ret=pNode->pElement;
         }
    }

return ret;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
 int ret=-1;
 int size=ll_len(this);
 Node* pNode;

    if(this !=NULL)
    {
       if(index >=0 && index <=size)
       {
         pNode=getNode(this,index);
         if(pNode !=NULL)
         {
    	 pNode->pElement=pElement;
    	 ret=0;
         }
       }
    }

return ret;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	 int ret=-1;
	 Node* pNode=(Node*)malloc(sizeof(Node));
	 Node* pAuxNode;
	 int size=ll_len(this);

	    if(this != NULL)
	    {
	    	if(pNode !=NULL && index >=0 && index <size)
	    	{
	    	  if(index ==0)
	    	  {
	    	       this->pFirstNode=pNode->pNextNode;
	               free(pNode);
	               this->size--;
	    	  }
	    	  else
	    	  {
	    		  pNode=getNode(this,index);
	    		  pAuxNode=getNode(this,index-1);
	    		  pAuxNode->pNextNode=pNode->pNextNode;
	    		  free(pNode);
	    	      this->size--;
	    	  }
	    	  ret=0;
	        }
	    }

return ret;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
 int ret=-1;
 int i;
 int size=ll_len(this);
 Node* pNode;

    if(this!=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    	  pNode=ll_get(this,i);
    	  ll_remove(this,i);
    	  free(pNode);
    	}
    	ret=0;
    }

return ret;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
int ret=-1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	ret=0;
    }

return ret;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
 int ret=-1;
 int size=ll_len(this);
 Node* pNode;
 int i;

    if(this !=NULL)
    {
    	for(i=0;i<size;i++)
    	{
    	   pNode=getNode(this,i);
	     if(pNode->pElement==pElement)
	     {
	       ret=i;
	       break;
	     }
    	}
    }
return ret;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
 int ret=-1;
 int size=ll_len(this);

    if(this !=NULL)
    {
    	if(size>0)
    	{
    	  ret=0;
    	}
    	else
    	{
          ret=1;
    	}
    }

return ret;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	 int ret=-1;
	 int size=ll_len(this);

	    if(this!=NULL)
	    {
	      if(index >=0 && index <=size)
	      {

	      if(!addNode(this,size,pElement))
	      {
	       ret=0;
	      }
	      }
	    }

return ret;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
void* ret=NULL;
int size=ll_len(this);

         if(this!=NULL)
        {
         if(index >=0 && index <size)
         {
          	  ret=ll_get(this,index);
          	  ll_remove(this,index);
         }
        }

return ret;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
int ret=-1;
int i;
int size=ll_len(this);
Node* pNode=NULL;

     if(this!=NULL)
     {
       for(i=0;i<=size;i++)
       {
    	 pNode=getNode(this,i);
        if(pNode !=NULL && pElement == pNode->pElement)
        {
          ret=1;
          break;
        }
        else
        {
          ret=0;
        }
       }
     }

return ret;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
int ret=-1;
int i;
int returnAux;
Node* pNode=NULL;
int size=ll_len(this2);


     if(this!=NULL && this2!=NULL)
     {
    	 for(i=0;i<size;i++)
    	 {
    		 pNode=getNode(this2,i);
    		 if(pNode !=NULL)
    	    {
    			 returnAux=ll_contains(this,pNode->pElement);
    	    }
         }

    	 if(returnAux == 1)
    	 {
    		 ret=1;
    	 }
    	 else
    	 {
    		 ret=0;
    	 }
     }

return ret;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
LinkedList* cloneArray=NULL;
int i;
void* pElement=NULL;
int size=ll_len(this);

       if(this !=NULL)
       {
    	  if((from >=0 && from <=size) && (to >=from && to <=size))
    	  {
    	   cloneArray=ll_newLinkedList();
    	   for(i=from;i<to;i++)
    	   {
    		 pElement=ll_get(this,i);
    		 if(pElement !=NULL)
    		 {
    		  ll_add(cloneArray,pElement);
    	     }
    	   }
          }
       }

return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
LinkedList* cloneArray = NULL;
int size=ll_len(this);

         if(this !=NULL)
         {
        	 cloneArray=ll_subList(this,0,size);
         }

return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
*/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int ret =-1;
    int i;
	int j;
	int size=ll_len(this);
    void* pElement1=NULL;
    void* pElement2=NULL;
    void* pAux=NULL;
    int   returnAux;

       if(this!=NULL && pFunc!=NULL &&(order==0 || order==1))
       {
           for(i=0; i<size-1; i++)
           {
               pElement1=ll_get(this,i);
               for(j=i+1; j<size; j++)
               {
                   pElement2=ll_get(this,j);
                   if(pElement1 !=NULL && pElement2 !=NULL)
                   {
                	returnAux=pFunc(pElement1,pElement2);
                   if(order==1 && returnAux ==1)
                   {
                           pAux=pElement1;
                           pElement1=pElement2;
                           pElement2=pAux;
                   }
                   else if(order==0 && returnAux ==-1)
                   {
                           pAux=pElement2;
                           pElement2=pElement1;
                           pElement1=pAux;
                   }
                   ll_set(this,j,pElement2);
                   ll_set(this,i,pElement1);
                  }
              }
          }
           ret=0;
       }

return ret;
}

int parser_FromText(FILE* pFile, LinkedList* listaConcursantes,char* path)
{
    int result;
	char buffer[5][50];

	//int flag;
	eConcursante* auxConcursante;
    result =-1;

    pFile=fopen(path,"r");
	if(pFile !=NULL && listaConcursantes !=NULL && path!=NULL)
    {
        do
        {
        fscanf(pFile,"%[^,],%[^,],%[^,],,%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
       // auxConcursante= concursantes_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
            if(auxConcursante !=NULL)
            {
               /* if(flag==0)
                {
                    flag++;
                    continue;
                }*/
                ll_add(listaConcursantes,auxConcursante);
            }
        }while(!feof(pFile));
        result=0;
    }
    fclose(pFile);
    return result;

}

eConcursante* concursante_new()
{
    eConcursante* concursante=(eConcursante*)malloc(sizeof(eConcursante));

    return concursante;
}
eConcursante* concursante_newParametros(char* char1,char* char2,char* char3,char* char4,char* char5,char* char6)
{
    eConcursante* concursante= concursante_new();
	int numeroConcursante;
    int anioDeNacimiento;

    char dni[8];
    char fechaPresentacion[10];
    char temaPresentacion[30];
    int puntajePrimeraRonda;

	if(concursante != NULL && char1!=NULL && char2!=NULL && char3!=NULL && char4!=NULL && char5!=NULL && char6!=NULL)
	{
        numeroConcursante=atoi(char1);
        anioDeNacimiento=atoi(char2);



        employee_setId(empl,id);
        employee_setNombre(empl,nombreStr);
        employee_setHorasTrabajadas(empl,horasTrabajadas);
        employee_setSueldo(empl,sueldo);
	}
    return empl;
}
