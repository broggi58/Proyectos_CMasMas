
/** \brief Controller that excecutes the commands  to load data from a text file to the linked list
 *
 * \param char* path
 * \param LinkedList* pArrayListEmployee
 * \return int 0 if successful or -1 if failure
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to load data from a bin file to the linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 if successful or -1 if failure
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to add an element to the linked list
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to edit an element on the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to remove an element from the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to print the elements of the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Shows the options to the user for sorting the element on the linked list and gets the option entered by the user
 *
 * \return int
 *
 */
int menuSort();
/** \brief Controller that excecutes the commands  to sort the data in the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to save the data of the linked list onto a text file
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Controller that excecutes the commands  to save the data of the linked list to a bin file
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Shows the options of the menu to edit an employee and gets the option entered by the user
 *
 * \return int
 *
 */
int ModifyMenu();
/** \brief Shows the options of the main menu to the user and gets the option entered by the user
 *
 * \return int
 *
 */
int menu();
/** \brief Shows the options to the user for sorting the element on the linked list
 *
 * \return void
 *
 */
void PrintOptionsSort();




