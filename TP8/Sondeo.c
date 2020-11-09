//TP8: Sondeo
#include <stdio.h>
void instrucciones(void){
	puts("Este cuestionario trata sobre problematicas globales");
	puts("con las cuales nuestra vida se ve afectada");
	puts("Usted debera responder en una escala del 1 al 10");
	puts("que tan importantes les parecen estas problematicas");
}

void cuestionario(int * const respuesta, char *tema){
	int tmp;
	do{
		printf("\nCual es la importancia para Ud. acerca de: %s\n", tema);
		printf("Su respuesta: ");
		scanf("%d", &tmp);
		if(tmp < 1 || tmp > 10)
			puts("El puntaje debe estar entre 1 y 10");
	} while(tmp < 1 || tmp > 10);
	tmp--;
	*(respuesta + tmp)+= 1;
}

int menu(void){
	int choice;
	do{
		puts("\nMenu\n");
		puts("1 - Acerca del Programa");
		puts("2 - Iniciar Cuestionario");
		puts("3 - Generar Informe");
		puts("4 - Salir");
		printf("\nSu eleccion: ");
		scanf("%d", &choice);
		if(choice < 1 || choice > 4)
			puts("Opcion invalida. Intente nuevamente.");
	} while(choice < 1 || choice > 4);
	return choice;
}

void informe(int respuesta[5][10], char *causas[5], int times_run){
	//checkea si el cuestionario corrio alguna vez
	if(!times_run){
		puts("Debes completar el cuestionario al menos una vez");
		return;
	}

	int mayor = -1, menor = -1;
	int puntos_mayor = 0, puntos_menor = 0;

	//Header
	printf("\n%-30s\t", "Puntaje");
	for (int i = 1; i <= 10; i++)
		printf("%5d ", i);
	printf("%10s\n\n", "Promedio");

	for (int i = 0; i < 5; i++){
		//Declaracion de variables para promedio
		int count = 0, total = 0;
		//Causas y Respuestas
		printf("%-30s\t", causas[i]);
		for (int j = 0; j < 10; j++){
			printf("%5d ", respuesta[i][j]);

			total += respuesta[i][j] * (j + 1);
			if(respuesta[i][j] != 0)
				count += respuesta[i][j];
		}

		printf("%7.2f", total != 0 ? (float) total/count : 0);

		if (total > puntos_mayor || mayor == -1){
			mayor = i;
			puntos_mayor = total;
		}

		if (total < puntos_menor || menor == -1){
			menor = i;
			puntos_menor = total;
		}
		printf("\n");
	}
	printf("\nMayor puntaje: %s con %d puntos\n", causas[mayor], puntos_mayor);
	printf("Menor puntaje: %s con %d puntos\n\n", causas[menor], puntos_menor);
}

int main(void){
	char *temas[5] = {"Corrupcion", "Calentamiento Global", "Desarrollo de la Tecnologia", "Educacion", "Racismo"};
	int respuestas[5][10] = {{0}};
	int repetir = 1, veces_corrido = 0;
	instrucciones();
	do{
		int eleccion = menu();
		switch (eleccion){
		case 1:
			instrucciones();
			break;
		case 2:
			for (int i = 0; i < 5; i++)
				cuestionario(respuestas[i], temas[i]);
			veces_corrido++;
			break;
		case 3:
			informe(respuestas, temas, veces_corrido);
			break;
		case 4:
			repetir = 0;
			break;
		}
	} while(repetir);
	return 0;
}
