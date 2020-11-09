//TP 3: Desencriptador de Numeros
#include <stdio.h>

int main(void){
  int num, c1, c2, c3, c4, flag = 0;
  do{
  printf("Ingrese un numero encriptado de hasta 4 cifras: ");
  scanf("%d", &num); 
  if(num < 9999 && num > 0)
    flag = 1;
  else
    printf("El numero ingresado no es valido. Intente nuevamente.\n\n");
  }while (flag == 0);  
  c1 = num;
  c2 = num;
  c3 = num;
  c4 = num;
  
  //Obtencion de la cifra 1
  while(c1>=10)
    c1 -= 10;

  //Obtencion de la cifra 2
  c2 -= c1;
  while(c2>=100)
    c2 -= 100;
  c2 /= 10;
  
  //Obtencion de la cifra 3
  c3 -= (c1+c2*10);
  while(c3>=1000)
    c3-=1000;
  c3 /= 100;

  //Obtencion de la cifra 4
  c4 -= (c1+c2*10+c3*100);
  c4 /= 1000;
 
  //Desencriptacion
  c1 -= 7;
  c2 -= 7;
  c3 -= 7;
  c4 -= 7;
  if(c1<0)
    c1 += 10; 
  if(c2<0)
    c2 += 10; 
  if(c3<0)
    c3 += 10; 
  if(c4<0)
    c4 += 10; 
  printf("Desencriptacion exitosa\nSu numero es: %d\n", c2*1000+c1*100+c4*10+c3);
  return 0;
} 
