#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "empleados.h"

/** \brief Muestra los datos de un array del tipo Employee en un indice determinado
 *
 * \param Recibe como parametro un array de tipo Employee


 *
 */

void showEmployee(Employee x)
{
    printf(" ID Nombre Apellido Sector Salario \n");
    printf("  %d  %s  %s  %d  %f \n",
           x.id,
           x.name,
           x.lastName,
           x.sector,
           x.salary
           );
}

/** \brief Recorre el array de tipo Employee mostrando todos los datos que no tengan el isEmpty en 0
 *
 * \param Recibe un array de tipo Employee
 * \param  Recibe el tamaño de dicho array
 * \return retorna 0
 *
 */


int printEmployees(Employee list[], int len)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Empleados ****\n\n");

    printf(" ID Nombre Apellido Sector Salario \n");
    for(int i=0; i < len; i++)
    {
        if( list[i].isEmpty == 0)
        {
            showEmployee(list[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay empleados que mostrar---");
    }

    printf("\n\n");
    return 0;
}
/** \brief Ordena los indices del array de tipo Employee por sector
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe el tamaño
 * \param Recibe el sentido de orden. Si es ascendente o descendente.
 * \return retorna 0
 *
 */


int sortEmployeesBySector(Employee list[], int len, int order)
{

    Employee auxEmpleado;
    if (order==0)
    {


    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if( list[i].sector > list[j].sector  && list[i].isEmpty == 0 && list[j].isEmpty == 0)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }


    }
    else
    {
        for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if( list[i].sector < list[j].sector  && list[i].isEmpty == 0 && list[j].isEmpty == 0)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }
    }
    return 0;
}

/** \brief Muestra el menu de opciones para que el usuario intrduzca la opcion a realizar
 *


 * \return retorna 0
 *
 */


int menu()
{

    int opcion;
    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Modificar Empleado\n");
    printf("3- Bajar Empleado\n");
    printf("4- Informar\n");
    printf("5- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Inicializa el array de tipo Employee, cargandole 1 al campo isEmplty en cada indice
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe el tamaño
 *
 *
 */

void initEmployees(Employee list[], int len)
{

    for(int i=0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }
}
/** \brief Busca un indice que este libre (con el campo isEmpty cargado en 1)
 *
 * \param Recibe un array de tipo Employee
 * \param recibe el tamaño
 * \return Retorna el indice
 *
 */

int searchFree(Employee list[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Busca un empleado que tenga el campo esEmpty en 0 y que tenga el mismo id que el de referencia
 *
 * \param Recibe un Id a buscar
 * \param recibe un array de tipo Employee
 * \param Recibe el tamaño de dicho array
 * \return Retorna el indice donde se encuentra el empleado con esa id
 *
 */

int findEmployee(int id, Employee list[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( list[i].isEmpty == 0 && list[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
/** \brief Da de alta a un empleado
 *
 * \param Recibe un array de tipo Employee
 * \param Eecibe el tamaño de dicho array
 * \param Recibe el id del empleado
 * \param Recibe el nombre del empleado
 * \param Recibe el apellido del empleado
 * \param Recibe el salario del empleado
 * \param Recibe el sector del empleado
 * \return Retorna -1
 *
 */

int addEmployee(Employee list[], int len,int id,char name[], char lastName[], float salary, int sector)
{


    int indice;
    int esta;







    system("cls");
    printf("**** Alta Empleado ****\n\n");

    indice = searchFree(list, len);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas empleados\n");
        system("pause");
    }
    else
    {

        esta = findEmployee(id, list, len);

        if( esta != -1)
        {
            printf("\nId ya registrado\n");
            showEmployee(list[esta]);
            system("pause");
        }
        else
        {




            list[indice] = newEmployee(id, name, lastName, sector, salary);

        }
    }
    return -1;
}

/** \brief Se encarga de registrar un nuevo empleado con los datos que lo componen
 *
 * \param Recibe el id del empleado
 * \param Recibe el nombre del empleado

 * \param Recibe el apellido del empleado
 * \param Recibe el sector del empleado
 * \param Recibe el salario del empleado
 * \return Retorna el array del empleado
 *
 */

Employee newEmployee(int id, char name[], char lastName[], int sector, float salary)
{
    Employee nuevoEmpleado;
    nuevoEmpleado.id = id;
    strcpy(nuevoEmpleado.name, name);
    strcpy(nuevoEmpleado.lastName, lastName);
    nuevoEmpleado.sector = sector;
    nuevoEmpleado.salary = salary;

    nuevoEmpleado.isEmpty = 0;

    return nuevoEmpleado;
}

/** \brief Se encarga de dar de baja a un empleado cambiando su campo de isEmpty de 1 a 0
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe su tamaño
 * \return Retorna -1
 *
 */

int removeEmployee(Employee list[], int len)
{


    int indice;
    int id;
    char confirma;

    system("cls");
    printf("**** Baja Empleado ****\n\n");

    printf("Ingrese empleado: ");
    scanf("%d", &id);

    indice = findEmployee(id, list,len);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese Id\n");
        system("pause");
    }
    else
    {
        showEmployee(list[indice]);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            list[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el empleado\n");

        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return -1;
}
/** \brief Modifica los datos de un empleado. Sea su nombre, apellido, salario o sector
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe su tamaño
 * \return Retorna -1
 *
 */


int modifyEmployee(Employee list[], int len)
{


    int indice;
    int id;
    int opcion;
    int sector;
    char name[51];
    char lastName[51];
    float salary;


    system("cls");
    printf("**** Modificar Alumno ****\n\n");

    printf("Ingrese Id: ");
    scanf("%d", &id);

    indice = findEmployee(id, list, len);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese Id\n");
        system("pause");
    }
    else
    {
        showEmployee(list[indice]);

        printf("Modificar\n\n");
        printf("Nombre 1\n");
        printf("Apllido 2\n");
        printf("Sector 3\n");
        printf("Salario 4\n");


        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Ingrese nombre 1: ");
            fflush(stdin);
            gets(name);
            // falta validar nota
            strcpy(list[indice].name,name);


            printf("Se actualizo el nombre");

        }
        else if( opcion == 2)
        {
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(lastName);
             // falta validar nota
            strcpy(list[indice].lastName,lastName);

            printf("Se actualizo el apellido\n");


        }
        else if(opcion==3)
        {
            printf("Ingrese sector");
            scanf("%d",&sector);
            list[indice].sector=sector;
            printf("Se actualizo el sector\n");
        }
        else if(opcion==4)
        {
            printf("Ingrese salario\n");
            fflush(stdin);
            scanf("%f",&salary);
            list[indice].salary=salary;
            printf("Se actualizo el salario\n");
        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return -1;
}

/** \brief Muestra un menu de opciones de los informes a mostrar
 *
 *
 *
 * \return Retorna la opcion ingresada
 *
 */

int menuInformes()
{
    int opcion;

    system("cls");
    printf("****** Informes *******\n\n");
    printf("1-Mostrar Empleados ordenados alfabeticamente por apellido y sector\n");
    printf("2-Mostrar total y promedio de los salarios,y cuantos empleados superan el salario promedio\n");

    printf("3-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Muestra los informes seleccionados
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe el tamaño
 *
 *
 */

void InformEmployee (Employee list[], int len)
{
   int order;
    char salir = 'n';
    system("cls");
    printf("***** Informes Empleados ****\n\n");

    do
    {
        switch( menuInformes())
        {
        case 1:
            printf("Ingrese Sentido. 0- Ascendente - Otro Numero- Descendente\n");
            scanf("%d",&order);
            sortEmployeesBySector(list,  len,  order);
            sortEmployeesByName( list,  len,  order);
            printEmployees(list,len);
            break;

        case 2:
            CalcSalario(list,len);
            break;
        case 3:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

}


/** \brief Se encarga de calcular y mostrar el total de los salarios, el promedio y la cantidad de empleados que cobran mas que el promedio
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe su tamaño
 *
 *
 */

void CalcSalario(Employee list[], int len)
{
    float acumulador=0;
    float prom=0;
    int cont=0;



    for (int i=0;i<len;i++)
    {

        if(list[i].isEmpty==0)
        {
            acumulador+=list[i].salary;
            cont++;
        }
    }
    prom=acumulador/cont;
    cont=0;
    for (int i=0;i<len;i++)
    {
        if (list[i].salary>prom)
        {
            cont++;
        }
    }
    printf("El total de los salarios es %.2f\n",acumulador);
    printf("El salario promedio es de %.2f\n",prom);
    printf("La cantidad de empleados que cobran mas que el promedio es de %d",cont);




}


/** \brief Ordena los empleados por apellido
 *
 * \param Recibe un array de tipo Employee
 * \param Recibe el tamaño
 * \param Recibe el sentido a ordenar
 * \return Retorna 0
 *
 */

int sortEmployeesByName(Employee list[], int len, int order)
{

    Employee auxEmpleado;
    if (order==0)
    {


    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if( list[i].sector == list[j].sector  && list[i].isEmpty == 0 && list[j].isEmpty == 0 && strcmp(list[i].lastName,list[j].lastName)==1)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }


    }
    else
    {
        for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if( list[i].sector == list[j].sector  && list[i].isEmpty == 0 && list[j].isEmpty == 0 && strcmp(list[i].lastName,list[j].lastName)==-1)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }
    }
    return 0;
}


