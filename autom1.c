#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int typzn(char c){
	switch (c){
		case '0': return 0;
		case '1': return 1;
		default : return 2;
	}
}

int main(){
	char a,b,c;
	int i,j,k,s;
	int T[4][3]={{0,1,3}, {2,0,3}, {1,2,3}, {3,3,3}};
	do {
	  s=0;
	  while((c=getchar())!='\n'){
		s = T[s][typzn(c)];
	  }
	  switch (s){
		case 0 : printf("Liczba podzielna przez 3\n");
		         break;
		case 1 :
		case 2 : printf("Liczba niepodzielna prze 3 (reszta %i)\n", s);
		         break;
		case 3 : printf("Blad w zapisie liczby binarnej\n");
	  }
	  printf("jeszcze raz? [t/n]");
	  b=getchar();
	  while (getchar()!='\n');
	} while (b!='n');
	


	system("pause");
}
