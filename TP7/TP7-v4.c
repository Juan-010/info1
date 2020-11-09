//TP7-4: Niveles de Dificultad
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long unsigned int power(int num, int exp){
    if(exp < 1)
        return 1;
    int result = num;
    for(int i = 1; i < exp; i++)
        result *= num;
    return result;
}
    

int questionDisplayer(unsigned int n1,unsigned int n2){
	printf("¿Cuanto es %u * %u?\n", n1, n2);
	unsigned long long int answer;
	scanf("%llu", &answer);
	return (answer == (unsigned long long int) n1 * n2) ? 1 : 0;
}

int difficultySelector(void){
    printf("Seleccione un nivel de dificultad (1-5): ");
    int level;
    do{
        scanf("%d", &level);
        if(level < 1 || level > 5)
            printf("Seleccion inválida, los niveles existen en el rango (1-5).\n");
    }while(level < 1 || level > 5);    
    return level;
}

void questionHandler(int level){
	unsigned int n1 = (rand() % (power(10, level) - power(10, level - 1))) + power(10, level - 1); 
	unsigned int n2 = (rand() % (power(10, level) - power(10, level - 1))) + power(10, level - 1); 
    int answer;
	do{
		answer = questionDisplayer(n1, n2);
		if(answer)
			printf("¡Muy Bien!\n");
		else
			printf("No. Inténtelo de nuevo\n");
	}while(!answer);	
}

int main(void){
	srand(time(NULL));
    printf("Bienvenido al sistema de Aprendizaje en Matemática!\n");
    printf("Para salir, presione \"Ctrl + C\" en cualquier momento\n");    
    int diff = difficultySelector();
    while(1)
		questionHandler(diff);
	return 0;
}
