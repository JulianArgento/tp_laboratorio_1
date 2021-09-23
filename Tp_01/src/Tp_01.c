

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaFunciones.h"

int main() {
	setbuf(stdout, NULL);

		char salir ='n';
	    int x=0;
	    int y=0;



	    int suma;
	    int resta;
	    float division;
	    int multiplicacion;
	    int factorialx=0;
	    int factorialy=0;

	    int ingresoA= 0;
	    int ingresoB= 0;
	    int opero= 0;



	    do
	    {
	        system("cls");
	        switch(menu(x,y))
	        {
	        case 1:
	            printf("Ingrese un valor para A: ");
	            fflush(stdin);
	            scanf("%d", &x);
	            printf("El valor de A ahora es: %d \n",x);
	            ingresoA=1;
	            break;

	        case 2:
	            printf("Ingrese un valor para B: ");
	            fflush(stdin);
	            scanf("%d", &y);
	            printf("El valor de B ahora es: %d \n",y);
	            ingresoB=1;
	            break;

	        case 3:
	            if(ingresoA&&ingresoB)
	            {
	                sumar(x,y,&suma);
	                restar(x,y,&resta);
	                multiplicar(x,y,&multiplicacion);
	                dividir(x,y,&division);
	            }
	            else
	            {
	                printf("Debe ingresar los 2 operandos antes de operar\n");
	                break;

	            }


	            if(x<0||y<0)
	            {
	                printf("Hubo un error. No se puede factorizar un numero negativo.");
	                break;

	            }
	            else
	            {
	                factorialx=factorizar(x);
	                factorialy=factorizar(y);

	            }


	            if(dividir(x,y,&division))
	            {
	                printf("Hubo un error. No se puede dividir por cero.");
	                break;
	            }
	            else
	            {
	                printf("Calculos realizados con exito.");
	                opero=1;
	            }




	            break;

	        case 4:

	            if(opero==1)
	            {
	                mostrarResultados(suma,resta,multiplicacion,division,factorialx,factorialy);

	            }
	            else
	            {
	                printf("Debe realizar las operaciones antes de poder mostrar los resultados\n");
	            }


	            break;




	        case 5:

	            printf("seguro que quiere salir? (s para si y n para no)\n");
	            fflush(stdin);
	            scanf("%c",&salir);

	            break;


	        default:
	            printf("opcion invalida!!!\n");
	            break;

	        }

	        system("pause");

	    }
	    while(salir == 'n');



	    return 0;
}
