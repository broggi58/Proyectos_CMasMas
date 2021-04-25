#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* empl=(Employee*)malloc(sizeof(Employee));

    return empl;
}

void employee_delete(Employee* this)
{
    free(this);
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* empl= employee_new();
	int id;
	int horasTrabajadas;
	int sueldo;
	if(empl != NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
        id=atoi(idStr);
        horasTrabajadas=atoi(horasTrabajadasStr);
        sueldo=atoi(sueldoStr);
        employee_setId(empl,id);
        employee_setNombre(empl,nombreStr);
        employee_setHorasTrabajadas(empl,horasTrabajadas);
        employee_setSueldo(empl,sueldo);
	}
    return empl;
}

int employee_setId(Employee* this,int id)
{
    int result;
    result=-1;
	if(this != NULL && id > 0 )
	{
        this->id=id;
        result=0;
	}
return result;
}

int employee_getId(Employee* this,int* id)
{
    int result;
    result = -1;
	if(this != NULL && id > 0 )
	{
        *id=this->id;
        result=0;
	}
    return result;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int result;
    result =-1;
    if(this != NULL && nombre > 0 )
        {
            strcpy(this->nombre,nombre);
		    result=0;
        }
    return result;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int result;
    result=-1;
	if(this != NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        result=0;
    }
    return result;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int result;
    result=-1;
    if(this != NULL && horasTrabajadas > 0 )
    {
        this->horasTrabajadas=horasTrabajadas;
        result=0;
    }
return result;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int result;
    result=-1;
	if(this != NULL && horasTrabajadas > 0 )
	{
        *horasTrabajadas=this->horasTrabajadas;
        result=0;
	}
    return result;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int result;
	result=-1;
	if(this != NULL && sueldo > 0 )
	{
        this->sueldo=sueldo;
        result=0;
	}
    return result;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int result;
	result=-1;
	if(this != NULL && sueldo > 0 )
	{
        *sueldo=this->sueldo;
        result=0;
	}
    return result;
}

int employee_CompareByName(Employee* e1, Employee* e2)
{

    return strcmp(e1->nombre,e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{

    int result;
    result=0;
    if(e1->id>e2->id)
    {
        result=1;
    }
    else if(e1->id<e2->id)
    {
        result=-1;
    }

    return result;
}
int employee_createEmployee(Employee* aux)
{

    int result;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
	result=-1;
      if(aux!=NULL)
	  {
        if(!utn_getInt(&auxId,"Ingrese el ID del empleado:\n ","Error. ID invalido\n",1,99999,3))
        {
            employee_setId(aux,auxId);
            if(!utn_getStringName(auxNombre,"Ingrese  nombre del empleado:\n ","Error. Nombre invalido\n",1,128,3))
            {
                employee_setNombre(aux,auxNombre);
                if(!utn_getInt(&auxHorasTrabajadas,"Ingrese las horas trabajadas del empleado:\n ","Error. Cantidad de horas invalida.\n",1,999,3))
                {
                    employee_setHorasTrabajadas(aux,auxHorasTrabajadas);
                    if(!utn_getInt(&auxSueldo,"Ingrese el sueldo del empleado: ","Error. Salario invalido.\n",1,9999999,3))
                    {
                        employee_setSueldo(aux,auxSueldo);


                        result=0;
                    }
                }
            }
        }

	   }
    return result;
}

int employee_editEmployee(LinkedList* pArrayList)
{
    int result;
    int index;
    char auxNombre[128];
    int  auxHorasTrabajadas;
    int  auxSueldo;
    int size;
    Employee* aux;
    result=-1;

    size=ll_len(pArrayList);

      if(pArrayList!=NULL && size>0 )
      {
	     if(!utn_getInt(&index,"Ingresar el incide del empleado a editar:\n ","Error. Indice invalido.\n",1,size,3))
         {
             aux =(Employee*) ll_get(pArrayList,(index-1));
              if(aux!=NULL)
    	 {
    	      result=0;
        	   switch(ModifyMenu())
        	  {
                case 1:

        	   if(!utn_getStringName(auxNombre,"Ingrese el nuevo nombre del empleado:\n ","Error. Nombre invalido\n",2,128,3))
               {
                   employee_setNombre(aux,auxNombre);
                   printf("Nombre cambiado con exito!\n");
               }

        	   break;
        	  case 2:

        	   if(!utn_getInt(&auxHorasTrabajadas,"Ingrese las horas Trabajadas del empleado:\n ","Error. Horas ingresadas invalidas.\n",1,40,2))
               {
                   employee_setHorasTrabajadas(aux,auxHorasTrabajadas);
                   printf("Horas trabajadas modificadas con exito!\n");
               }

	           break;
	          case 3:

        	   if(!utn_getInt(&auxSueldo,"Ingrese el sueldo del empleado: \n","Error. Salario invalido.\n",1,99999999,2))
               {
                   employee_setSueldo(aux,auxSueldo);
                   printf("Sueldo modificado con exito!\n");
               }

        	   break;
              case 4:
                break;
        	  }



            }
    	    else
            {
        	printf("Error. Indice invalido.\n");
            }
         }

       }
       else
       {
           printf("Error. Puntero a NULL o lista vacia.\n");
       }
    return result;
}

int employee_removeEmployee(LinkedList* pArrayList)
{
    int result;
    int index;
    int size;
    Employee* pEmployee;
    result=-1;
    size=ll_len(pArrayList);
    if(pArrayList!=NULL && size>0)
    {
        if(!utn_getInt(&index,"Ingrese el indice del empleado a eliminar en la lista:\n","Error. Indice invalido.\n",0,size,3))
        {
            pEmployee=ll_get(pArrayList,(index-1));
            if(pEmployee!=NULL)
            {
                if(!ll_remove(pArrayList,(index-1)))
                {
                    printf("Empleado removido con exito!\n");
                    result=0;
                }
                else
                {
                    printf("Error al eliminar al empleado.\n");
                }
            }
        }
    }
    return result;
}
int employee_ListEmployee(Employee* pAux,int index)
{
    printf("  %2d       %2d %10s          %2d   \n",index+1,pAux->id,pAux->nombre,pAux->horasTrabajadas);
    return 1;
}
int employee_ListEmployees(LinkedList* pArrayList)
{
    int result;
    int i;
    int size;
    int flag;
    Employee* pAux;
    size=ll_len(pArrayList);
    result=-1;
    flag=0;
    if(pArrayList!=NULL && size>0)
    {
        printf("Indice    ID       Nombre     Horas Trabajadas\n");
        for(i=0;i<=size;i++)
        {
            pAux=ll_get(pArrayList,i);
            if(pAux!=NULL)
            {
                flag++;
                employee_ListEmployee(pAux,i);
                if(flag%50==0)
                {
                    printf("Ingrese enter para continuar...\n");
                    fflush(stdin);
                    getchar();
                }
            }
        }
        result=0;
    }
    return result;
}
