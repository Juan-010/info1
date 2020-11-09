//TP7-3: Monitoreo del Desempeño Estudiantil
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int questionDisplayer(int n1, int n2){
	printf("¿Cuanto es %d * %d?\n", n1, n2);
	int answer;
	scanf("%d", &answer);
	return (answer == n1 * n2) ? 1 : 0;
}

int questionHandler(void){
	int n1 = (rand() % 9) + 1, n2 = (rand() % 9) + 1, answer;
	answer = questionDisplayer(n1, n2);
	if(answer == 1)
		printf("¡Muy Bien!\n");
	else
		printf("No. Inténtelo de nuevo\n");
	return answer;
}

int main(void){
	int count = 0;
	srand(time(NULL));	
    printf("Bienvenido al sistema de Aprendizaje en Matemática!\n");
    printf("Usted será evaluado con 10 ejercicios de multiplicación\n");
	for(int i = 0; i < 10; i++)
		if(questionHandler())
			count++;
	int percent = count * 100 / 10;
	printf("Su puntuacion es de %d%%.\n", percent);
	if(percent >= 75)
		printf("¡Felicitaciones, está listo para pasar al siguiente nivel!\n");
	else
		printf("Pídale ayuda adicional a su maestro\n");
	return 0;
}
