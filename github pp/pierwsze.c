#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int n, p, k=1, q, podz;
	printf("Ile liczb pierwszych znalezc?");
	scanf("%i", &n);
	p=3;
	printf("2\n");
	while (k<=n){
		q=2;
		podz=0;
		while ((q<=(int)sqrt(p)) && (podz==0)){
			if (p%q!=0) {q++;}
			else {podz=1;}
		}
	    if (podz==0) {
//		    printf("%i\n", p);
		    k++;	    
		}
		p+=2;
	}
	printf("Najwieksza znaleziona to %i\n", p-2);
	system("pause");
}
