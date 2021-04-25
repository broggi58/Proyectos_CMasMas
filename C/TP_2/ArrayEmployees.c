#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len)
{
    int retorno;
    int i;
    retorno=-1;
    if(list!=NULL || len!=1000)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=1;
        }
        retorno=0;
    }
 return retorno;
}

int SearchFree(Employee list[],int len)
{
    int index;
    int i;
    index=-1;
    if(list !=NULL || len!=1000)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int CreateNewEmployee(Employee list[],int len,int id)
{
    int retorno;
    int flagName;
    int flagLastName;
    int flagSalary;
    int flagSector;
    retorno=-1;
    flagName=-1;
    flagLastName=-1;
    flagSalary=-1;
    flagSector=-1;
    Employee empl;
    empl.id=id;
    flagName=utn_getString(empl.name,"Ingrese nombre:\n","Error. Nombre fuera de rango\n",2,50,5);
    if(!flagName)
    {
        flagLastName=utn_getString(empl.lastName,"Ingrese apellido: \n","Error. Apellido fuera de rango\n",2,50,3);
    }
    if(!flagLastName)
    {
        flagSalary=utn_getFloat(&empl.salary,"Ingrese salario: \n","Error. No se puede tener salario negativo.",0,FLT_MAX,3);
    }
    if(!flagSalary)
    {
        flagSector=utn_getInt(&empl.sector,"Ingrese sector entre 1 y 9.\n","Error. Sector ingresado no existe\n",1,9,3);
    }
    if(!flagSector)
    {
        retorno= addEmployee(list,len,id,empl.name,empl.lastName,empl.salary,empl.sector);
    }

    return retorno;
}

int addEmployee(Employee list[], int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int retorno;
    int index;
    retorno=-1;
    index= SearchFree(list,len);
    if(index>=0)
    {
        list[index].id=id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName,lastName);
        list[index].salary=salary;
        list[index].sector=sector;
        list[index].isEmpty=0;
        retorno=0;
    }

  return retorno;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int retorno;
    int i;
    retorno=-1;
    if(list !=NULL && len ==1000)
    {
        for(i=0;i<len;i++)
      {
        if(list[i].id==id)
        {
            retorno=i;
            break;
        }
      }
    }


 return retorno;

}

int removeEmployee(Employee list[], int len, int id)
{
    int retorno;
    int index;
    retorno=-1;
    if(list!=NULL|| len!=1000)
    {
        index= findEmployeeById(list,len,id);
    }
    if(index>=0)
    {
        list[index].isEmpty=1;
        retorno=0;
    }
 return retorno;
}

int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    int retorno;
    Employee buffer;
    retorno=0;
    if(order==1 && list!=NULL && len==1000)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i;j<len;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)==1)
                {
                    buffer=list[i];
                    list[i]=list[j];
                    list[j]=buffer;
                }
            }
        for(i=0;i<len-1;i++)
        {
            for(j=i;j<len;j++)
            {
                if(!strcmp(list[i].lastName,list[j].lastName))
                {
                    if(list[i].sector>list[j].sector)
                    {
                        buffer=list[i];
                        list[i]=list[j];
                        list[j]=buffer;
                    }
                }
            }
        }
        }
        retorno=1;
    }
    if(order==2 && list!=NULL && len==1000)
    {
        for(i=0;i<len-1;i++)
        {
            for(j=i;j<len;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName)==-1)
                {
                    buffer=list[i];
                    list[i]=list[j];
                    list[j]=buffer;
                }
            }
        }
        for(i=0;i<len-1;i++)
        {
            for(j=i;j<len;j++)
            {
                if(!strcmp(list[i].lastName,list[j].lastName))
                {
                    if(list[i].sector<list[j].sector)
                    {
                        buffer=list[i];
                        list[i]=list[j];
                        list[j]=buffer;
                    }
                }
            }
        }
        retorno=1;
    }

 return retorno;
}

int printEmployee(Employee empl)
{
    printf("%d  %10s      %10s          %1d            $ %06.2f\n",empl.id,empl.lastName,empl.name,empl.sector,empl.salary);
    return 0;
}

int printEmployees(Employee list[], int length)
{
    int i;
    if (list!=NULL)
    {
        for(i=0;i<length;i++)
        {
            if(list[i].isEmpty==0)
            {
                printEmployee(list[i]);
            }
        }
    }

 return 0;
}

void PrintOptions()
{
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

}
int menu()
{
    int option;
    system("cls");
    PrintOptions();

    utn_getInt(&option,"Introduzca una opcion\n","Error. Introduzca una opcion valida\n",1,5,99);
    return option;
}

void PrintModifyOptions()
{
    printf("1- Modificar nombre\n");
    printf("2- Modificar apellido\n");
    printf("3- Modificar salario\n");
    printf("4- Modificar sector\n");
    printf("5- Regresar\n");

}
int ModifyMenu()
{
    int option;
    system("cls");
    PrintModifyOptions();
    utn_getInt(&option,"Ingresar atributo a modificar\n","Error. ese atributo no existe\n",1,5,14);
    return option;

}
void ModifyEmployee(Employee list[],int len,int id)
{
    int index;
    if(list!=NULL || len!=1000)
    {
        index= findEmployeeById(list,len,id);
    }
    if(index>=0)
    {
        switch(ModifyMenu())
    {
        case 1 :
                 utn_getString(list[index].name,"Ingrese nuevo nombre:\n","Error. Nombre fuera de rango\n",2,50,8);
                 printf("Nombre modificado con exito!\n");
                 break;
        case 2 :
                utn_getString(list[index].lastName,"Ingrese nuevo apellido:\n","Error. Apellido fuera de rango\n",2,50,8);
                printf("Apellido modificado con exito!\n");
                break;
        case 3:
                utn_getFloat(&list[index].salary,"Ingrese nuevo salario:\n","Error. No se puede tener un salario negativo\n",0,FLT_MAX,45);
                printf("Salario modificado con exito!\n");
        case 4:
                utn_getInt(&list[index].sector,"Ingrese nuevo sector entre 1 y 9 : \n","Error. Ese sector no existe.\n",1,9,58);
                printf("Sector modificado con exito!\n");
                break;
        case 5:
                break;

    }
    }
    else
    {
        printf("Error. No se encontro empleado con ese id.\n");
        fflush(stdin);
        printf("Pulse intro para continuar...\n");
        getchar();
    }

}
float SumSalaries (Employee list[],int len)
{
    int total;
    int i;
    total=0;
    if(list== NULL || len != 1000)
    {
        total=-1;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                total+=list[i].salary;
            }
        }
    }

    return total;
}
float getAverageSalary (Employee list[],int len,float total)
{
    int count;
    int i;
    float average;
    count=0;
    if(list == NULL || len !=1000 || total <0)
    {
        count=-1;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                count++;
            }
        }
        average = total/count;
    }
    return average;
}
int CountHighSalaries(Employee list[],int len,float average)
{
    int count;
    int i;
    count =0;
    if(list== NULL || len!=1000 || average<0)
    {
        count =-1;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].salary>average)
            {
                count++;
            }
        }
    }
    return count;
}
