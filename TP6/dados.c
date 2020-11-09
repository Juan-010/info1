//TP6: Lanzamiento de Dados
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	//Setup del Seed de la funcion random
	srand(time(NULL));

	int comb[11] = {0};
	for(int i = 0; i < 36000; i++){
		int dado1 = (rand() % 6) + 1;
		int dado2 = (rand() % 6) + 1;
		comb[dado1 + dado2 - 2]++;
	}
	
	int mayor = 2, menor = 2;
	printf("Comb.    Frec.    Porc.\n");
	for(int i = 0; i < 11; i++){
		printf(" %2d      %4d     %.2f%%\n", i+2, comb[i], comb[i]*100/36000.0);
		if(comb[i] < comb[menor])
			menor = i;
		else if(comb[i] > comb[mayor])
			mayor = i;
	}
	printf("La Combinacion mas frecuente es %d, con una cuenta total de %d y un porcentaje de %.2f%%\n", mayor + 2, comb[mayor], comb[mayor]*100/36000.0); 	
	printf("La Combinacion menos frecuente es %d, con una cuenta total de %d y un porcentaje de %.2f%%\n", menor + 2, comb[menor], comb[menor]*100/36000.0); 	
	return 0;
}
