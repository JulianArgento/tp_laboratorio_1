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

int menu();

int menuInforme();

int menuModificacion();

/** \brief Para indicar de manera logica que todas las posiciones del array estan
vacias, esta funcion pone la flag (isEmpty) en 1 en todas las posiciones del array
* \param list Employee[] puntero al array de empleados
* \param len int tamanio del array
* \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
*
*/
int initEmployees(Employee list[], int len);

/** \brief Esta funcion busca la primera posicion libre (isEmpty en 1) en un array de empleados
 *
 * \param list[] Employee puntero a array de empleados
 * \param len int tam del array de empleados
 * \return int si encuentra un lugar libre, retorna el indice del array en el cual se encuentra, de lo contrario retornara -1
 *
 */
int buscarLibre(Employee list[], int len);

/** \brief agrega en un array existente de empleados un empleado nuevo con los parametros recibidos en la primera posicion libre.
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \param id int id del nuevo empleado
 * \param name[] char nombre del nuevo empleado
 * \param lastName[] char apellido del nuevo empleado
 * \param salary float salario del nuevo empleado
 * \param sector int sector del nuevo empleado
 * \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
 *
 */
int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief busca un empleado por su numero de id y, en caso de encontrarlo, retorna el indice del array en el que se encuentra
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \param id int id del empleado a buscar
 * \return int retorna el indice del array donde se encuentra el empleado o (-1) en caso de no encontrarse un empleado
 *
 */
int findEmployeeById(Employee list[], int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \param id int id del empleado que se desea eliminar
 * \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
 *
 */
int removeEmployee(Employee list[], int len, int id);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \param order int [1] indica ascendente y [0] descendente
 * \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);

/** \brief muestra en pantalla un empleado
 *
 * \param anEmployee Employee empleado que se desea mostrar
 * \return void
 *
 */
void printEmployee(Employee anEmployee);

/** \brief imprime el contenido del array de empleados
 *
 * \param list[] Employee array de empleados
 * \param length int tam del array
 * \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
 *
 */
int printEmployees(Employee list[], int length);

/** \brief Se ingresa el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \return int retorna -1 en caso de error [puntero NULL o tam invalido] o (0) si esta Ok
 *
 *
 */
int modificarEmpleado(Employee list[], int len);



/** \brief informa el total y promedio de los salarios, y cuántos empleados superan el salario promedio
 *
 * \param list[] Employee array de empleados
 * \param len int tam del array
 * \return void
 *
 */
void informeSueldo(Employee list[], int len);





#endif // ARRAYEMPLOYEES_H_INCLUDED
