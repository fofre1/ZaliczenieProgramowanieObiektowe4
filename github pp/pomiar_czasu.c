#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

clock_t start, stop;

double oblicz_czas(clock_t a, clock_t b){
	return (double)(b-a)/CLOCKS_PER_SEC;
}

int sumapodzfast(int n){
	int s=1,pn,k;
	pn=(int)sqrt(n);
	if (pn*pn==n){
		s+=pn;
		pn--;
	}
	for (k=2; k<=pn; k++){
		if (n%k==0) s+=k+n/k;
	}
	return s;
}

int main(){
	int k,m,n,s1,l=0;
	printf("Podaj zakres m - n:\n");
	scanf("%i", &m); scanf("%i", &n);
	start=clock();
	printf("Liczby zaprzyjaznione w przedziale [%i,%i]\n", m,n);
	for (k=m; k<=n; k++){
		s1=sumapodzfast(k);
		if ((s1>k) && (k==sumapodzfast(s1))){
			printf("%i : %i\n", k, s1);
			l++;
		}
	}
	stop=clock();
    printf("Znaleziono %i par liczb zaprzyjaznionych\n", l);
    printf("Czas dzialania programu %.5lf\n", oblicz_czas(start, stop));
	
	system("pause");
}
