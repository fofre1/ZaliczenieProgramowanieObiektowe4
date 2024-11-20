#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float heron(float c, float e, int poziom) {
    if(c==1 || c==0)
        {
            printf("Pierwiastek z liczby %f wynosi %f", c, c);
            return 0;
        }
        float d=1,x;
        while(1)
        {
            x=((poziom-1)*d+c/pow(d, poziom-1))/poziom;
            if(fabs(x-d)<e) return x;
            d=x;
        }
}

int main() {
    float c, e, f;
    int poziom;
    int positive_integer=0;
    while(positive_integer==0)
    {
        printf("Prosze podac dodatnia liczbe: ");
        scanf("%f", &c);
        if(c>=0) positive_integer=1;
    }
    printf("Prosze podac z jaka doklasnoscia: ");
    scanf("%f", &e);
    printf("Prosze podac ktorego stopnia ma byc pierwiastek: ");
    scanf("%i", &poziom);
    f=heron(c, e, poziom);
    printf("Pierwiastek z liczby %f wynosi %f", c, f);

}
