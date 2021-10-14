#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>
#include <ctype.h>
#include "utn.h"


int menu()
{
    system("cls");

    int opcion;

    printf("-----ABM de empleados-----\n\n\n");
    printf("-----Elija la operacion a realizar-----\n\n\n");
    printf("1. Altas\n");
    printf("2. Baja \n");
    printf("3. Modificar \n");
    printf("4. Informar\n");
    printf("5. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;




};

int menuInforme()
{
    int opcion;

    printf("-----Informe de empleados-----\n\n\n");
    printf("-----Elija el informe deseado-----\n\n\n");
    printf("1. Listado de empleados \n");
    printf("2. Ordenar listado por apellido y sector\n");
    printf("3. Informe salarios\n");
    printf("4. Volver al menu\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuModificacion()
{
    system("cls");

    int opcion;

    printf("-----Modificacion de empleado-----\n\n\n");
    printf("-----Elija lo que desea modificar del empleado seleccionado-----\n\n\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Salario\n");
    printf("4- Sector\n");
    printf("5- Salir\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int initEmployees(Employee list[], int len)
{
    int todoOk=-1;

    if(list!=NULL&&len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }

        todoOk=0;
    }

    return todoOk;

};

int buscarLibre(Employee list[], int len)
{
    int indice=-1;

    if(list!=NULL&&len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;

};

int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    int todoOk=-1;
    int i;

    if(list!=NULL&&len>0)
    {


        i=buscarLibre(list,len);

        if(i==-1)
        {
            printf("No hay mas lugar en el sistema.\n\n");
        }
        else
        {
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);

            list[i].id=id;
            list[i].isEmpty=0;
            list[i].salary=salary;
            list[i].sector=sector;


            todoOk=0;

        }


    }


    return todoOk;

};

void printEmployee(Employee anEmployee)
{


    printf("%d    %-8s  %-8s    %.2f      %-3d\n",anEmployee.id,anEmployee.name,anEmployee.lastName,anEmployee.salary,anEmployee.sector);



}

int printEmployees(Employee list[], int len)
{
    int todoOk=-1;

    if(list!=NULL&&len>0)
    {
        int flag=1;

        system("cls");

        printf("-----Empleados-----\n\n");
        printf("Id      Nombre     Apellido    Sueldo      Sector\n");
        printf("--------------------------------------------------\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {

                printEmployee(list[i]);

                flag=0;
            }

        }

        if(flag)
        {
            printf("No se encontro ningun empleado.\n\n");
        }
        else
        {
            todoOk=0;
        }

    }


    return todoOk;

}

int findEmployeeById(Employee list[], int len, int id )
{

    int indice=-1;

    if(list!=NULL&&len>0&&id>=2000)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id&&list[i].isEmpty==0)
            {
                indice=i;
                break;
            }

        }

    }


    return indice;

}

int removeEmployee(Employee list[], int len, int id)
{
    int todoOk=-1;
    int indice;
    char respuesta;

    if(list!=NULL&&len>0)
    {

        if(findEmployeeById(list,len,id)!=-1)
        {
            indice = findEmployeeById(list,len,id);


            printEmployee(list[indice]);

            printf("Seguro que desea eliminar a este empleado? (s para si, n para no): ");
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                list[indice].isEmpty=1;
                printf("Empleado dado de baja\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");

            }



            todoOk=0;

        }
        else
        {
            printf("Ha ocurrido un error. Empleado no encontrado\n\n");
        }

    }


    return todoOk;


}

int sortEmployees(Employee list[], int len, int order)
{
    int todoOk=-1;
    Employee auxEmployee;


    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order)
                {
                    if(strcmp(list[i].lastName,list[j].lastName)<0||(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector>list[j].sector))
                    {
                        auxEmployee= list[i];
                        list[i]=list[j];
                        list[j]=auxEmployee;

                    }


                }
                else
                {
                    if(strcmp(list[i].lastName,list[j].lastName)>0||(strcmp(list[i].lastName,list[j].lastName)==0&&list[i].sector<list[j].sector))
                    {
                        auxEmployee= list[i];
                        list[i]=list[j];
                        list[j]=auxEmployee;

                    }

                }

            }
        }

        todoOk=0;


    }
    return todoOk;
}

void informeSueldo(Employee list[], int len)
{
    int todoOk=-1;
    float sumaSalarios=0;
    float salarioPromedio;

    int contador=0;
    int contadorMayorPromedio=0;

    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                sumaSalarios+=list[i].salary;
                contador++;
            }

        }

        if(contador!=0)
        {
            salarioPromedio = (float) sumaSalarios/contador;
        }


        for(int i=0; i<len; i++)
        {
            if(list[i].salary>salarioPromedio&&list[i].isEmpty==0)
            {
                contadorMayorPromedio++;
            }
        }

        todoOk=0;
    }


    if(todoOk==0)
    {
        printf("La suma de los salarios es de %.2f , el salario promedio es de %.2f y hay un total de %d empleados que superan el promedio. \n ",sumaSalarios,salarioPromedio,contadorMayorPromedio);
    }
    else
    {
        printf("No se pudo realizar la operacion.\n");
    }


}

int modificarEmpleado(Employee list[],int len)
{
    int todoOk = -1;
    int id;
    int indice;
    char confirm;
    char auxName[51];
    char auxSurname[51];
    float auxSalary;
    int auxSector;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("       *** Modificar Empleado ***      \n");
        printf("----------------------------------\n");

        printf("-----Lista de empleados-----\n");
        printEmployees(list,len);
        printf("----------------------------------\n");

        printf("Ingrese id del empleado que desea modificar: ");
        scanf("%d", &id);

        indice = findEmployeeById(list,len,id);

        if(indice == -1)
        {
            printf("No existe un empleado con id: %d\n", id);
        }
        else
        {
            printEmployee(list[indice]);
            printf("\n");
            printf("Confirma modificacion? ('s' para confirmar)\n");
            fflush(stdin);
            scanf("%c", &confirm);

            confirm = tolower(confirm);

            if(confirm == 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    if (!getStringLetras("Ingrese nuevo nombre: ",auxName))
                    {
                        printf ("El nombre debe estar compuesto solo por letras y no puede superar los 50 caracteres\n");
                        break;
                    }
                    strcpy(list[indice].name, auxName);
                    break;
                case 2:
                    if (!getStringLetras("Ingrese nuevo apellido: ",auxSurname))
                    {
                        printf ("El apellido debe estar compuesto solo por letras y no puede superar los 50 caracteres\n");
                        break;
                    }
                    strcpy(list[indice].lastName, auxSurname);
                    break;
                case 3:
                    printf("Ingrese nuevo salario: ");
                    scanf("%f", &auxSalary);
                    list[indice].salary = auxSalary;
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &auxSector);
                    list[indice].sector = auxSector;
                    break;
                case 5:
                    break;
                }
                todoOk = 0;
            }
            else
            {
                printf("Se ha cancelado la baja \n");
            }
        }
    }
    return todoOk;
}
