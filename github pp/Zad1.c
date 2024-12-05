#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int x, suma;
	do {
	  printf("Podaj kolejne wartosci, 0 konczy dane.\n");
	  suma=0;
/*	  scanf("%i", &x);
	  while (x!=0){
		suma=suma+x;   // suma+=x;
		scanf("%i", &x);
	  }
*/
      do{
      	scanf("%i", &x);
      	suma+=x;
	  } while(x!=0);
	  
	  printf("Suma wczytanych wartosci wynosi %i\n", suma);
      printf("Jeszcze raz? (0-nie, 1-tak): ");
      scanf("%i", &x);
    } while (x!=0);
    
	system("pause");
}
