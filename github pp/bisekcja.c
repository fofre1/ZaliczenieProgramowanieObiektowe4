#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double F(double x){
//      return cos(x)-x; 
       return pow(x,5)-3*x+1;
}


int main(){
    double a,b,c,eps;
    int k=0;
    do { 
      printf("Podaj poczatkowe wartosci a i b: ");
      scanf("%lf  %lf", &a, &b);
      if (F(a)*F(b)>0){
            printf("Podales zle wartosci a i b\n");
      } else {k=1;}
    } while (k!=1);
    printf("Podaj dokladnosc rozwiazania ");
    scanf("%lf", &eps);  
    while (b-a > eps) {
       c=(a+b)/2;
       if (F(a)*F(c) < 0) {b=c;}
       else {a=c;}
    }
    c=(a+b)/2;
    printf("Pierwiastek x0 = %.15lf\n", c);
    printf("Sprawdzenie: F(x0) = %.15lf\n", F(c));
    system("pause");
    return 0;
}
