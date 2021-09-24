#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaFunciones.h"

int menu(int x, int y)
{


    int opcion;

    printf("Menu de operaciones\n\n");
    printf("1. Ingresar 1er operando. A= %d\n",x);
    printf("2. Ingresar 2do operando. B= %d\n",y);
    printf("3. Calcular operaciones\n");
    printf("4. Resultados\n");
    printf("5. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int sumar(int x, int y, int* resultado)
{
    int errores=0;

    *resultado= x+y;

   return errores;

}

int restar(int x, int y, int* resultado)
{
    int errores=0;

    *resultado= x-y;

    return errores;

}


int dividir(int x, int y , float* resultado)
{
    int errores=0;

    if(y==0)
    {
        errores++;
    }
    else
    {
        *resultado = (float) x/y;
    }



    return errores;

}

int multiplicar(int x, int y, int* resultado)
{

    int errores=0;

    *resultado = x*y;


    return errores;



}

int factorizar(int x)
{
    int resultado=0;


    if(x<0)
    {
        resultado=0;
    }
    else
    {
        if(x==0 || x==1)
        {
            resultado=1;
        }
        else
        {
            resultado = (x*factorizar(x-1));
        }
    }



    return resultado;


}

void mostrarResultados(int suma, int resta, int multiplicacion, float division, int factorialx, int factorialy, int y, int x)
{

    printf("El resultado de A+B es: %d \nEl resultado de A-B es: %d \nEl resultado de A*B es: %d \n",suma,resta,multiplicacion);

    if(y==0)
    {
        printf("No se puede dividir por cero. \n");

    }
    else
    {
        printf("El resultado de A/B es: %.2f. \n",division);
    }




    if(x<=12)
    {
        if(factorialx==0)
        {
            printf("No se puede factorizar un numero negativo \n");
        }
        else
        {
            printf("El factorial de A es: %d \n",factorialx);
        }
    }
    else
    {
        printf("No se puede factorizar numeros mayores a 12 (el resultado es demasiado grande para mostrarlo)\n");
    }


    if(y<=12)
    {
        if(factorialy==0)
        {
            printf("No se puede factorizar un numero negativo \n");
        }
        else
        {
            printf("El factorial de B es: %d \n",factorialy);
        }
    }
    else
    {
        printf("No se puede factorizar numeros mayores a 12 (el resultado es demasiado grande para mostrarlo)\n");
    }





}

