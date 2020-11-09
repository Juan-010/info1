//TP7-2: Reducir la Fatiga del Estudiante
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int questionDisplayer(int n1, int n2){
	printf("¿Cuanto es %d * %d?\n", n1, n2);
	int answer;
	scanf("%d", &answer);
	return (answer == n1 * n2) ? 1 : 0;
}

void messageGenerator(int right){
	char goodMessages[][80] = {"¡Muy Bien!", "¡Excelente!", "¡Buen Trabajo!", "¡Sigue con el buen trabajo!"}; 
	char badMessages[][80] = {"No. Por favor inténtelo de nuevo.", "Incorrecto. Intentar una vez más.", "¡No te rindas!", "No. Sigue intentándolo."};
	
	int randMessage = rand() % 4;
	if(right)
		switch(randMessage){
			case 0:
				printf("%s\n", goodMessages[0]);
				break;
			case 1:
				printf("%s\n", goodMessages[1]);
				break;
			case 2:
				printf("%s\n", goodMessages[2]);
				break;
			case 3:
				printf("%s\n", goodMessages[3]);
				break;
			}
	else if(!right)
		switch(randMessage){
			case 0:
				printf("%s\n", badMessages[0]);
				break;
			case 1:
				printf("%s\n", badMessages[1]);
				break;
			case 2:
				printf("%s\n", badMessages[2]);
				break;
			case 3:
				printf("%s\n", badMessages[3]);
				break;
			}
}

void questionHandler(void){
	int n1 = (rand() % 9) + 1, n2 = (rand() % 9) + 1, answer;
	do{
		answer = questionDisplayer(n1, n2);
		messageGenerator(answer);
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
