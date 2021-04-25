#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee list[], int len);

/** \brief To search the first free position of the array
 *
 * \param list Employee array of employees
 * \param len int Array length
 * \return int return (-1) if Error [Invalid Lenght , NULL pointer or full array]- index if Ok
 *
 */

int SearchFree(Employee list[],int len);
/** \brief To create a new employee
 *
 * \param list Employee Array of employees
 * \param len int Array length
 * \param id int id of employee
 * \return int return (-1) if Error[could not create or add]- (0) if Ok
 *
 */

int CreateNewEmployee(Employee list[],int len,int id);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int addEmployee(Employee list[], int len, int id, char name[],char
lastName[],float salary,int sector);
/** \brief Finds an employee by id
 *
 * \param list Employee array of employees
 * \param len int
 * \param id int
 * \return Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - Index if Ok
 *
 */

int findEmployeeById(Employee list[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee list[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);
/** \brief Print the content of an element of type Employee
 *
 * \param empl Employee
 * \return returns int 0
 *
 */

int printEmployee(Employee empl);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee list[], int length);
/** \brief Displays options to show in the menu function
 */

void PrintOptions();
/** \brief it gets a number introduced by the user to do a certain operation
 *

 * \return int option
 *
 */

int menu();
/** \brief Displays options to show the fields that the user can modify

 */

void PrintModifyOptions();
/** \brief it gets a number introduced by the user to modify a certain field

 */

int ModifyMenu();
/** \brief Modifies a field of an employee chosen by the user
 *
 * \param list Employee Array of employees
 * \param len int
 * \param id int
 *
 */

void ModifyEmployee(Employee list[],int len,int id);
/** \brief Sums the salaries of all the employees
 *
 * \param list Employee Array of employees
 * \param len int
 * \return float returns the sum of all salaries
 *
 */

float SumSalaries (Employee list[],int len);
/** \brief Gets the average salary of the employees
 *
 * \param list Employees
 * \param len int
 * \param total float
 * \return float returns the average value
 *
 */

float getAverageSalary (Employee list[],int len,float total);
/** \brief Counts how many employees earn more than the average
 *
 * \param list Employee array of employees
 * \param len int
 * \param total float
 * \return int count
 *
 */

int CountHighSalaries(Employee list[],int len,float average);

#include "ArrayEmployees.c"

#endif // ARRAYEMPLOYEES_H_INCLUDED
