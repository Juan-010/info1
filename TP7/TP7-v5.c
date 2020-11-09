//TP7-5: Variando los Tipos de Problemas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int questionDisplayer(int n1, int n2, int choice){
	int answer;
	switch(choice){
        case 1:
            printf("¿Cuanto es %d + %d?\n", n1, n2);
	        scanf("%d", &answer);
	        return (answer == n1 + n2) ? 1 : 0;
        case 2:
            printf("¿Cuanto es %d - %d?\n", n1, n2);
	        scanf("%d", &answer);
	        return (answer == n1 - n2) ? 1 : 0;
        case 3:
            printf("¿Cuanto es %d * %d?\n", n1, n2);
	        scanf("%d", &answer);
	        return (answer == n1 * n2) ? 1 : 0;
        default:
            return 0;
    }
}

int modeMenu(void){
    int choice;
        printf("Menu de operaciones:\n");
        printf("1 - Suma\n");
        printf("2 - Resta\n");
        printf("3 - Multiplicacion\n");
        printf("4 - Mezcla de los 3\n");
    do{
        printf("Su eleccion: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 4)
            printf("Opcion inválida, intente nuevamente\n");
    }while(choice < 1 || choice > 4);
    return choice;
}

void questionHandler(int choice){
	int n1 = (rand() % 9) + 1, n2 = (rand() % 9) + 1, answer;
    if(choice == 4){
        choice = (rand() % 3) + 1;
    }
	do{
		answer = questionDisplayer(n1, n2, choice);
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
    int choice = modeMenu();    
    while(1)
		questionHandler(choice);
	return 0;
}
