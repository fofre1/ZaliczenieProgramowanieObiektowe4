#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int typzn(char c){
	if (isdigit(c)) return 0;
	switch (c){
		case '+': return 1;
		case '-': return 2;
		case '.': return 3;
		case 'e': return 4;
		default : return 5;
	}
}

int main(){
	char a,b,c;
	int i,j,k,s,ex,ze;
	double x,y, w, z;
	int T[11][6]={{3,1,2,4,10,10}, {3,10,10,4,10,10}, {3,10,10,4,10,10}, {3,10,10,4,6,10}, 
	{5,10,10,10,6,10}, {5,10,10,10,6,10}, {9,7,8,10,10,10}, {9,10,10,10,10,10},
	{9,10,10,10,10,10}, {9,10,10,10,10,10},  {10,10,10,10,10,10}};
	
	do {
	  s=0;
	  x=y=0.0;
	  z=1.0;
	  k=1;
	  ze=1; ex=0;
	  while((c=getchar())!='\n'){
		s = T[s][typzn(c)];
		switch (s){
			case 1: break;
			case 2: z=-1.0;
			        break;
			case 3: x=x*10.0+c-'0';
			case 4: break;
			case 5: y=y*10.0+c-'0';
			        k=k*10;
			case 6:;
			case 7: break;
			case 8: ze=-1;
			        break;
			case 9: ex=ex*10+c-'0';
			case 10:;
		}
	  }
	  switch (s){
		case 3 :
		case 4 :
		case 5 : 
		case 9 : w = z*(x+y/k)*pow(10,ze*ex);
		         printf("wynik: %f\n", w);
		         break;
		case 1 :
		case 2 : 
		case 6 :
		case 7 :
		case 8:
		case 10 : printf("blad w zapisie liczby\n");
	  }
	  printf("jeszcze raz? [t/n]");
	  b=getchar();
	  while (getchar()!='\n');
	} while (b!='n');
	


	system("pause");
}
