//TP 4: Calculo de Pago Semanal
#include <stdio.h>
int main(void)
{//funcion main
	int salir = 0;
	printf("Calculadora de Pago Semanal\n\n");
	do{
		printf("Ingrese el código de empleado:\n");
		printf("1 - Gerentes\n");
		printf("2 - Trabajadores por Hora\n");
		printf("3 - Trabajadores de Comisión\n");
		printf("4 - Trabajadores a Destajo\n");
		printf("0 - Salir\n");
	
		int choice;
		do
		{//Verificacion de respuesta
			printf("Su codigo: ");
			scanf("%d", &choice);
			if(!(choice >= 0 && choice <= 4))
				printf("Codigo inválido, intente nuevamente\n");
		} while(!(choice >= 0 && choice <= 4));
	
		float wage, sales;
		int hours, artProduced;
		switch(choice)
		{//Declaracion del Menu
			case 1:
				//Salario Semanal Fijo
				wage = 1500;
				break;
			case 2:
				// 150 por Hora 40 horas, despues x1.5
				do{
				printf("Inserte la cantidad de horas trabajadas: ");
				scanf("%d", &hours);
				printf("%s", (hours < 0) ? "Dato inválido, ingrese nuevamente\n" : "");
				}while(hours < 0);

				if(hours <= 40)
					wage = hours * 150;
				else
					wage = 40 * 150 + (hours - 40) * 150 * 1.5;
				break;
			case 3:
				//250 + 5.7% de sus ventas totales
				do{
				printf("Inserte las ventas producidas: ");
				scanf("%f", &sales);
				printf("%s", (sales < 0) ? "Dato inválido, ingrese nuevamente\n" : "");
				}while(sales < 0);
				
				wage = 250 + sales * 0.057;
				break;
			case 4:
				//Cantidad fija (300) por articulo producido
				do{
				printf("Inserte la cantidad de artículos producidos: ");
				scanf("%d", &artProduced);
				printf("%s", (artProduced < 0) ? "Dato inválido, ingrese nuevamente\n" : "");
				}while(artProduced < 0);
				
				wage = 300 + artProduced * 300;
				break;
			case 0:
				salir = 1;
				break;
		}

		if(salir != 1) 
			printf("Su pago semanal es de %.2f\n\n", wage);

	}while(salir != 1);
	return 0;
}
