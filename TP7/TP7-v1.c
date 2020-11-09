//TP7-1: Instruccion Asistida por Computadora
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int questionDisplayer(int n1, int n2){
	printf("¿Cuanto es %d * %d?\n", n1, n2);
	int answer;
	scanf("%d", &answer);
	return (answer == n1 * n2) ? 1 : 0;
}

void questionHandler(void){
	int n1 = (rand() % 9) + 1, n2 = (rand() % 9) + 1, answer;
	do{
		answer = questionDisplayer(n1, n2);
		if(answer == 1)
			printf("¡Muy Bien!\n");
		else
			printf("No. Inténtelo de nuevo\n");
	}while(answer == 0);	
}

int main(void){
	srand(time(NULL));
    printf("Bienvenido al sistema de Aprendizaje en Matemática!\n");
    printf("Para salir, presione \"Ctrl + C\" en cualquier momento\n");
	while(1)
		questionHandler();
	return 0;
}
