//TP 3: Encriptador de numeros
#include <stdio.h>

int main(void){
  int num, c1, c2, c3, c4, flag = 0;
  printf("Encriptador de numeros\n");
  do{
  printf("Ingrese un Numero de hasta 4 cifras: ");
  scanf("%d", &num); 
  if(num < 9999 && num >= 0)
    flag = 1;
  else
    printf("El numero ingresado no es válido. Intente nuevamente.\n\n");
    }while (flag == 0);  
 
  c1 = num;
  c2 = num;
  c3 = num;
  c4 = num;
  
  while(c1>=10)
    c1 -= 10;

  c2 -= c1;
  while(c2>=100)
    c2 -= 100;
  c2 /= 10;
  
  c3 -= (c1+c2*10);
  while(c3>=1000)
    c3-=1000;
  c3 /= 100;

  c4 -= (c1+c2*10+c3*100);
  c4 /= 1000;
 
  c1 = (c1 + 7) % 10;
  c2 = (c2 + 7) % 10;
  c3 = (c3 + 7) % 10;
  c4 = (c4 + 7) % 10;

  printf("Encriptacion exitosa\nSu numero es: %d\n", c2*1000+c1*100+c4*10+c3);
  return 0;
} 
