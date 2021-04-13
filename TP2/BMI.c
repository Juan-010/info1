//TP2: Indice de Masa Corporal
#include <stdio.h>
int main(void)
{
  printf("Calculadora de Indice de Masa Corporal");
  printf("\n\nPresiona Enter para continuar...");
  getchar();

  int height;
  float weight, heightInM, bmi;

  printf("\nIngrese su altura en centimetros: ");
  scanf("%d", &height);
  printf("Ingrese su peso en kilogramos: ");
  scanf("%f", &weight);

  printf("\n\nCalculando...");
  heightInM = (float) height/100;
  bmi = weight/(heightInM*heightInM);

  printf("\n\n\nTu Indice de Masa Corporal es de: %.2f", bmi);

  printf("\n\nUtiliza la siguiente tabla para clasificar tu IMC");
  printf("\n\nInfrapeso: Menos de 18.5");
  printf("\nPeso Ideal: Entre 18.5 y 25");
  printf("\nSobrepeso: Entre 25 y 30");
  printf("\nObesidad: Mas de 30\n");
    
  return 0;
}
