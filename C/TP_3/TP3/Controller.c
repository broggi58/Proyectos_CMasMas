#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


void PrintOptions()
{

	printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("2-Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	printf("3-Alta de empleado.\n");
	printf("4-Modificar datos de empleado.\n");
	printf("5-Baja de empleado.\n");
	printf("6-Listar empleados.\n");
	printf("7-Ordenar empleados.\n");
	printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
	printf("10-Salir\n");

}

int menu()
{
    int option;
    system("cls");
    PrintOptions();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,10,3);
    return option;
}

void PrintModifyOptions()
{
    printf("1- Modificar nombre\n");
    printf("2- Modificar horas trabajadas\n");
    printf("3- Modificar salario\n");
    printf("4- Regresar\n");

}

int ModifyMenu()
{
    int option;
    system("cls");
    PrintModifyOptions();
    utn_getInt(&option,"Ingresar atributo a modificar\n","Error. ese atributo no existe\n",1,4,3);
    return option;

}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    result=0;
	if(path !=NULL && pArrayListEmployee !=NULL)
	{
        FILE *pFile;
        pFile=fopen(path,"r");
        if(pFile==NULL)
        {
            printf("Error al abrir el archivo.\n");
            result=-1;
        }
        else if(parser_EmployeeFromText(pFile,pArrayListEmployee)==0)
        {
            printf("Archivo cargado con exito!\n");
        }
        fclose(pFile);
        }
    //ll_pop(pArrayListEmployee,0);
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;

}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    int size;
    result=0;
	if(path !=NULL && pArrayListEmployee !=NULL)
	{
        FILE *pFile;
        pFile=fopen(path,"rb");
        if(pFile==NULL)
        {
            printf("Error al abrir el archivo.\n");
            result=-1;
        }
        else if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)!=-1)
        {
            printf("Archivo abierto con exito!\n");
        }

        }
        size=ll_len(pArrayListEmployee);
    //ll_pop(pArrayListEmployee,0);
    ll_pop(pArrayListEmployee,size-1);
         printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;

}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int result;
    Employee* employee;
    employee=employee_new();
    if(employee!=NULL)
    {
        if(!employee_createEmployee(employee))
    {
        if(!ll_add(pArrayListEmployee,employee))
        {
            printf("Empleado cargado con exito!\n");
            result=0;

        }
        else
        {
            printf("Error. No se pudo dar de alta al empleado.\n");
            result=-1;
        }
    }
    }

 printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    employee_editEmployee(pArrayListEmployee);
 printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    employee_removeEmployee(pArrayListEmployee);
     printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_ListEmployees(pArrayListEmployee);
   /*  printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();*/
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order;
    switch(menuSort())
    {
    case 1: if(!utn_getInt(&order,"Ingrese 0 para ordenar de forma descendente y 1 para ordenar de forma ascendente:\n ","Error. Numero ingresado invalido.\n",0,1,3))
                {
                    ll_sort(pArrayListEmployee,employee_CompareById,order);
                    printf("Empleados ordenados por ID con exito!\n");
                }
        break;
    case 2: if(!utn_getInt(&order,"Ingrese 1 para ordenar de forma ascendente y 2 para ordenar de forma descendente:\n ","Error. Numero ingresado invalido.\n",0,1,3))
                {
                    ll_sort(pArrayListEmployee,employee_CompareByName,order);
                    printf("Empleados ordenados por Nombre con exito!\n");
                }
        break;
    case 3:
        break;
    }
     printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    int size;
    int i;
    Employee* pAux;
    FILE* fileEmployee;
    fileEmployee= fopen(path,"w");
    result=0;
    size=ll_len(pArrayListEmployee);
    if(fileEmployee==NULL)
    {
        printf("Error. No se pudo abrir el archivo.\n");
        result=-1;
    }
    else
    {
        for(i=0;i<=size;i++)
        {
            pAux=ll_get(pArrayListEmployee,i);
            if(pAux!=NULL)
            {
                fprintf(fileEmployee,"%d, %s, %d, %d \n",pAux->id,pAux->nombre,pAux->horasTrabajadas,pAux->sueldo);
            }
        }
        fclose(fileEmployee);
        printf("Archivo guardado con exito!\n");
    }
    printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int result;
    int size;
    int i;
    result=-1;
    Employee* pAux;
    FILE* fileEmployee;
    fileEmployee=fopen(path,"wb");
    size=ll_len(pArrayListEmployee);
    if(fileEmployee==NULL)
    {
        printf("Error. No se pudo abrir el archivo.\n");

    }
    else
    {
        for(i=0;i<=size;i++)
        {
            pAux=ll_get(pArrayListEmployee,i);
            if(pAux!=NULL)
            {
                fwrite(pAux,sizeof(Employee),1,fileEmployee);
            }
        }
        fclose(fileEmployee);
        result=0;
        printf("Archivo guardado con exito!\n");

    }

 printf("Pulse intro para continuar...\n");
    fflush(stdin);
    getchar();
    return result;
}

void PrintOptionsSort()
{

	printf("1-Ordenar empleados por ID.\n");
	printf("2-Ordenar empleados por nombre.\n");
	printf("3-Regresar\n");

}

int menuSort()
{
    int option;
    system("cls");
    PrintOptionsSort();

    utn_getInt(&option,"Introduzca una opcion:\n","Error. Introduzca una opcion valida.\n",1,3,3);
    return option;
}

