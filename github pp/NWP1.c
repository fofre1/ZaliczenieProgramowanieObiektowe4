#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int NWP1(int m, int n){
   int c;
   if (m<n) { c=m; m=n; n=c; }
   while ((c=m-n) > 0){
   	  if(c>=n) { m=c; }
   	  else { m=n; n=c; }
   }
   return m;	
}

int NWP2(int m, int  n){
	int c;
	do{
		c=m%n;
		m=n;
		n=c;
	} while (n!=0);
	return m;
}



int main(){
	int m, n, d;
	do{
		printf("Podaj dodatnie m i n: ");
		scanf("%i", &m);
		scanf("%i", &n);
		if ((m>0)&&(n>0)){
			printf("NWP(%i,%i) = %i\n", m, n, d=NWP2(m,n));
			printf("NWW(%i,%i) = %i\n", m, n, m*n/d);
		}
		else { 
		    printf("Podales niewlasciwe dane\n");
		}
		printf("Czy powtorzyc? (0-nie, 1-tak): ");
		scanf("%i", &m);
	} while (m!=0);
	
	
	
	system("pause");
}
