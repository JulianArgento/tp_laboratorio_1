#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}




int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloNumerico(int num)
{
    int todoOk=0;

    char buffer[20];

    itoa(num,buffer,10);

    if(esNumerico(buffer))
    {
        todoOk=1;



    }


    return todoOk;

}



int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux)&&strlen(aux)<51)
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

void getConfirmacion(char mensaje[], char* rta)
{
    char confirmacion= *rta;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&confirmacion);

     while(confirmacion!='s'&& confirmacion!='n')
            {
                printf("Opcion no valida.");
                printf("%s",mensaje);
                fflush(stdin);
                scanf("%c",&confirmacion);
            }
    *rta = confirmacion;


}


int menu()
{
    system("cls");

    int opcion;


    printf("-----Elija la operacion a realizar-----\n\n\n");
    printf("*****************************************************/\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("*****************************************************/\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;




}

int subMenu()
{
    system("cls");

    int opcion;


    printf("-----Elija la modificacion a realizar-----\n\n\n");
    printf("1. Nombre\n");
    printf("2. Horas trabajadas \n");
    printf("3. Sueldo \n");

    printf("4. Salir\n");

    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}

int menuOrdenar()
{
    system("cls");

    int opcion;


    printf("-----Elija el dato a ordenar-----\n\n\n");
    printf("1. Id\n");
    printf("2. Nombre\n");
    printf("3. Horas de trabajo\n");
    printf("4. Sueldo\n");
    printf("5. Salir\n");


    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}

int menuCriterio()
{
    system("cls");

    int opcion;


    printf("-----Elija el criterio de ordenamiento-----\n\n\n");
    printf("1. Ascendente\n");
    printf("2. Descendente\n");


    printf("Ingrese opcion: ");
    printf("\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}



