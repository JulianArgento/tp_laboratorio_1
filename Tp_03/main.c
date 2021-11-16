#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    char salir = 'n';
    int carga=0;
    char rta;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {

        switch(menu())
        {
        case 1:
            system("cls");

            if(carga)
            {
                printf("No se puede cargar mas de una vez el archivo");
            }
            else
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {

                    carga=1;
                }

            }



            break;
        case 2:
            system("cls");
            if(carga)
            {
                printf("No se puede cargar mas de una vez el archivo");
            }
            else
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {

                    carga=1;
                }

            }

            break;
        case 3:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {
                controller_addEmployee(listaEmpleados);
            }

            break;
        case 4:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
            }

            break;

        case 5:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
            }

            break;


        case 6:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }

            break;

        case 7:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
            }

            break;
        case 8:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {

                getConfirmacion("Los contenidos del archivo data.csv seran sobreescritos. Confirma el guardado? (s para si, n para no) : ",&rta);


            if(rta=='s')
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("Datos de texto guardados con exito.\n");
            }
            else
            {
                printf("Guardado de datos de texto cancelado\n");
            }


            }


            break;
         case 9:
            system("cls");
            if(!carga)
            {
                printf("Antes de operar se debe cargar un archivo");
            }
            else
            {

                getConfirmacion("Los contenidos del archivo data.bin seran sobreescritos. Confirma el guardado? (s para si, n para no):",&rta);


                if(rta=='s')
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    printf("Datos binarios guardados con exito.\n");
                }
                else
                {
                    printf("Guardado de datos binarios cancelado\n");
                }

            }

            break;

         case 10:
          getConfirmacion("Confirma la salida? (s para si, n para no): ",&salir);

        break;

         default:
        printf("Opcion no valida\n");
        break;



        }
        system("pause");
    }
    while(salir == 'n');



    return 0;
}

