#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <float.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define SIZE 1000

int main()
{
    int Exit;
    int id;
    int idToFind;
    int order;
    int flagEmployeeExists;
    int confirmExit;
    int countHighSalary;
    float accumulatedSalary;
    float averageSalary;
    accumulatedSalary=0;
    countHighSalary=0;
    Exit=0;
    id=1000;
    flagEmployeeExists=0;
    Employee employees[SIZE];

    initEmployees(employees,SIZE);



    do{
        switch(menu())
        {
            case 1:
                if(CreateNewEmployee(employees,SIZE,id)==0)
                {
                    id++;
                    flagEmployeeExists++;
                    printf("Alta exitosa!\n");
                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();
                }
                break;
            case 2: if(flagEmployeeExists==0)
                    {
                        printf("No existe ningun empleado.\n");

                    }
                    else
                    {
                        utn_getInt(&idToFind,"Ingresar id del empleado a buscar:\n","Error. Id invalido.\n",1000,100000,15);
                        ModifyEmployee(employees,SIZE,idToFind);
                    }
                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();
                    break;
            case 3:
                    if(flagEmployeeExists==0)
                    {
                        printf("No existe ningun empleado.\n");
                    }
                    else
                    {
                       utn_getInt(&idToFind,"Ingresar id del empleado a buscar:\n","Error. Id invalido.\n",1000,100000,15);
                       if(removeEmployee(employees,SIZE,idToFind)==0)
                       {
                           printf("Empleado eliminado con exito\n");
                           flagEmployeeExists--;
                       }


                    }
                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();

                    break;
            case 4:
                    if(flagEmployeeExists==0)
                    {
                        printf("No existe ningun empleado.\n");
                    }
                    else
                    {
                        utn_getInt(&order,"Ingrese 1 para ordenar de manera ascendente y 2 para descendente.","Error. Numero fuera de rango.\n",1,2,33);
                        sortEmployees(employees,SIZE,order);
                        printf("ID       APELLIDO         NOMBRE          SECTOR         SALARIO\n");
                        printEmployees(employees,SIZE);
                        accumulatedSalary=SumSalaries(employees,SIZE);
                        averageSalary=getAverageSalary(employees,SIZE,accumulatedSalary);
                        countHighSalary=CountHighSalaries(employees,SIZE,averageSalary);
                        if(accumulatedSalary!=-1)
                        {
                            printf("\nEl salario total de los empleados es de %.2f\n",accumulatedSalary);
                        }
                        if(averageSalary!=-1)
                        {
                            printf("El salario promedio de los empleados es de  :%.2f\n",averageSalary);
                        }
                        if(countHighSalary!=-1)
                        {
                            printf("El salario promedio es superado por %d empleados\n",countHighSalary);
                        }

                    }
                    fflush(stdin);
                    printf("Pulse enter para continuar...\n");
                    getchar();
                    break;
            case 5:

                    utn_getInt(&confirmExit,"Confirmar salida? Introducir 1 para confirmar o 2 para continuar.\n","Error. Opcion invalida.\n",1,2,22);
                    if(confirmExit==1)
                    {
                        Exit=1;
                    }

                    break;

        }
    }while(Exit!=1);
    return 0;
}
