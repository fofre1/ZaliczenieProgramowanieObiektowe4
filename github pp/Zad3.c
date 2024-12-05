#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void uporzadkuj(int A[], int n ){
	int i,j, y;
	for (i=n-1; i>0; i--)
	   for (j=0; j<i; j++)
	      if (A[j]>A[j+1]){
	      	y=A[j]; A[j]=A[j+1]; A[j+1]=y;
		  }
}

int main(){
	int x, n, nd, xmin, xmax, k;
	float sr, od, s, med;
	int T[100];  //  T[0],... T[99]
	do {
	  printf("Podaj kolejne wartosci, 0 konczy dane.\n");
	  n=nd=0;
	  sr=od=0.0;
	  scanf("%i", &x);
	  xmax = xmin = x;
	  while (x!=0){
	  	T[n]=x;
		n++;
		if (x>0) nd++;
		sr+=(float)x;
		od+=(float)x*x;
		if (x<xmin) { xmin=x; }
		else { if (x>xmax) xmax=x; }
		scanf("%i", &x);
	  }
	  if (n>0){ 
	     printf("Wczytano %i liczb, w tym %i liczb dodatnich.\n", n, nd);
	     printf("Srednia arytmetyczna wynosi %.2f\n", s=sr/n);
	     printf("Odchylenie standardowe wynosi %.2f\n", sqrt(od/n-s*s));
	     printf("Najmniejsza i najwieksza z nich to %i oraz %i\n",xmin, xmax);
	     uporzadkuj(T,n);
	     for (k=0; k<n; k++) printf("%i, ", T[k]);
	     printf("\n");
//	     if (n%2==1){med =T[n/2];} else {med =(T[n/2]+T[n/2-1]);}
	     med = (n%2) ? T[n/2] : (T[n/2]+T[n/2-1])/2.0;
		 printf("Mediana wynosi %.1f\n", med);
      }
      printf("Jeszcze raz? (0-nie, 1-tak): ");
      scanf("%i", &x);
    } while (x!=0);
    
	system("pause");
}
