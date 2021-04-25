#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
/** \brief Reserves a space in dynamic memory for a new employee
 *
 * \return Employee*
 *
 */

Employee* employee_new();
/** \brief Parses the data from String obteined by reading it from a text file
           into each respective type, and it saves them on each field.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee*
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief Frees the dynamic memory space reserved for an employee.
 *

 */

void employee_delete(Employee* this);
/** \brief It sets the id field on an employee
 *
 * \param Employee* this
 * \param int id
 * \return 0 if successful or -1 if failure
 *
 */

int employee_setId(Employee* this,int id);
/** \brief It gets the id field from an employee
 *
 * \param Employee* this
 * \param int* id
 * \return 0 if successful or -1 if failure
 *
 */

int employee_getId(Employee* this,int* id);
/** \brief It sets the nombre  field on an employee
 *
 * \param Employee* this
 * \param char* nombre
 * \return 0 if successful or -1 if failure
 *
 */

int employee_setNombre(Employee* this,char* nombre);
/** \brief It gets the nombre field from an employee
 *
 * \param Employee* this
 * \param char* nombre
 * \return 0 if successful or -1 if failure
 *
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief It sets the horasTrabajadas field on an employee
 *
 * \param Employee* this
 * \param int horasTrabajadas
 * \return 0 if successful or -1 if failure
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief It gets the horasTrabajadas field from an employee
 *
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return 0 if successful or -1 if failure
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief It sets the sueldo field on an employee
 *
 * \param Employee* this
 * \param int sueldo
 * \return 0 if successful or -1 if failure
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief It gets the sueldo field from an employee
 *
 * \param Employee* this
 * \param int* sueldo
 * \return 0 if successful or -1 if failure
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);
/** \brief Compares 2 names
 *
 * \param Employee* e1
 * \param Employee* e2
 * \return -1 if the first is smaller, 0 if they are equal or 1 if the second is bigger
 *
 */

int employee_CompareByName(Employee* e1, Employee* e2);
/** \brief Compares 2 IDs
 *
 * \param Employee* e1
 * \param Employee* e2
 * \return -1 if the first is smaller, 0 if they are equal or 1 if the second is bigger
 *
 */
int employee_CompareById(Employee* e1, Employee* e2);
/** \brief Creates a new employee
 *
 * \param Employee* aux
 * \return 0 if successful or -1 if failure
 *
 */

int employee_createEmployee(Employee* aux);
/** \brief It edits an employee
 *
 * \param LinkedList* pArrayList
 * \return 0 if successful or -1 if failure
 *
 */

int employee_editEmployee(LinkedList* pArrayList);
/** \brief It removes an employee
 *
 * \param LinkedList* pArrayList
 * \return 0 if successful or -1 if failure
 *
 */
int employee_removeEmployee(LinkedList* pArrayList);
/** \brief It prints an employee
 *
 * \param Employee* aux
 * \param int index
 * \return returns 1
 *
 */

int employee_ListEmployee(Employee* pAux,int index);
/** \brief It lists all the employees on the linked list
 *
 * \param LinkedList* pArrayList
 * \return 0 if successful or -1 if failure
 *
 */

int employee_ListEmployees(LinkedList* pArrayList);

#endif // employee_H_INCLUDED
