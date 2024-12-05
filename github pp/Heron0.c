#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a,x;
    int k,n;
do{
    printf("Podaj liczbe do pierwiastkowania (>0)\n");
    scanf("%lf",&a);
    printf("Podaj liczbe krokow\n");
    scanf("%i",&n);
    x=1.0;
    for (k=1; k<=n; k++){
      x=1.0/3.0*(2.0*x+a/(x*x));
      printf("%i: %.10lf\n", k, x);
    }
    printf("Przyblizenie pierwiastka z %lf: %lf\n", a, x);
    printf("Jeszcze raz? (0/1): ");
    scanf("%i", &k);
} while (k!=0);
               
system("pause");
}
