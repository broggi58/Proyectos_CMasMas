#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Concursantes.h"
#include "parser.h"
#include "utn.h"
#define FINALISTAS 3

int controller_loadFromText(LinkedList* listaConcursantes, int* flagParticipantes,char* path)
{
   // char path[20];
    int result;
    int flag;
    result=0;
    FILE* pFile;
	if(listaConcursantes !=NULL && flagParticipantes!= NULL && path!=NULL)
	{
       /* FILE *pFile;
        pFile=fopen(path,"r");
        if(pFile==NULL)
        {
            printf("Error al abrir el archivo.\n");
            result=-1;
        }*/
        flag=utn_getString(path,"Ingrese nombre del archivo a cargar con su extension:\n","Error al introducir nombre del archivo.\n",1,100,3);
        if(!flag)
        {
            if(parser_FromText(pFile,listaConcursantes,path)==0)
            {
                printf("Archivo cargado con exito!\n");
                result=1;
            }
            else
            {
                printf("Error al cargar el archivo. Puede que no exista archivo con ese nombre.\n");
            }
        }

        }
    *flagParticipantes=result;
    //ll_pop(listaConcursantes,0);
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;

}

void PrintOptions()
{

	printf("1-Cargar los datos de los concursantes desde un archivo de texto.\n");
	printf("2-Impimir concursantes\n");
	printf("3-Evaluar segunda fase\n");
	printf("4-Mostrar cuantos participantes superan los 70 puntos en la primera ronda\n");
	printf("5-Guardar participantes con mas de 70 puntos en la primera ronda\n");
	printf("6-Elegir Finalistas\n");
	printf("7-Evaluar tercera etapa\n");
	printf("8-Salir\n");
}

int menu()
{
    int option;
    system("cls");
    PrintOptions();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,10,3);
    return option;
}

int controller_listElements(LinkedList* listaConcursantes,int* flagParticipantes)
{
    int i;
    int size;
    eConcursante* concursanteAux;
    size=ll_len(listaConcursantes);
    if(size>0 && flagParticipantes)
    {
         printf("Numero de concursante   anio de nacimiento   D.N.I.   Fecha de presentacion   Tema de presentacion   Puntaje primera ronda\n");
        for(i=0;i<size;i++)
        {
            concursanteAux= ll_get(listaConcursantes,i);
            ListElement(concursanteAux);
        }
    }
    else
    {
        printf("Error. No se pueden listar los concursantes porque no estan cargados.\n");

    }
    printf("Ingrese intro para continuar...\n");
                        fflush(stdin);
                        getchar();
    return 0;
}

int controller_evaluarParticipantesSegundaFase(LinkedList* listaConcursantes,int *flagHayConcursantes,char* path,int* flagSegundaFase)
{
    if(listaConcursantes!=NULL && path!=NULL && flagHayConcursantes!=NULL)
    {
        if(*flagHayConcursantes==0)
        {
            printf("Error. No se han cargado datos de ningun archivo previamente.\n");
        }
        else
        {
            if(ll_map(listaConcursantes,calificarSegundaEtapa))
               {
                    guardarResultados(path,listaConcursantes);
                    *flagSegundaFase=1;
                    printf("Resultados calculados con exito!\n");
               }
        }

    }
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 0;
}

int controller_informar(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase)
{
    int cont;
    if(listaConcursantes!=NULL && flagHayConcursantes!=NULL && flagSegundaFase!=NULL)
    {
        if(*flagHayConcursantes==0 || *flagSegundaFase==0)
        {
            printf("Error. No se han cargado los datos del archivo o no se calcularon los valores de la segunda fase.\n");
        }
        else
        {
           cont= ll_count(listaConcursantes,checkearConcursante);
           printf("Hay %d participantes que superaron los 70 puntos en la primera fase.\n",cont);
        }


    }
    else
    {
        printf("Error.\n");
    }
    printf("Ingrese intro para contiunar...\n");
    fflush(stdin);
    getchar();
    return 0;
}

int controller_guardarDatos(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase)
{
    eConcursante* auxConcursante;

    int i;
    int size;
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

    if(listaConcursantes!=NULL && flagHayConcursantes!=NULL && flagSegundaFase!=NULL)
    {
        if(*flagHayConcursantes==0 || *flagSegundaFase==0)
        {
            printf("Error. No se cargaron los datos del archivo o no se evaluo la segunda fase.\n");
        }
        else
        {
            size=ll_len(listaConcursantes);
            for(i=0;i<size;i++)
            {
                auxConcursante=ll_get(listaConcursantes,i);
                if(auxConcursante!=NULL)
                {
                    if(checkearConcursante(auxConcursante))
                    {
                        eConcursante_getdni(auxConcursante,nombreArchivo);
                        strcat(nombreArchivo,extension);
                        myFile=fopen(nombreArchivo,"w");
                        if(myFile!=NULL)
                        {
                            eConcursante_getnumeroConcursante(auxConcursante,&numerodeConcursante);
                            eConcursante_getAnioDeNacimiento(auxConcursante,&anioDeNacimiento);
                            eConcursante_getnombre(auxConcursante,nombre);
                            eConcursante_getdni(auxConcursante,dni);
                            eConcursante_getfecha(auxConcursante,&fechaDePresentacion);
                            eConcursante_gettemaDePresentacion(auxConcursante,temaDePresentacion);
                            eConcursante_getpuntajePrimeraRonda(auxConcursante,&puntajePrimeraRonda);
                            eConcursante_getpuntajeSegundaRonda(auxConcursante,&puntajeSegundaRonda);
                            eConcursante_getpuntajePromedio(auxConcursante,&puntajePromedio);
                            ListElement(auxConcursante);
                            //fwrite(auxConcursante,1,sizeof(eConcursante),myFile);
                            //fprintf(myFile,"%d, %d, %s, %s,%d/%d/%d, %s, %d,%d, %f \n   ",auxConcursante->numerodeConcursante,auxConcursante->anioDeNacimiento,auxConcursante->nombre,auxConcursante->dni,auxConcursante->fechaDePresentacion.mes,auxConcursante->fechaDePresentacion.dia,auxConcursante->fechaDePresentacion.anio,auxConcursante->temaDePresentacion,auxConcursante->puntajePrimeraRonda,auxConcursante->puntajeSegundaRonda,auxConcursante->puntajePromedio);
                            fprintf(myFile,"%d, %d, %s, %s,%d/%d/%d, %s, %d,%d, %f \n   ",numerodeConcursante,anioDeNacimiento,auxConcursante->nombre,dni,fechaDePresentacion.mes,fechaDePresentacion.dia,fechaDePresentacion.anio,temaDePresentacion,puntajePrimeraRonda,puntajeSegundaRonda,puntajePromedio);
                        }
                        fclose(myFile);
                    }
                }
            }
            printf("Archivos guardados con exito!.\n");
        }
    }
    else
    {
        printf("Error.\n");
    }
    printf("Ingrese intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 0;
}

int controller_elegirFinalistas(LinkedList* listaConcursantes,int* flagHayConcursantes,int* flagSegundaFase)
{
    LinkedList* listaFinalistas;
    eConcursante* auxConcursante;
    int* notaReferencia;
    FILE* myFile;
    int size;
    int i;
    //int cantidadDeFinalistas;
    char* extension=".csv";
    char nombreArchivo[100]="\0";
    int sizeFinalistas;
    int numerodeConcursante;
    int anioDeNacimiento;
    char nombre[50]="\0";
    char dni[8];
    eFecha fechaDePresentacion;
   // char fechaDePresentacion[10];
    char temaDePresentacion[30];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float puntajePromedio;
    if(listaConcursantes!=NULL && flagHayConcursantes!=NULL && flagSegundaFase!=NULL)
    {
        if(*flagHayConcursantes==0 || *flagSegundaFase==0)
        {
            printf("Error. No se han cargado los datos del archivo o no se calcularon los valores de la segunda fase.\n");
        }
        else
        {
            size=ll_len(listaConcursantes);
            notaReferencia= ObtenerNotaDeReferencia(listaConcursantes,size);
            //ObtenerNotasMasAltas(listaConcursantes,notasMaximas);

           listaFinalistas=ll_filterV2(listaConcursantes,FiltrarConcursantes,notaReferencia);


        }

        sizeFinalistas=ll_len(listaFinalistas);
        ll_sort(listaFinalistas,eConcursante_CompareByNotaPrimeraEtapa,0);

        for(i=0;i<sizeFinalistas;i++)
        {
            auxConcursante=ll_get(listaFinalistas,i);
            if(auxConcursante!=NULL)
            {
                eConcursante_getdni(auxConcursante,nombreArchivo);
                        strcat(nombreArchivo,extension);
                        myFile=fopen(nombreArchivo,"w");

                        if(myFile!=NULL)
                        {

                            eConcursante_getnumeroConcursante(auxConcursante,&numerodeConcursante);
                            eConcursante_getAnioDeNacimiento(auxConcursante,&anioDeNacimiento);
                            eConcursante_getnombre(auxConcursante,nombre);
                            eConcursante_getdni(auxConcursante,dni);
                            eConcursante_getfecha(auxConcursante,&fechaDePresentacion);
                            eConcursante_gettemaDePresentacion(auxConcursante,temaDePresentacion);
                            eConcursante_getpuntajePrimeraRonda(auxConcursante,&puntajePrimeraRonda);
                            eConcursante_getpuntajeSegundaRonda(auxConcursante,&puntajeSegundaRonda);
                            eConcursante_getpuntajePromedio(auxConcursante,&puntajePromedio);
                            ListElement(auxConcursante);
                            //fwrite(auxConcursante,1,sizeof(eConcursante),myFile);
                            //fprintf(myFile,"%d, %d, %s, %s,%d/%d/%d, %s, %d,%d, %f \n   ",auxConcursante->numerodeConcursante,auxConcursante->anioDeNacimiento,auxConcursante->nombre,auxConcursante->dni,auxConcursante->fechaDePresentacion.mes,auxConcursante->fechaDePresentacion.dia,auxConcursante->fechaDePresentacion.anio,auxConcursante->temaDePresentacion,auxConcursante->puntajePrimeraRonda,auxConcursante->puntajeSegundaRonda,auxConcursante->puntajePromedio);
                            fprintf(myFile,"%d, %d, %s, %s,%d/%d/%d, %s, %d,%d, %f \n   ",numerodeConcursante,anioDeNacimiento,auxConcursante->nombre,dni,fechaDePresentacion.mes,fechaDePresentacion.dia,fechaDePresentacion.anio,temaDePresentacion,puntajePrimeraRonda,puntajeSegundaRonda,puntajePromedio);
                        }
                        fclose(myFile);
            }
        }
        printf("Archivos guardados con exito!.\n");



    }
    else
    {
        printf("Error.\n");
    }
    printf("Ingrese intro para contiunar...\n");
    fflush(stdin);
    getchar();
    return 0;
}

int controller_controller_evaluarParticipantesEtapaTres(LinkedList* listaConcursantes,int* flagHayConcursantes,char path,int* flagSegundaFase)
{

     LinkedList* listaFinalistas2;
     //int notasMaximas[3];
     eConcursante* aux;
     int notaReferencia;
     int i;
     int size;
     int sizeFinalistas;
     if(listaConcursantes!=NULL && path!=NULL && flagHayConcursantes!=NULL)
    {
        if(*flagHayConcursantes==0)
        {
            printf("Error. No se han cargado datos de ningun archivo previamente.\n");
        }
        else
        {
            if(ll_map(listaConcursantes,calificarTerceraEtapa))
               {
                   size=ll_len(listaConcursantes);
                   notaReferencia=ObtenerNotaDeReferenciaEtapaTres(listaConcursantes,size);
                    //guardarResultados(path,listaConcursantes);
                   // *flagSegundaFase=1;
                   // ObtenerNotasMasAltasEtapaTres(listaConcursantes,notasMaximas);

                    listaFinalistas2=ll_filterV2(listaConcursantes,FiltrarConcursanteTerceraRonda,notaReferencia);

                   // printf("Resultados calculados con exito!\n");
               }
                sizeFinalistas=ll_len(listaFinalistas2);

                if(sizeFinalistas>FINALISTAS)
                {
                    //Desempatar(listaFinalistas2,&sizeFinalistas,FINALISTAS);
                    ll_sort(listaFinalistas2,eConcursante_CompareByNotaTerceraEtapa,1);
                    while(sizeFinalistas>FINALISTAS)
                    {
                        ll_remove(listaFinalistas2,0);
                        sizeFinalistas--;
                    }
                }
               // ll_sort(listaFinalistas2,eConcursante_CompareByNotaTerceraEtapa,1);
               for(i=0;i<sizeFinalistas;i++)
               {
                   aux=ll_get(listaFinalistas2,i);
                   if(aux!=NULL)
                   {
                       ListElement(aux);
                   }

               }
        }

    }
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 0;
}
