#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
	char buffer[4][128];
	//int flag;
	Employee* auxEmp;
    result =-1;
    //flag=0;
    pFile=fopen("data.csv","r");
	if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        do
        {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        auxEmp= employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(auxEmp !=NULL)
            {
               /* if(flag==0)
                {
                    flag++;
                    continue;
                }*/
                ll_add(pArrayListEmployee,auxEmp);
            }
        }while(!feof(pFile));
        result=0;
    }
    fclose(pFile);
    return result;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int result;
	Employee* auxEmp;
    //int flag;
    result =-1;
    //flag=0;
    pFile=fopen("data.bin","rb");
	if(pFile !=NULL && pArrayListEmployee !=NULL)
    {

        do{
            auxEmp=employee_new();
            if(auxEmp !=NULL)
            {
                fread(auxEmp,sizeof(Employee),1,pFile);
               /* if(flag==0)
                {
                   flag++;
                   //continue;
                }*/
                ll_add(pArrayListEmployee,auxEmp);
            }
        }while(!feof(pFile));
        result=0;
    }
    employee_delete(auxEmp);
    fclose(pFile);

    return result;
}
