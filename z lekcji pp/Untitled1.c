#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float funkcja(float f){
	return (pow(f, 3)+pow(f, 2)-3*f+1);
}

int main(){
	float a, b, dokladnosc, f1, f2, c;
	do{
	printf("Podaj poczatowe wartosci a i b: ");
	scanf("%f" "%f", &a, &b);
	f1=funkcja(a);
	f2=funkcja(b);
	}while((f1*f2)>0);
	printf("Prosze podac z jaka doklasnoscia: ");
	scanf("%f" , &dokladnosc);
	while(1){
		c=(a+b)/2;
		if(funkcja(c)*funkcja(a)<0) b=c;
		else a=c;
		if(fabs(b-a)<dokladnosc) break;
	}
	printf("%f", (a+b)/2);
	
}
