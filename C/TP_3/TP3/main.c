#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Employee.h"
#include "string.h"





/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* employeeList;
    employeeList= ll_newLinkedList();
    int salir;
    int flagArchivo;
    int flagDato;
    int confirmarSalir;
    flagDato=0;
    flagArchivo=0;
    do{

    	switch(menu())
    		{
    		case 1:
                if(flagArchivo==0)
                {
                    controller_loadFromText("data.csv",employeeList);
                    flagDato=1;
                    flagArchivo=1;
                }
                else{
                    printf("Ya se cargaron los datos del archivo previamente.\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }
    			break;
    		case 2:
                if(flagArchivo==0)
                {
                    controller_loadFromBinary("data.bin",employeeList);
                    flagDato=1;
                    flagArchivo=1;
                }
                else{
                    printf("Ya se cargaron los datos del archivo previamente.\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }


    			break;
    		case 3:

    		    controller_addEmployee(employeeList);
    		    flagDato++;
    		    break;
    		case 4:
                if(flagDato!=0)
                {
                    controller_editEmployee(employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }

    		    break;
    		case 5:
                    if(flagDato!=0)
                {
                    controller_removeEmployee(employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }

    			break;
    		case 6:
                if(flagDato!=0)
                {
                            controller_ListEmployee(employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }

    			break;
    		case 7:
                if(flagDato!=0)
                {
                           controller_sortEmployee(employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }


    			break;
    		case 8:
                    if(flagDato!=0)
                {
                            controller_saveAsText("data.csv",employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }


    			break;
    		case 9:
                    if(flagDato!=0)
                {
                           controller_saveAsBinary("data.bin",employeeList);
                }
                else
                {
                    printf("Error. No se encuentran empleados cargados...\n");
                    printf("Pulse intro para continuar...\n");
                    fflush(stdin);
                    getchar();
                }


    		     break;
            case 10:

                    utn_getInt(&confirmarSalir,"Confirmar salida? Introducir 1 para confirmar o 2 para continuar.\n","Error. Opcion invalida.\n",1,2,22);
                    if(confirmarSalir==1)
                    {
                        salir=1;
                    }

                    break;
    		}
    	}while(salir!=1);



    return 0;
}
