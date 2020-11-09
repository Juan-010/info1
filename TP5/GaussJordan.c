//TP5: Metodo de Gauss Jordan
#include <stdio.h>
#define N 100
#define M 100
#define ERR 0.001
	
int main(void){
	float mat[N][M];
	int nEq, nVar;
	do{
		printf("Ingrese la cantidad de ecuaciones de su sistema: ");
		scanf("%d",&nEq);
		printf("Ingrese la cantidad de variables de su sistema: ");
		scanf("%d",&nVar);
		if(nEq < 1 || nEq > 100 || nVar < 1 || nVar > 100)
			printf("Seleccion Invalida, intente nuevamente\n");
			
	} while(nEq < 1 || nEq > 100 || nVar < 1 || nVar > 100);
	
	for(int i = 0; i < nEq; i++){
		for(int j = 0; j <= nVar; j++){
			if (j == nVar)
				printf("Ingrese el termino independiente de la ecuacion %d: ", i+1);
			else
				printf("Ingrese el coeficiente de la variable %d de la ecuacion %d: ", j+1, i+1);
			scanf("%f",&mat[i][j]);
		}
	}
	
	//gaussJordan
	for(int i = 0; i < nEq; i++)
		for(int j = 0; j < nVar; j++){
		if (i == j)
		{
			float saveVar = mat[i][j];
			for(int k = 0; k <= nVar; k++)
				mat[i][k] /= saveVar;
				for(int k = 0; k < nEq; k++){
					if(k == i)
						continue;
					saveVar = -mat[k][j];
					for(int l = 0; l <= nVar; l++)
						mat[k][l] += mat[i][l] * saveVar;
				}
		}
	}
		
	printf("El vector solucion es:\n");
	float solucion[N];
	for(int i = 0; i < nEq; i++){
		if(mat[i][nEq] < ERR && mat[i][nEq] > -ERR)
			solucion[i] = 0;
		else
			solucion[i] = mat[i][nEq];
	}
	printf("<");
	for(int i = 0; i < nEq; i++)
		printf("%.2f ", solucion[i]);
	printf("\b>\n");
	return 0;
}
