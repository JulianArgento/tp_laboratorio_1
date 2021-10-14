#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 1000

int main()
{

	setbuf(stdout, NULL);
    char salir= 'n';

    int nextId=2000;

    Employee auxEmployee;

    int idEliminar;
    int orden;




    Employee list[TAM];

    if(initEmployees(list,TAM)==0)
    {
        printf("Empleados inicializados \n");
    }
    else
    {
        printf("Empleados no inicializados \n");
    }




    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");

            printf("-----Alta de empleado-----\n");

            if (!getStringLetras("Ingrese el nombre: ",auxEmployee.name))
            {
                printf ("El nombre debe estar compuesto solo por letras y no puede superar los 50 caracteres\n");
                break;
            }

            if (!getStringLetras("Ingrese el apellido: ",auxEmployee.lastName))
            {
                printf ("El apellido debe estar compuesto solo por letras y no puede superar los 50 caracteres\n");
                break;
            }


            printf("Ingrese el sueldo: ");
            fflush(stdin);
            scanf("%f",&auxEmployee.salary);


            printf("Ingrese el sector: ");
            fflush(stdin);
            scanf("%d",&auxEmployee.sector);


            auxEmployee.id=nextId;
            nextId++;

            if(addEmployee(list,TAM,auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)==0)
            {
                printf("Empleado dado de alta exitosamente.\n");
            }
            else
            {
                printf("No hay mas lugar en sistema para agregar empleados.\n");
            }

            break;


        case 2:
            system("cls");
            printf("-----Baja de empleado-----\n");
            printEmployees(list,TAM);
            printf("Ingrese el id del empleado que desea dar de baja: ");
            fflush(stdin);
            scanf("%d",&idEliminar);

            removeEmployee(list,TAM,idEliminar);



            break;

        case 3:
            if( modificarEmpleado(list,TAM)==0)
            {
                printf("Modificacion realizada con exito\n");
            }

            break;

        case 4:
            system("cls");

            switch(menuInforme())
            {
            case 1:
                system("cls");
                printf("-----Lista de empleados-----\n");
                printEmployees(list,TAM);
            break;

            case 2:
                system("cls");
                printf("-----Ordenar empleados-----\n\n");


                printf("0-Ordenar de manera descendente\n");
                printf("1-Ordenar de manera ascendente\n\n");

                printf("Seleccione el criterio de ordenamiento:");
                scanf("%d",&orden);

                if(orden==0||orden==1)
                {
                    if(sortEmployees(list,TAM,orden)==0)
                    {
                        printf("Empleados ordenados con exito\n");
                    }
                    else
                    {
                        printf("Hubo un error. No se pudo ordenar a los empleados por el criterio elegido.");
                    }

                }
                else
                {
                    printf("Opcion invalida.\n");

                }

            break;

            case 3:
                system("cls");
                printf("-----Informe sueldos-----\n");
                informeSueldo(list,TAM);
            break;

            case 4:
            break;

            default:
                printf("Opcion invalida\n");
            break;
            }
        break;

        case 5:

            printf("Seguro que desea salir? (ingrese n para cancelar la salida): ");
            fflush(stdin);
            scanf("%c",&salir);
        break;

        default:
            printf("Opcion invalida\n");
        break;



        }


        system("pause");
    }
    while(salir=='n');



    return 0;
}
