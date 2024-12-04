#include <stdio.h>
#include <math.h>

int main() {
    long long int a, i;
    long double pi = 0.0; 
    printf("Podaj liczbę iteracji: ");
    scanf("%lld", &a);
    for (i = 0; i < a; i++) {
        pi += pow(-1, i)* (1.0 / (2 * i + 1));
        if(i%100000==0) printf("%.30LF\n", (4*pi));
    }
    pi *= 4;
    printf("Przybliżenie liczby pi po %lld iteracjach: %.30LF\n", a, pi);
    return 0;
}
