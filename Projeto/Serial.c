#include <stdio.h>
#include <math.h>

long double fat(long double x){
	return (tgamma(x+1));
}

void taylor(long double n, long double *e){
	for (int i=0; i<=n;i++){
		*e += (1/fat(i));
	}
}

int main(){
	long double n = 10000000;
	long double e = 0.0;
	taylor(n, &e);
	printf("Valor de e encontrado = %.20Lf\n", e);
}

