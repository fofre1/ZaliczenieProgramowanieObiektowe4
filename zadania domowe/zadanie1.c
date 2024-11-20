#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float heron(float c, float e) {
    if(c==1 || c==0)
        {
            printf("Pierwiastek z liczby %f wynosi %f", c, c);
            return 0;
        }
        float d=1,x;
        while(1)
        {
            x=0.5*(d+c/d);
            if(fabs(x-d)<e) return x;
            d=x;
        }
}

int main() {
    float c, e, f;
    int positive_integer=0;
    while(positive_integer==0)
    {
        printf("Prosze podac dodatnia liczbe: ");
        scanf("%f", &c);
        if(c>=0) positive_integer=1;
    }
    printf("Prosze podac z jaka doklasnoscia: ");
    scanf("%f", &e);
    f=heron(c, e);
    printf("Pierwiastek z liczby %f wynosi %f", c, f);

}
