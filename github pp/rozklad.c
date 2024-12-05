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
	printf("Podaj liczbe do rozkladu na czynniki pierwsze: ");
	scanf("%i", &p);
	printf("%i = ", p);
	i=0;
	while(p>1){
		if (p%P[i]==0){ 
		    p=p/P[i]; 
		    printf("%i", P[i]);
		    if (p>1) printf("*");
		}
		else { i++;	}
		
	}
	printf("\n");
	system("pause");
}
