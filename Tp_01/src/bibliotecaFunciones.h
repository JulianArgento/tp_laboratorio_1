#ifndef BIBLIOTECAFUNCIONES_H_INCLUDED
#define BIBLIOTECAFUNCIONES_H_INCLUDED


/** \brief funcion que le muestra al usuario el menu de opciones y recibe su input
 *
 * \param x int  recibe el valor del operando 1 para mostrar su valor actual
 * \param y int  recibe el valor del operando 2 para mostrar su valor actual
 * \return int   retorna la opcion elegida por el usuario
 *
 */
int menu(int x, int y);



/** \brief funcion que recibe dos operandos enteros y los suma.
 *
 * \param x int primer operando.
 * \param y int segundo operando.
 * \param resultado int* direccion de memoria donde se guardara el resultado entero.
 * \return int retorna 1 en caso de error.
 *
 */
int sumar(int x, int y, int* resultado);




/** \brief funcion que recibe dos operandos enteros y los resta.
 *
 * \param x int primer operando.
 * \param y int segundo operando .
 * \param resultado int* direccion de memoria donde se guardara el resultado entero.
 * \return int retorna 1 en caso de error
 *
 */
int restar(int x, int y, int* resultado);




/** \brief funcion que recibe dos operandos y los divide, validando si el segundo operando es 0.
 *
 * \param x int operando dividendo.
 * \param y int operando divisor .
 * \param resultado float* direccion de memoria donde se guardara el resultado flotante.
 * \return int retorna 1 en caso de error.
 *
 */
int dividir(int x , int y, float* resultado);




/** \brief funcion que recibe dos operandos enteros y los multiplica.
 *
 * \param x int primer operando.
 * \param y int segundo operando.
 * \param resultado int* direccion de memoria donde se guardara el resultado.
 * \return int retorna 1 en caso de error.
 *
 */
int multiplicar(int x,int y,int* resultado);




/** \brief funcion que recibe un numero entero y lo factoriza.
 *
 * \param x int operando a factorizar.
 * \return int resultado de la factorizacion.
 *
 */
int factorizar(int x);



/** \brief funcion que recibe los resultados de las operaciones, filtra errores y se las muestra al usuario
 *
 * \param suma int resultado de la suma de A y B
 * \param resta int resultado de la resta de A y B
 * \param multiplicacion int producto entre A y B
 * \param division float division entre A y B
 * \param factorialx int factorial de A
 * \param factorialy int factorial de B
 * \param y int primer operando utilizado para validar
 * \param x int segundo operando utilizado para validar
 * \return void
 *
 */
void mostrarResultados(int suma, int resta, int multiplicacion, float division, int factorialx, int factorialy, int y, int x);






#endif // BIBLIOTECAFUNCIONES_H_INCLUDED
