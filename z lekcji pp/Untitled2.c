#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sumapodzielnikow(int n){
	int suma=1, i, p;
	p=(int)sqrt(n);
	if(p*p==n)
	{
	suma+=p;
	p--;
	}
	for(i=2; i<=p; i++)
	{
		if(n%i==0) 
		{
		suma+=i;
		}
	}
	return suma;

}

int main(){
	int b, a, k;
	printf("Prosze podac przedzial: ");
    scanf("%i" "%i", &a, &b);
	for(k=a; k<=b; k++)
	{
		if(k==sumapodzielnikow(k)) printf("Liczba %i jest liczba doskonala\n", k);
	}
}
