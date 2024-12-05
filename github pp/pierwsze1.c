#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main(){
	int n, p, k, q, podz,b,i;
	int P[500000];
	printf("Ile liczb pierwszych znalezc?  (n<=500000)\n");
	scanf("%i", &n);
	if (n>500000) n=500000;
	P[0]=2; P[1]=3; k=2;
	p=5;
	while (k<n){
		q=P[0]; i=0;
		podz=0;
		b = (int)sqrt(p);
		while ((q<=b) && (podz==0)){
			if (p%q!=0) {i++; q=P[i];}
			else {podz=1;}
		}
	    if (podz==0) { 
		    P[k]=p;	
			k++;    
		}
		p+=2;
	}
	printf("Najwieksza znalezxiona l. pierwsza to %i\n", P[n-1] );
	system("pause");
}
