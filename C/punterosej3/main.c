#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int serial;
    int age;
    char sex;
}Employee;
Employee* allocEmployee()
{

    Employee* ptr=(Employee*)malloc(sizeof(Employee));
    if (ptr!= NULL)
    {
        return ptr;
    }
    else
        return NULL;
}
void loadEmployees(Employee* array[],int size)
{
    Employee* aux;
    int serial=1000;
    int age;
    char sex;
    for(int i=0;i<size;i++)
    {
        aux= allocEmployee();
        if(aux!=NULL)
        {
            aux->serial=serial;
            serial++;
            printf("Mete la edad del sujeto en la posicion %d\n",i+1);
            fflush(stdin);
            do{
            scanf("%d",&age);
            aux->age=age;
            if(age<0)
                printf("No podes tener 1 edad negativa la re puta madre q te pario uwu\n");
            }while(age<0);
            printf("Introduce el sexo del sospechoso en la posicion %d\n",i+1);
            do{
            fflush(stdin);
            scanf("%c",&sex);
            if(sex!='m'&& sex!='f')
                printf("Q te haces el no binario hippie roñoso.Seguro q sos un zurdo q habla como retrasade. Anda a la conche de tu madre. Sos peor q ese q se indentifica como un perro\n");
            }while(sex!='m'&& sex!='f');
            aux->sex=sex;
            array[i]=aux;
        }
    }
}
float averageAge(Employee* array[],int size)
{
    float average=0;
    for(int i=0;i<size;i++)
    {
        average+=array[i]->age;
    }
    return average/size;
}
void printHighest(Employee* array[],int size)
{
    int maxAge=0;
    for(int i=0;i<size;i++)
    {
        if(array[i]->age>maxAge)
        {
            maxAge=array[i]->age;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(array[i]->age==maxAge)
        {
            printf("Legajo de la persona con mayor edad: %d\n",array[i]->serial);
            printf("Sexo de la persona con la mayor edad %c\n",array[i]->sex);
            break;
        }
    }
}
int main()
{
    const int employees=30;
    Employee* ptrArray[employees];
    loadEmployees(ptrArray,employees);
    float average= averageAge(ptrArray,employees);
    printf("Hello world! El promedio de edad es %.2f UWU\n",average);
    printHighest(ptrArray,employees);
    return 0;
}
