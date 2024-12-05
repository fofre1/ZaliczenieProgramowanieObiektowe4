#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(){
	char c,d,e;
	int k=0, x;
	do {
        printf("Podaj liczbe calkowita:\n");
        x=0;
        while (isdigit(c=getchar())) {      
        	x = x*10 + c-'0';
		}
		if (c!='\n') {
			printf("oczekiwano cyfry\n");
			while (getchar()!='\n')	;
		}
		else {
		   printf("wpisales liczbe %i\n", x);
	    }
		printf("jeszcze raz? (t/n) \n");
		d=getchar();
		while (getchar()!='\n')	;
	} while (d=='t');
	




	system("pause");
}
