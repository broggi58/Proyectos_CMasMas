#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Concursantes.h"
int parser_FromText(FILE* pFile, LinkedList* listaConcursantes,char* path)
{
    int result;
	char buffer[7][50];

	int flag;
	eConcursante* auxConcursante;
    result =-1;
    flag=0;

    pFile=fopen(path,"r");
	if(pFile !=NULL && listaConcursantes !=NULL && path!=NULL)
    {
        do
        {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
        auxConcursante= concursante_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
            if(auxConcursante !=NULL)
            {
                if(flag==0)
                {
                    flag++;
                    continue;
                }
                ll_add(listaConcursantes,auxConcursante);
            }
        }while(!feof(pFile));
        result=0;
    }
    fclose(pFile);
    return result;

}
