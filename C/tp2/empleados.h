#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED


typedef struct
{
    int id;
    char name[51];

    char lastName[51];

    int sector;
    float salary;

    int isEmpty;
} Employee;


#endif // EMPLEADOS_H_INCLUDED

void showEmployee(Employee  x);
int printEmployees(Employee list[], int len);
int sortEmployees(Employee list[], int len,int order);
void initEmployees(Employee list[], int len);
int searchFree(Employee list[], int len);
int findEmployee(int id, Employee list[], int len);
Employee newEmployee(int id, char name[], char lastName[], int sector, float salary);
int addEmployee(Employee list[], int len,int id,char name[], char lastName[], float salary, int sector);
int removeEmployee(Employee list[], int len);
int modifyEmployee(Employee list[], int len);
int menu();
int menuInformes();
void InformEmployee (Employee list[], int len);
void CalcSalario(Employee list[], int len);
int sortEmployeesBySector(Employee list[], int len, int order);
int sortEmployeesByName(Employee list[], int len, int order);
